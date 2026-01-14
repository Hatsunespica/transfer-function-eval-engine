#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H

#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/Support/Error.h"
#include "EvaluationTypes.h"
#include "EvaluationParameter.h"


namespace Evaluation{

class EvaluationBatch {
    std::vector<AbstractOperation> transferFunctions, baseTransferFunctions;
    const static inline std::string CONCRETE_FUNCTION_NAME = "concrete_op";
    ConcreteOperation concreteFunction;

    const static inline std::string MEET_NAME = "meet";
    const static inline std::string JOIN_NAME = "join";
    BinaryAbstractFunction meet, join;

    const static inline std::string GET_TOP_NAME = "getTop";
    ConstantAbstractFunction getTop, getBottom;

    const static inline std::string FROM_CONCRETE_NAME = "fromConcrete";
    FromConcreteFunction fromConcrete;

    const static inline std::string DISTANCE_NAME = "distance";
    DistanceFunction distance;

    const static inline std::string ABSTRACT_DOMAIN_CONSTRAINT_NAME = "getConstraint";
    AbstractDomainConstraint abstractDomainConstraint;

    const static inline std::string INSTANCE_CONSTRAINT_NAME = "getInstanceConstraint";
    InstanceConstraint instanceConstraint;

    llvm::ExitOnError ExitOnErr;

public:
    EvaluationBatch(llvm::orc::LLJIT& jitModule,
                    const EvaluationParameter& parameters);


    const std::vector<AbstractOperation>& getTransferFunctions() const {
        return transferFunctions;
    }

    const std::vector<AbstractOperation>& getBaseTransferFunctions() const {
        return baseTransferFunctions;
    }

    const ConcreteOperation& getConcreteFunction() const {
        return concreteFunction;
    }

    const BinaryAbstractFunction& getMeet() const {
        return meet;
    }

    const BinaryAbstractFunction& getJoin() const {
        return join;
    }

    const ConstantAbstractFunction& getGetTop() const {
        return getTop;
    }

    const ConstantAbstractFunction& getGetBottom() const {
        return getBottom;
    }

    const FromConcreteFunction& getFromConcrete() const {
        return fromConcrete;
    }

    const DistanceFunction& getDistance() const {
        return distance;
    }

    const AbstractDomainConstraint& getAbstractDomainConstraint() const {
        return abstractDomainConstraint;
    }

    const InstanceConstraint& getInstanceConstraint() const {
        return instanceConstraint;
    }

};
}


#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONBATCH_H