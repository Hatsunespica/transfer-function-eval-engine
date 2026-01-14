#include "EvaluationEngine.h"

namespace Evaluation {
    EvaluationEngine::EvaluationEngine(const EvaluationParameter& evaluationParameter, const EvaluationBatch& evaluationBatch):
        evaluationParameter(evaluationParameter),
        evaluationBatch(evaluationBatch), dataSampler(evaluationParameter, evaluationBatch){}


    bool EvaluationEngine::nextIndices(std::vector<size_t>& indices, const std::vector<size_t>& limits,
        std::function<void(size_t, size_t)> argSetter) {
        indices.back()++;
        bool carry = indices.back() == limits.back();
        if (carry) {
            int n=indices.size() -1;
            for (;carry && n>=1;--n) {
                indices[n]=0;
                argSetter(n, 0);
                indices[n-1]++;
                carry = indices[n-1] == limits[n-1];
            }
            if (indices[0] == limits[0]) {
                return false;
            }
            argSetter(n, indices[n]);
            return true;
        }else {
            argSetter(indices.size()-1, indices.back());
            return true;
        }
    }

    AbstractValue EvaluationEngine::computeBestAbstractValue(const std::vector<AbstractConcreteValuePair>& abstractConcreteValuePairs,
        const std::vector<size_t>& indices, ConcreteOperation concreteOperation, BinaryAbstractFunction join,
        FromConcreteFunction fromConcreteFunction) {
        std::vector<size_t> innerIndices(indices.size(), 0);
        std::vector<llvm::APInt> args;
        llvm::APInt concreteResult;
        std::vector<size_t> limits;
        for (size_t index : indices) {
            limits.push_back(abstractConcreteValuePairs[index].getConcreteValues().size());
            args.push_back(abstractConcreteValuePairs[index].getConcreteValues()[0]);
        }
        std::function<void(size_t, size_t)> argSetter = [&args, &indices, &abstractConcreteValuePairs](size_t index, size_t innerIndex) {
            args[index] = abstractConcreteValuePairs[indices[index]].getConcreteValues()[innerIndex];
        };

        concreteOperation(args.data(),&concreteResult);
        AbstractValue result(evaluationParameter.getAbstractDomainLength()), tmpResult(evaluationParameter.getAbstractDomainLength());
        fromConcreteFunction(&concreteResult, result.data());
        while (nextIndices(innerIndices, limits, argSetter)) {
            concreteOperation(args.data(),&concreteResult);
            fromConcreteFunction(&concreteResult, tmpResult.data());
            join(result.data(), tmpResult.data(), result.data());
        }
        return result;
    }

    void dump(const AbstractValue& absVal) {
        for (int i=0;i<absVal.size();++i) {
            absVal[i].dump();
        }
        llvm::errs()<<"\n";
    }

    EvaluationResult EvaluationEngine::evaluateBatch() {
        size_t numTransferFunctions = evaluationParameter.getTransferFunctionNames().size();
        size_t numBaseTransferFunctions = evaluationParameter.getBaseTransferFunctionNames().size();
        size_t arity = evaluationParameter.getTransferFunctionArity();
        EvaluationResult result(numTransferFunctions);
        llvm::errs()<<"Only enumerate all bit width with arity "<<arity<<"\n";
        ConcreteOperation concreteOperation = evaluationBatch.getConcreteFunction();
        FromConcreteFunction fromConcrete = evaluationBatch.getFromConcrete();
        BinaryAbstractFunction meet = evaluationBatch.getMeet();
        BinaryAbstractFunction join = evaluationBatch.getJoin();

        auto& transferFunctions = evaluationBatch.getTransferFunctions();
        auto& baseTransferFunctions = evaluationBatch.getBaseTransferFunctions();
        for (size_t bitWidth :evaluationParameter.getEnumerateBitWidth()){
            llvm::errs()<<"Evaluate current bitwidth "<<bitWidth<<"\n";
            auto data=dataSampler.getData(bitWidth);
            llvm::errs()<<"Data pair size: "<<data.size()<<"\n";

            std::vector<size_t> indices(arity, 0), limits(arity, data.size());
            std::vector<AbstractValue> args;
            std::vector<AbstractDomain> ptrArgs;

            std::function<void(size_t, size_t)> argSetter = [&args, &data](size_t index, size_t innerIndex) {
                args[index]=data[innerIndex].getAbstractValue();
            };
            for (int i=0;i<arity;++i) {
                args.push_back(data[0].getAbstractValue());
                ptrArgs.push_back(args[i].data());
            }

            AbstractValue bestResult = computeBestAbstractValue(data, indices, concreteOperation, join, fromConcrete);
            AbstractValue baseResult(arity), tmpResult(arity);


            baseTransferFunctions[0](ptrArgs.data(), baseResult.data());
            for (int i=1;i<baseTransferFunctions.size();++i) {
                baseTransferFunctions[i](ptrArgs.data(), tmpResult.data());
                meet(baseResult.data(), tmpResult.data(), baseResult.data());
            }
            for (int i=0;i<transferFunctions.size();++i) {
                // update result for all transfer functions
            }

            int cnt=1;
            while (nextIndices(indices, limits, argSetter)) {
                bestResult = computeBestAbstractValue(data, indices, concreteOperation, join, fromConcrete);
                for (int i=0;i<arity;++i) {
                    ptrArgs[i] = args[i].data();
                }

                baseTransferFunctions[0](ptrArgs.data(), baseResult.data());
                for (int i=1;i<baseTransferFunctions.size();++i) {
                    baseTransferFunctions[i](ptrArgs.data(), tmpResult.data());
                    meet(baseResult.data(), tmpResult.data(), baseResult.data());
                }
                for (int i=0;i<transferFunctions.size();++i) {
                    // update result for all transfer functions
                }
                ++cnt;
            }
        }
        return result;
    }
}