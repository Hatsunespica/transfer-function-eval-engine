#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONTYPES_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONTYPES_H

#include "llvm/ADT/APInt.h"
#include <vector>

namespace Evaluation {
    using APInt = llvm::APInt;

// Here we only consider APInt domain
// A concrete value is an APInt
    using ConcreteValue = APInt;
    using ConcreteValueVector = APInt *;
    using ConcreteDomain = ConcreteValue *;
    using ConcreteDomainVector = ConcreteDomain;
// An abstract value consists of multiple APInts
    using AbstractValue = std::vector<APInt>;
    using AbstractDomain = APInt *;
    using AbstractDomainVector = AbstractDomain *;

    using BinaryAbstractFunction = void (*)(AbstractDomain, AbstractDomain,
                                            AbstractDomain);
    using UnaryAbstractFunction = void (*)(AbstractDomain, AbstractDomain);
// The only argument is used for obtaining bitwidth
    using ConstantAbstractFunction = void (*)(AbstractDomain, AbstractDomain);
    using AbstractDomainConstraint = void (*)(AbstractDomain, int *);
    using InstanceConstraint = void (*)(AbstractDomain, ConcreteDomain, int *);
    using ContainsFunction = void (*)(AbstractDomain, AbstractDomain, int *);
    using ConcreteOpConstraint = void (*)(ConcreteValueVector, int *);
    using AbstractOpConstraint = void (*)(AbstractDomainVector, int *);
    using FromConcreteFunction = void (*)(ConcreteDomain, AbstractDomain);
    using DistanceFunction = void (*)(AbstractDomain, AbstractDomain, APInt *);
    using ConcreteOperation = void (*)(ConcreteDomainVector, ConcreteDomain);
    using AbstractOperation = void (*)(AbstractDomainVector, AbstractDomain);
}; // namespace Evaluation

#endif // TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONTYPES_H