#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONTYPES_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONTYPES_H

#include "llvm/ADT/APInt.h"
#include <functional>

namespace Evaluation {
    template<typename T>
    using function = std::function<T>;
    using APInt = llvm::APInt;

    // Here we only consider APInt domain
    using ConcreteDomain = APInt*;
    using ConcreteDomainVector = ConcreteDomain*;
    // An abstract domain consists of multiple APInts
    using AbstractDomain = APInt**;
    using AbstractDomainVector = AbstractDomain*;

    using BinaryAbstractFunction     = void(*)(AbstractDomain, AbstractDomain, AbstractDomain);
    using UnaryAbstractFunction      = void(*)(AbstractDomain, AbstractDomain);
    using ConstantAbstractFunction   = void(*)(AbstractDomain);
    using AbstractDomainConstraint   = bool(*)(AbstractDomain);
    using InstanceConstraint         = bool(*)(AbstractDomain, ConcreteDomain);

    using ConcreteOperation          = void(*)(ConcreteDomainVector);
    using AbstractOperation          = void(*)(AbstractDomainVector);
};

#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONTYPES_H