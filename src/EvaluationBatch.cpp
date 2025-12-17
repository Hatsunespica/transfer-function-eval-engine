#include "EvaluationBatch.h"

namespace Evaluation {

EvaluationBatch::EvaluationBatch(std::unique_ptr<llvm::orc::LLJIT> jitModule,
    const std::vector<std::string>& trasnferFunctionNames,
    const std::string& domain) {

    ExitOnErr = llvm::ExitOnError("Cannot find desired function");

    concreteFunction = ExitOnErr(jitModule->lookup(CONCRETE_FUNCTION_NAME)).toPtr<ConcreteOperation>();
    for (const auto& functionName : trasnferFunctionNames) {
        transferFunctions.push_back(ExitOnErr(jitModule->lookup(functionName)).toPtr<AbstractOperation>());
    }
    abstractDomainConstraint = ExitOnErr(jitModule->lookup(ABSTRACT_DOMAIN_CONSTRAINT_NAME)).toPtr<AbstractDomainConstraint>();
    instanceConstraint = ExitOnErr(jitModule->lookup(INSTANCE_CONSTRAINT_NAME)).toPtr<InstanceConstraint>();
    getTop = ExitOnErr(jitModule->lookup(GET_TOP_NAME)).toPtr<ConstantAbstractFunction>();

}

}