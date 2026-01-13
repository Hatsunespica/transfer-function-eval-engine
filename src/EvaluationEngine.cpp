#include "EvaluationEngine.h"

namespace Evaluation {
    EvaluationEngine::EvaluationEngine(const EvaluationParameter& evaluationParameter, const EvaluationBatch& evaluationBatch):
        evaluationParameter(evaluationParameter),
        evaluationBatch(evaluationBatch), dataSampler(evaluationParameter, evaluationBatch){}

    void EvaluationEngine::evaluateBatch() {
        llvm::errs()<<"Eval batch\n";
    }
}