#include "DataSampler.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include "llvm/Support/ErrorHandling.h"

namespace Evaluation {

DataSampler::DataSampler(const EvaluationParameter& evaluationParameter, const EvaluationBatch& evaluationBatch):
    dataCachePath(evaluationParameter.getDataCachePath()),
    domain(evaluationParameter.getDomain()),
    concreteDomainLength(evaluationParameter.getConcreteDomainLength()),
    abstractDomainLength(evaluationParameter.getAbstractDomainLength()),
    abstractDomainConstraint(evaluationBatch.getAbstractDomainConstraint()),
    instanceConstraint(evaluationBatch.getInstanceConstraint()){

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

void DataSampler::saveData(const std::filesystem::path& path, std::vector<AbstractConcreteValuePair>& data, size_t bitWidth) const {
    std::ofstream fout(path, std::ios::binary);

    size_t count=data.size();
    assert (count>0);
    fout.write((char*)&count, sizeof(size_t));

    size_t concreteValueLength = data[0].getConcreteValues().size();
    fout.write((char*)&concreteValueLength, sizeof(size_t));
    assert(concreteValueLength>0);

    uint64_t tmp;
    for (const auto& abstractValuePair : data) {
        for (const auto& apInt: abstractValuePair.getAbstractValue()) {
            tmp = apInt.getZExtValue();
            fout.write((char*)&tmp, sizeof(uint64_t));
        }
        for (const auto& concreteValue: abstractValuePair.getConcreteValues()) {
            tmp=concreteValue.getZExtValue();
            fout.write((char*)&tmp, sizeof(uint64_t));
        }
    }
}

std::vector<AbstractConcreteValuePair> DataSampler::loadData(const std::filesystem::path& path, size_t bitWidth)const {
    std::ifstream fin(path, std::ios::binary);

    size_t count, concreteValueLength;
    fin.read((char*)&count, sizeof(size_t));
    fin.read((char*)&concreteValueLength, sizeof(size_t));
    assert(count>0);
    assert(concreteValueLength>0);

    uint64_t tmp;
    APInt tmpAPInt(bitWidth, 0);
    AbstractValue tmpAbstractValue;
    std::vector<ConcreteValue> tmpConcreteValues;

    std::vector<AbstractConcreteValuePair> result;
    result.reserve(count);
    for (size_t i=0;i<count;i++) {
        for (size_t j=0;j<abstractDomainLength;++j) {
            fin.read((char*)&tmp, sizeof(uint64_t));
            tmpAbstractValue.emplace_back(bitWidth, tmp);
        }
        for (size_t j=0;j<concreteValueLength;++j) {
            fin.read((char*)&tmp, sizeof(uint64_t));
            tmpConcreteValues.emplace_back(bitWidth, tmp);
        }
        result.emplace_back(tmpAbstractValue, tmpConcreteValues);
        tmpAbstractValue.clear();
        tmpConcreteValues.clear();
    }

    return result;
}


AbstractValue DataSampler::initAbstractValue(size_t bitWidth)const {
    return AbstractValue(abstractDomainLength, APInt(bitWidth, 0));
}

bool DataSampler::nextAbstractValue(AbstractValue& abstractValue)const {
    for (size_t i=0;i<abstractDomainLength;++i) {
        if (!abstractValue[i].isMaxValue()) {
            abstractValue[i]+=1;
            for (size_t j=0;j<i;++j) {
                abstractValue[j]=0;
            }
            return true;
        }
    }
    return false;
}

std::vector<ConcreteValue> DataSampler::sampleConcreteValues(AbstractValue& abstractValue, size_t bitWidth)const {
    std::vector<ConcreteValue> result;
    APInt upperBound=APInt::getAllOnes(bitWidth);
    for (APInt value(bitWidth, 0);value!=upperBound;value+=1) {
        if (instanceConstraint(abstractValue.data(), &value)) {
            result.push_back(value);
        }
    }
    if (instanceConstraint(abstractValue.data(), &upperBound)) {
        result.push_back(upperBound);
    }
    return result;
}

std::vector<AbstractConcreteValuePair> DataSampler::sampleData(size_t bitWidth)const {
    auto sampleParameterIt = bitWidthToSampleParameter.find(bitWidth);
    assert(sampleParameterIt!=bitWidthToSampleParameter.end());
    const SampleParameter& sampleParameter = sampleParameterIt->second;
    std::vector<AbstractConcreteValuePair> result;
    if (sampleParameter.getSamplePolicy() == SamplePolicy::FULL_ENUMERATION) {
        AbstractValue abstractValue = initAbstractValue(bitWidth);
        do {
            if (abstractDomainConstraint(abstractValue.data())) {
                std::vector<ConcreteValue> concreteValues=sampleConcreteValues(abstractValue, bitWidth);
                result.emplace_back(abstractValue, concreteValues);
            }
        }while (nextAbstractValue(abstractValue));
        return result;
    }else if (sampleParameter.getSamplePolicy() == SamplePolicy::SAMPLE_CONCRETE) {
        assert(false && "Not support yet");
    }else if (sampleParameter.getSamplePolicy() == SamplePolicy::SAMPLE_ABSTRACT_AND_CONCRETE) {
        assert(false && "Not support yet");
    }

    llvm_unreachable("Unhandled error in sampling data");
}

std::vector<AbstractConcreteValuePair> DataSampler::getData(size_t bitWidth) {
    using namespace std::filesystem;
    path dataFilePath = getDataFilePath(bitWidth);
    if (exists(dataFilePath) && is_regular_file(dataFilePath)) {
        return loadData(dataFilePath, bitWidth);
    }else {
        auto result=sampleData(bitWidth);
        saveData(dataFilePath, result, bitWidth);
        return result;
    }
}
}

