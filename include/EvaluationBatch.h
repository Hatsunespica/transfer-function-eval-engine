#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H

#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/Support/Error.h"
#include "EvaluationTypes.h"
#include "EvaluationParameter.h"


namespace Evaluation{

class EvaluationBatch {
    std::vector<AbstractOperation> transferFunctions, baseTransferFunctions;
    const static inline std::string CONCRETE_FUNCTION_NAME="concrete_op";
    ConcreteOperation concreteFunction;

    const static inline std::string MEET_NAME="meet";
    BinaryAbstractFunction meet, join;

    const static inline std::string GET_TOP_NAME="getTop";
    ConstantAbstractFunction getTop, getBottom;

    const static inline std::string FROM_CONCRETE_NAME="fromConcrete";
    FromConcreteFunction fromConcrete;

    const static inline std::string DISTANCE_NAME = "distance";
    DistanceFunction distance;

    const static inline std::string ABSTRACT_DOMAIN_CONSTRAINT_NAME="getConstraint";
    AbstractDomainConstraint abstractDomainConstraint;

    const static inline std::string INSTANCE_CONSTRAINT_NAME="getInstanceConstraint";
    InstanceConstraint instanceConstraint;

    llvm::ExitOnError ExitOnErr;
public:
    EvaluationBatch(std::unique_ptr<llvm::orc::LLJIT> jitModule,
        const EvaluationParameter& parameters);
};
}


#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H