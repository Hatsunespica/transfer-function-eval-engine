#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H

#include "DataSampler.h"
#include "EvaluationBatch.h"
#include "EvaluationParameter.h"
#include "EvaluationResult.h"
#include <fstream>
#include <functional>

namespace Evaluation {

    class AbstractValueCache {
        const static inline std::string CACHE_FILE_NAME = "cache";

        // This cache path is the dataPath + uniqueName
        // It is created if the parameter from evaluationParameter is empty
        std::filesystem::path cachePath;
        std::fstream cacheStream;
        size_t abstractDomainLength, bitWidth;
        const std::unordered_map<size_t, SampleParameter> &bitWidthToSampleParameter;
        bool isRead;

        std::filesystem::path getCacheFilePath() const;

    public:
        AbstractValueCache(const EvaluationParameter &evaluationParameter);

        static std::filesystem::path
        createUniqueFolder(const std::filesystem::path &path);

        void loadCache(size_t bitWidth);

        AbstractValue getAbstractValue();

        void writeAbstractValue(const AbstractValue &abstractValue);
    };

    class EvaluationEngine {
        const EvaluationParameter &evaluationParameter;
        const EvaluationBatch &evaluationBatch;
        DataSampler dataSampler;

        bool nextIndices(std::vector<size_t> &indices,
                         const std::vector<size_t> &limits,
                         std::function<void(size_t, size_t)> argSetter);

        AbstractValue computeBestAbstractValue(
                const std::vector<AbstractConcreteValuePair> &abstractConcreteValuePairs,
                const std::vector<size_t> &indices, ConcreteOperation concreteOperation,
                BinaryAbstractFunction join, FromConcreteFunction fromConcreteFunction,
                ConcreteOpConstraint opConstraint, bool trivialOpConstraint,
                bool &hasBestValue);

    public:
        EvaluationEngine(const EvaluationParameter &evaluationParameter,
                         const EvaluationBatch &evaluationBatch);

        EvaluationResultOnBitWidth evaluateBatch();
    };

} // namespace Evaluation

#endif // TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H