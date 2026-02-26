#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H

#include <vector>
#include <string>

namespace Evaluation {

class EvaluationParameter {
    const std::string& dataCachePath;
    const std::vector<std::string>& transferFunctionNames;
    const std::vector<std::string>& baseTransferFunctionNames;
    const size_t& maxOperationLength;
    const std::string& domain;
    const size_t& concreteDomainLength;
    const size_t& abstractDomainLength;
    const size_t& transferFunctionArity;
    const std::vector<size_t>& enumerateBitWidth;
    const std::vector<size_t>& sampleBitWidth;
    const std::vector<size_t>& sampleAbstractAmount;
    const std::vector<size_t>& sampleConcreteAmount;
    const size_t& randomSeed;

public:
    EvaluationParameter(
        const std::string& dataCachePath,
        const std::vector<std::string>& transferFunctionNames,
        const std::vector<std::string>& baseTransferFunctionNames,
        const size_t& maxOperationLength,
        const std::string& domain,
        const size_t& concreteDomainLength,
        const size_t& abstractDomainLength,
        const size_t& transferFunctionArity,
        const std::vector<size_t>& enumerateBitWidth,
        const std::vector<size_t>& sampleBitWidth,
        const std::vector<size_t>& sampleAbstractAmount,
        const std::vector<size_t>& sampleConcreteAmount,
        const size_t& randomSeed)
        : dataCachePath(dataCachePath),
          transferFunctionNames(transferFunctionNames),
          baseTransferFunctionNames(baseTransferFunctionNames),
          maxOperationLength(maxOperationLength),
          domain(domain),
          concreteDomainLength(concreteDomainLength),
          abstractDomainLength(abstractDomainLength),
        transferFunctionArity(transferFunctionArity),
          enumerateBitWidth(enumerateBitWidth),
          sampleBitWidth(sampleBitWidth),
          sampleAbstractAmount(sampleAbstractAmount),
          sampleConcreteAmount(sampleConcreteAmount),
          randomSeed(randomSeed){}

    // Getters
    const std::string& getDataCachePath() const {
        return dataCachePath;
    }

    const std::vector<std::string>& getTransferFunctionNames() const {
        return transferFunctionNames;
    }

    const std::vector<std::string>& getBaseTransferFunctionNames() const {
        return baseTransferFunctionNames;
    }

    const size_t& getMaxOperationLength() const {
        return maxOperationLength;
    }

    const std::string& getDomain() const {
        return domain;
    }

    const size_t& getConcreteDomainLength() const {
        return concreteDomainLength;
    }

    const size_t& getAbstractDomainLength() const {
        return abstractDomainLength;
    }

    const size_t& getTransferFunctionArity() const {
        return transferFunctionArity;
    }

    const std::vector<size_t>& getEnumerateBitWidth() const {
        return enumerateBitWidth;
    }

    const std::vector<size_t>& getSampleBitWidth() const {
        return sampleBitWidth;
    }

    const std::vector<size_t>& getSampleAbstractAmount() const {
        return sampleAbstractAmount;
    }

    const std::vector<size_t>& getSampleConcreteAmount() const {
        return sampleConcreteAmount;
    }

    const size_t& getRandomSeed() const {
        return randomSeed;
    }
};

}



#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H