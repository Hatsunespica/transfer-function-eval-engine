#include "DataSampler.h"
#include "llvm/Support/ErrorHandling.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <charconv>

namespace Evaluation {

    DataSampler::DataSampler(const EvaluationParameter &evaluationParameter,
                             const EvaluationBatch &evaluationBatch)
            : dataCachePath(evaluationParameter.getDataCachePath()),
              maxOperationLength(evaluationParameter.getMaxOperationLength()),
              domain(evaluationParameter.getDomain()),
              concreteDomainLength(evaluationParameter.getConcreteDomainLength()),
              abstractDomainLength(evaluationParameter.getAbstractDomainLength()),
              abstractDomainConstraint(evaluationBatch.getAbstractDomainConstraint()),
              instanceConstraint(evaluationBatch.getInstanceConstraint()),
              bitWidthToSampleParameter(
                      evaluationParameter.getBitWidthToSampleParameter()) {

        using namespace std::filesystem;
        assert(exists(dataCachePath) && is_directory(dataCachePath));
    };

    std::filesystem::path DataSampler::getDataPath(size_t bitWidth) const {
        auto newPath = dataCachePath / domain / std::to_string(bitWidth);
        if (!exists(newPath)) {
            create_directories(newPath);
        }
        assert(is_directory(newPath));
        return newPath;
    }

    std::filesystem::path DataSampler::getDataFilePath(size_t bitWidth) const {
        return getDataPath(bitWidth) / DATA_FILE_NAME;
    }

    bool SampleParameter::matchSampleParameter(
            const std::filesystem::path &path, const SampleParameter &sampleParameter) {
        std::fstream fin(path, std::ios::binary | std::ios::in);
        return sampleParameter == SampleParameter::loadFromFile(fin);
    }

    void DataSampler::saveData(const std::filesystem::path &path,
                               std::vector<AbstractConcreteValuePair> &data,
                               size_t bitWidth) const {
        std::fstream fout(path, std::ios::binary | std::ios::out | std::ios::trunc);

        (bitWidthToSampleParameter.find(bitWidth)->second).saveToFile(fout);

        size_t count = data.size();
        assert(count > 0);
        fout.write((char *) &count, sizeof(size_t));

        uint64_t tmp;
        for (const auto &abstractValuePair: data) {
            for (const auto &apInt: abstractValuePair.getAbstractValue()) {
                tmp = apInt.getZExtValue();
                fout.write((char *) &tmp, sizeof(uint64_t));
            }

            size_t concreteValueLength = abstractValuePair.getConcreteValues().size();
            assert(concreteValueLength > 0);
            fout.write((char *) &concreteValueLength, sizeof(size_t));

            for (const auto &concreteValue: abstractValuePair.getConcreteValues()) {
                tmp = concreteValue.getZExtValue();
                fout.write((char *) &tmp, sizeof(uint64_t));
            }
        }
    }

    std::vector<AbstractConcreteValuePair>
    DataSampler::loadData(const std::filesystem::path &path,
                          size_t bitWidth) const {
        std::fstream fin(path, std::ios::binary | std::ios::in);

        auto sampleParameter = SampleParameter::loadFromFile(fin);
        assert(sampleParameter == bitWidthToSampleParameter.find(bitWidth)->second);

        size_t count, concreteValueLength;
        fin.read((char *) &count, sizeof(size_t));
        assert(count > 0);

        uint64_t tmp;
        APInt tmpAPInt(bitWidth, 0);
        AbstractValue tmpAbstractValue;
        std::vector<ConcreteValue> tmpConcreteValues;

        std::vector<AbstractConcreteValuePair> result;
        result.reserve(count);
        for (size_t i = 0; i < count; i++) {
            for (size_t j = 0; j < abstractDomainLength; ++j) {
                fin.read((char *) &tmp, sizeof(uint64_t));
                tmpAbstractValue.emplace_back(bitWidth, tmp);
            }
            fin.read((char *) &concreteValueLength, sizeof(size_t));
            assert(concreteValueLength > 0);
            for (size_t j = 0; j < concreteValueLength; ++j) {
                fin.read((char *) &tmp, sizeof(uint64_t));
                tmpConcreteValues.emplace_back(bitWidth, tmp);
            }
            result.emplace_back(tmpAbstractValue, tmpConcreteValues);
            tmpAbstractValue.clear();
            tmpConcreteValues.clear();
        }

        return result;
    }

    AbstractValue DataSampler::initAbstractValue(size_t bitWidth) const {
        return AbstractValue(abstractDomainLength, APInt(bitWidth, 0));
    }

    bool DataSampler::nextAbstractValue(AbstractValue &abstractValue) const {
        for (size_t i = 0; i < abstractDomainLength; ++i) {
            if (!abstractValue[i].isMaxValue()) {
                abstractValue[i] += 1;
                for (size_t j = 0; j < i; ++j) {
                    abstractValue[j] = 0;
                }
                return true;
            }
        }
        return false;
    }

    std::vector<ConcreteValue>
    DataSampler::sampleConcreteValues(AbstractValue &abstractValue,
                                      size_t bitWidth) const {
        std::vector<ConcreteValue> result;
        APInt upperBound = APInt::getAllOnes(bitWidth);
        int isValidInstance;
        for (APInt value(bitWidth, 0); value != upperBound; value += 1) {
            instanceConstraint(abstractValue.data(), &value, &isValidInstance);
            if (isValidInstance) {
                result.push_back(value);
            }
        }
        instanceConstraint(abstractValue.data(), &upperBound, &isValidInstance);
        if (isValidInstance) {
            result.push_back(upperBound);
        }
        return result;
    }

    std::vector<AbstractConcreteValuePair>
    DataSampler::sampleData(size_t bitWidth) const {
        auto sampleParameterIt = bitWidthToSampleParameter.find(bitWidth);
        assert(sampleParameterIt != bitWidthToSampleParameter.end());
        const SampleParameter &sampleParameter = sampleParameterIt->second;
        std::vector<AbstractConcreteValuePair> result;
        std::vector<ConcreteValue> tmpValues(maxOperationLength);
        int isValidAbstractDomain;
        if (sampleParameter.getSamplePolicy() == SamplePolicy::FULL_ENUMERATION) {
            AbstractValue abstractValue = initAbstractValue(bitWidth);
            do {
                abstractDomainConstraint(abstractValue.data(), &isValidAbstractDomain);
                if (isValidAbstractDomain) {
                    std::vector<ConcreteValue> concreteValues =
                            sampleConcreteValues(abstractValue, bitWidth);
                    if (concreteValues.empty()) {
                        abstractValue[0].dump();
                        abstractValue[1].dump();
                        llvm::errs() << "Find abstract value without any concrete value\n";
                        exit(0);
                    }
                    result.emplace_back(abstractValue, concreteValues);
                }
            } while (nextAbstractValue(abstractValue));
            return result;
        } else if (sampleParameter.getSamplePolicy() ==
                   SamplePolicy::SAMPLE_CONCRETE) {
            assert(false && "Not support yet");
        } else if (sampleParameter.getSamplePolicy() ==
                   SamplePolicy::SAMPLE_ABSTRACT_AND_CONCRETE) {
            assert(false && "Not support yet");
        }

        llvm_unreachable("Unhandled error in sampling data");
    }

    std::vector<AbstractConcreteValuePair> DataSampler::getData(size_t bitWidth) {
        using namespace std::filesystem;
        path dataFilePath = getDataFilePath(bitWidth);

        if (exists(dataFilePath) && is_regular_file(dataFilePath) &&
            SampleParameter::matchSampleParameter(
                    dataFilePath, bitWidthToSampleParameter.find(bitWidth)->second)) {
            return loadData(dataFilePath, bitWidth);
        } else {
            auto result = sampleData(bitWidth);
            saveData(dataFilePath, result, bitWidth);
            return result;
        }
    }

    AbstractValue ExternalDataLoader::parseKnownBits(std::string_view str) {
        size_t bitWidth = str.size();
        AbstractValue result(2, APInt(bitWidth, 0));
        for (size_t i = 0, loc = bitWidth - 1; i < bitWidth; ++i, --loc) {
            if (str[i] == '0') {
                result[0].setBit(loc);
            } else if (str[i] == '1') {
                result[1].setBit(loc);
            } else if (str[i] != '?') {
                assert(false && "Wrong data");
            }
        }
        return result;
    }


    std::vector<std::string_view> ExternalDataLoader::splitOneLine(std::string_view str) {
        std::vector<std::string_view> result;

        size_t start = 0;
        while (start <= str.size()) {
            size_t end = str.find('\t', start);

            if (end == std::string_view::npos) {
                result.emplace_back(str.substr(start));
                break;
            }

            result.emplace_back(str.substr(start, end - start));
            start = end + 1;
        }

        return result;
    }

    ExternalDataSet ExternalDataLoader::loadFromExternalData() {
        std::ifstream fin(dataPath);
        std::string line;
        ExternalDataSet dataSet;

        // Skip header info
        int skipHeader = 0;
        const static std::string HEADER = "# ---";
        while (std::getline(fin, line)) {
            if (line == HEADER) {
                ++skipHeader;
            }
            if (skipHeader == 2) {
                break;
            }
        }

        std::getline(fin, line);

        std::vector<AbstractValue> abstractValues;
        //parse each line
        while (std::getline(fin, line)) {
            auto splitResult = splitOneLine(line);
            assert(arity + 2 == splitResult.size());
            //parse the first bit width
            size_t bitWidth;
            auto result = std::from_chars(splitResult[0].data(), splitResult[0].data() + splitResult[0].size(),
                                          bitWidth);
            assert(result.ec != std::errc::invalid_argument);

            //parse rest and add to result
            if (dataSet.find(bitWidth) == dataSet.end()) {
                dataSet.emplace(bitWidth, std::vector<std::vector<AbstractValue>>());
            }
            for (int i = 1; i < splitResult.size(); ++i) {
                abstractValues.push_back(parseAbstractValue(splitResult[i]));
            }
            dataSet[bitWidth].push_back(abstractValues);
            abstractValues.clear();
        }
        return dataSet;
    }

    ExternalDataLoader::ExternalDataLoader(const EvaluationParameter &evaluationParameter) :
            dataPath(evaluationParameter.getExternalDataPath()),
            domain(evaluationParameter.getDomain()),
            arity(evaluationParameter.getTransferFunctionArity()) {
        using namespace std::filesystem;
        assert(exists(dataPath) && is_regular_file(dataPath));
        if (domain == "KnownBits") {
            parseAbstractValue = parseKnownBits;
        } else {
            assert(false && "Doesn't support for loading from the given domain: ");
        }

    }
} // namespace Evaluation
