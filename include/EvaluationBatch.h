#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H

#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/Support/Error.h"
#include "EvaluationTypes.h"
#include <vector>
#include <string>


namespace Evaluation{

class EvaluationBatch {
    std::vector<AbstractOperation> transferFunctions;
    const static inline std::string CONCRETE_FUNCTION_NAME="concrete_op";
    ConcreteOperation concreteFunction;

    const static inline std::string MEET_NAME="meet";
    BinaryAbstractFunction meet, join;

    const static inline std::string GET_TOP_NAME="getTop";
    ConstantAbstractFunction getTop, getBottom;

    const static inline std::string ABSTRACT_DOMAIN_CONSTRAINT_NAME="getConstraint";
    AbstractDomainConstraint abstractDomainConstraint;

    const static inline std::string INSTANCE_CONSTRAINT_NAME="getInstanceConstraint";
    InstanceConstraint instanceConstraint;

    llvm::ExitOnError ExitOnErr;
public:
    EvaluationBatch(std::unique_ptr<llvm::orc::LLJIT> jitModule,
        const std::vector<std::string>& trasnferFunctionNames,
        const std::string& domain);

};
}


#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H