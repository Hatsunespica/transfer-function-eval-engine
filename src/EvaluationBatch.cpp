#include "EvaluationBatch.h"
#include "llvm/Support/Error.h"

namespace Evaluation {

    void DEFAULT_CONCRETE_OP_CONSTRAINT(ConcreteValueVector, int *result) {
        result[0] = 1;
    }

    void DEFAULT_ABSTRACT_OP_CONSTRAINT(AbstractDomainVector, int *result) {
        result[0] = 1;
    }

    EvaluationBatch::EvaluationBatch(llvm::orc::LLJIT &jitModule,
                                     const EvaluationParameter &parameters) {

        ExitOnErr = llvm::ExitOnError("Cannot find desired function");
        abstractDomainConstraint =
                ExitOnErr(jitModule.lookup(ABSTRACT_DOMAIN_CONSTRAINT_NAME))
                        .toPtr<AbstractDomainConstraint>();
        instanceConstraint = ExitOnErr(jitModule.lookup(INSTANCE_CONSTRAINT_NAME))
                .toPtr<InstanceConstraint>();
        getTop = ExitOnErr(jitModule.lookup(GET_TOP_NAME))
                .toPtr<ConstantAbstractFunction>();
        //getBottom = ExitOnErr(jitModule.lookup(GET_BOTTOM_NAME))
        //        .toPtr<ConstantAbstractFunction>();
        distance =
                ExitOnErr(jitModule.lookup(DISTANCE_NAME)).toPtr<DistanceFunction>();
        fromConcrete = ExitOnErr(jitModule.lookup(FROM_CONCRETE_NAME))
                .toPtr<FromConcreteFunction>();
        containsFunction = ExitOnErr(jitModule.lookup(CONTAINS_FUNCTION_NAME))
                .toPtr<ContainsFunction>();
        meet = ExitOnErr(jitModule.lookup(MEET_NAME)).toPtr<BinaryAbstractFunction>();
        join = ExitOnErr(jitModule.lookup(JOIN_NAME)).toPtr<BinaryAbstractFunction>();

        auto concreteOpConstraintResult = jitModule.lookup(CONCRETE_OP_CONSTRAINT);

        if (auto E = concreteOpConstraintResult.takeError()) {
            concreteOpConstraint = DEFAULT_CONCRETE_OP_CONSTRAINT;
            trivialConcreteOpConstraint = true;
            llvm::consumeError(std::move(E));
        } else {
            concreteOpConstraint =
                    concreteOpConstraintResult.get().toPtr<ConcreteOpConstraint>();
            trivialConcreteOpConstraint = false;
        }

        auto abstractOpConstraintResult = jitModule.lookup(ABSTRACT_OP_CONSTRAINT);
        if (auto E = abstractOpConstraintResult.takeError()) {
            abstractOpConstraint = DEFAULT_ABSTRACT_OP_CONSTRAINT;
            trivialAbstractOpConstraint = true;
            llvm::consumeError(std::move(E));
        } else {
            abstractOpConstraint =
                    abstractOpConstraintResult.get().toPtr<AbstractOpConstraint>();
            trivialAbstractOpConstraint = false;
        }

        concreteFunction = ExitOnErr(jitModule.lookup(CONCRETE_FUNCTION_NAME))
                .toPtr<ConcreteOperation>();
        for (const auto &functionName: parameters.getTransferFunctionNames()) {
            transferFunctions.push_back(
                    ExitOnErr(jitModule.lookup(functionName)).toPtr<AbstractOperation>());
        }
        for (const auto &functionName: parameters.getBaseTransferFunctionNames()) {
            baseTransferFunctions.push_back(
                    ExitOnErr(jitModule.lookup(functionName)).toPtr<AbstractOperation>());
        }
    }

} // namespace Evaluation