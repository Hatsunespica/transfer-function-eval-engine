#include "EvaluationBatch.h"

namespace Evaluation {

EvaluationBatch::EvaluationBatch(std::unique_ptr<llvm::orc::LLJIT> jitModule,
    const EvaluationParameter& parameters) {

    ExitOnErr = llvm::ExitOnError("Cannot find desired function");

    abstractDomainConstraint = ExitOnErr(jitModule->lookup(ABSTRACT_DOMAIN_CONSTRAINT_NAME)).toPtr<AbstractDomainConstraint>();
    instanceConstraint = ExitOnErr(jitModule->lookup(INSTANCE_CONSTRAINT_NAME)).toPtr<InstanceConstraint>();
    getTop = ExitOnErr(jitModule->lookup(GET_TOP_NAME)).toPtr<ConstantAbstractFunction>();
    distance = ExitOnErr(jitModule->lookup(DISTANCE_NAME)).toPtr<DistanceFunction>();
    fromConcrete = ExitOnErr(jitModule->lookup(FROM_CONCRETE_NAME)).toPtr<FromConcreteFunction>();

    concreteFunction = ExitOnErr(jitModule->lookup(CONCRETE_FUNCTION_NAME)).toPtr<ConcreteOperation>();
    for (const auto& functionName : parameters.getTransferFunctionNames()) {
        transferFunctions.push_back(ExitOnErr(jitModule->lookup(functionName)).toPtr<AbstractOperation>());
    }
    for (const auto& functionName : parameters.getBaseTransferFunctionNames()) {
        baseTransferFunctions.push_back(ExitOnErr(jitModule->lookup(functionName)).toPtr<AbstractOperation>());
    }
}

}