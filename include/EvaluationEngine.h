#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H

#include "DataSampler.h"
#include "EvaluationBatch.h"
#include "EvaluationParameter.h"
#include "EvaluationResult.h"
#include <functional>

namespace Evaluation {

class EvaluationEngine {
    const EvaluationParameter& evaluationParameter;
    const EvaluationBatch& evaluationBatch;
    DataSampler dataSampler;

    bool nextIndices(std::vector<size_t>& indices, const std::vector<size_t>& limits,
        std::function<void(size_t, size_t)> argSetter);

    AbstractValue computeBestAbstractValue(const std::vector<AbstractConcreteValuePair>& abstractConcreteValuePairs,
        const std::vector<size_t>& indices, ConcreteOperation concreteOperation, BinaryAbstractFunction join,
        FromConcreteFunction fromConcreteFunction, ConcreteOpConstraint opConstraint,bool trivialOpConstraint,
        bool& hasBestValue);

public:
    EvaluationEngine(const EvaluationParameter& evaluationParameter, const EvaluationBatch& evaluationBatch);
    EvaluationResultOnBitWidth evaluateBatch();
};

}



#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H