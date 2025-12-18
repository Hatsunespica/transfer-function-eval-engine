#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H

#include <vector>
#include <string>

namespace Evaluation {

class EvaluationParameter {
    const std::string& dataCachePath;
    const std::vector<std::string>& transferFunctionNames;
    const std::vector<std::string>& baseTransferFunctionNames;
    const std::string& domain;
    const std::vector<size_t>& enumerateBitWidth;
    const std::vector<size_t>& sampleBitWidth;
    const std::vector<size_t>& sampleAmount;

public:
    EvaluationParameter(
        const std::string& dataCachePath,
        const std::vector<std::string>& transferFunctionNames,
        const std::vector<std::string>& baseTransferFunctionNames,
        const std::string& domain,
        const std::vector<size_t>& enumerateBitWidth,
        const std::vector<size_t>& sampleBitWidth,
        const std::vector<size_t>& sampleAmount)
        : dataCachePath(dataCachePath),
          transferFunctionNames(transferFunctionNames),
          baseTransferFunctionNames(baseTransferFunctionNames),
          domain(domain),
          enumerateBitWidth(enumerateBitWidth),
          sampleBitWidth(sampleBitWidth),
          sampleAmount(sampleAmount) {}

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

    const std::string& getDomain() const {
        return domain;
    }

    const std::vector<size_t>& getEnumerateBitWidth() const {
        return enumerateBitWidth;
    }

    const std::vector<size_t>& getSampleBitWidth() const {
        return sampleBitWidth;
    }

    const std::vector<size_t>& getSampleAmount() const {
        return sampleAmount;
    }
};

}



#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONPARAMETER_H