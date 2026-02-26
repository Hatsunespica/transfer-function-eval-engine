#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H

#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

namespace Evaluation {

    enum SamplePolicy {
        FULL_ENUMERATION,
        SAMPLE_CONCRETE,
        SAMPLE_ABSTRACT_AND_CONCRETE
    };

    class SampleParameter {
        SamplePolicy samplePolicy;
        size_t randomSeed;
        size_t numConcreteSamples;
        size_t numAbstractSamples;

    public:
        explicit SampleParameter(SamplePolicy samplePolicy, size_t randomSeed = 0,
                                 size_t numConcreteSamples = 0,
                                 size_t numAbstractSamples = 0)
                : samplePolicy(samplePolicy), randomSeed(randomSeed),
                  numConcreteSamples(numConcreteSamples),
                  numAbstractSamples(numAbstractSamples) {}

        const SamplePolicy &getSamplePolicy() const { return samplePolicy; }

        const size_t &getNumConcreteSamples() const { return numConcreteSamples; }

        const size_t &getNumAbstractSamples() const { return numAbstractSamples; }

        const size_t &getRandomSeed() const { return randomSeed; }

        void saveToFile(std::fstream &fout) const;

        static SampleParameter loadFromFile(std::fstream &fin);

        static bool matchSampleParameter(const std::filesystem::path &path,
                                         const SampleParameter &sampleParameter);

        bool operator==(const SampleParameter &s) const {
            return samplePolicy == s.samplePolicy && randomSeed == s.randomSeed &&
                   numConcreteSamples == s.numConcreteSamples &&
                   numAbstractSamples == s.numAbstractSamples;
        }
    };

    class EvaluationParameter {
        const std::string &dataCachePath;
        const bool& writeAbstractValue;
        const std::string &abstractValueCacheName;
        const std::vector<std::string> &transferFunctionNames;
        const std::vector<std::string> &baseTransferFunctionNames;
        const size_t &maxOperationLength;
        const std::string &domain;
        const size_t &concreteDomainLength;
        const size_t &abstractDomainLength;
        const size_t &transferFunctionArity;
        const std::vector<size_t> &enumerateBitWidth;
        const std::vector<size_t> &sampleBitWidth;
        const std::vector<size_t> &sampleAbstractAmount;
        const std::vector<size_t> &sampleConcreteAmount;
        const size_t &randomSeed;
        std::unordered_map<size_t, SampleParameter> bitWidthToSampleParameter;

    public:
        EvaluationParameter(const std::string &dataCachePath,
                            const bool& writeAbstractValue,
                            const std::string &abstractValueCacheName,
                            const std::vector<std::string> &transferFunctionNames,
                            const std::vector<std::string> &baseTransferFunctionNames,
                            const size_t &maxOperationLength,
                            const std::string &domain,
                            const size_t &concreteDomainLength,
                            const size_t &abstractDomainLength,
                            const size_t &transferFunctionArity,
                            const std::vector<size_t> &enumerateBitWidth,
                            const std::vector<size_t> &sampleBitWidth,
                            const std::vector<size_t> &sampleAbstractAmount,
                            const std::vector<size_t> &sampleConcreteAmount,
                            const size_t &randomSeed);

        // Getters
        const std::string &getDataCachePath() const { return dataCachePath; }

        const bool& getWriteAbstractValue()const{return writeAbstractValue;}

        const std::string &getAbstractValueCacheName()const{return abstractValueCacheName;}

        const std::vector<std::string> &getTransferFunctionNames() const {
            return transferFunctionNames;
        }

        const std::vector<std::string> &getBaseTransferFunctionNames() const {
            return baseTransferFunctionNames;
        }

        const size_t &getMaxOperationLength() const { return maxOperationLength; }

        const std::string &getDomain() const { return domain; }

        const size_t &getConcreteDomainLength() const { return concreteDomainLength; }

        const size_t &getAbstractDomainLength() const { return abstractDomainLength; }

        const size_t &getTransferFunctionArity() const {
            return transferFunctionArity;
        }

        const std::vector<size_t> &getEnumerateBitWidth() const {
            return enumerateBitWidth;
        }

        const std::vector<size_t> &getSampleBitWidth() const {
            return sampleBitWidth;
        }

        const std::vector<size_t> &getSampleAbstractAmount() const {
            return sampleAbstractAmount;
        }

        const std::vector<size_t> &getSampleConcreteAmount() const {
            return sampleConcreteAmount;
        }

        const size_t &getRandomSeed() const { return randomSeed; }

        const std::unordered_map<size_t, SampleParameter> &
        getBitWidthToSampleParameter() const {
            return bitWidthToSampleParameter;
        }
    };

} // namespace Evaluation

#endif // TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H