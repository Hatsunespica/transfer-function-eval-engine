#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H

#include "DataSampler.h"
#include "EvaluationBatch.h"
#include "EvaluationParameter.h"
#include "EvaluationResult.h"

namespace Evaluation {

class EvaluationEngine {
    const EvaluationParameter& evaluationParameter;
    const EvaluationBatch& evaluationBatch;
    DataSampler dataSampler;
public:
    EvaluationEngine(const EvaluationParameter& evaluationParameter, const EvaluationBatch& evaluationBatch);
    void evaluateBatch();
};

}



#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONENGINE_H