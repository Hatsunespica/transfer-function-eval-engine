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
        FromConcreteFunction fromConcreteFunction, ConcreteOpConstraint concreteOpConstraint, bool& hasBestValue) {
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

        AbstractValue result(evaluationParameter.getAbstractDomainLength()), tmpResult(evaluationParameter.getAbstractDomainLength());
        hasBestValue=false;
        int opConstraintResult;
        concreteOpConstraint(args.data(), &opConstraintResult);
        if(opConstraintResult){
            concreteOperation(args.data(),&concreteResult);
            fromConcreteFunction(&concreteResult, result.data());
            hasBestValue=true;
        }
        while (nextIndices(innerIndices, limits, argSetter)) {
            concreteOpConstraint(args.data(), &opConstraintResult);
            if(opConstraintResult){
                concreteOperation(args.data(),&concreteResult);
                if(hasBestValue){
                    fromConcreteFunction(&concreteResult, tmpResult.data());
                    join(result.data(), tmpResult.data(), result.data());
                }else{
                    fromConcreteFunction(&concreteResult, result.data());
                    hasBestValue=true;
                }
            }
        }
        return result;
    }

    void dump(const AbstractValue& absVal) {
        for (int i=0;i<absVal.size();++i) {
            absVal[i].dump();
        }
        llvm::errs()<<"\n";
    }

    void dump(const AbstractDomain& absVal, size_t len) {
        for (int i=0;i<len;++i) {
            absVal[i].dump();
        }
        llvm::errs()<<"\n";
    }

    EvaluationResultOnBitWidth EvaluationEngine::evaluateBatch() {
        size_t numTransferFunctions = evaluationParameter.getTransferFunctionNames().size();
        size_t numBaseTransferFunctions = evaluationParameter.getBaseTransferFunctionNames().size();
        size_t arity = evaluationParameter.getTransferFunctionArity();
        EvaluationResultOnBitWidth finalResult;
        llvm::errs()<<"Only enumerate all bit width with arity "<<arity<<"\n";
        ConcreteOperation concreteOperation = evaluationBatch.getConcreteFunction();
        FromConcreteFunction fromConcrete = evaluationBatch.getFromConcrete();
        BinaryAbstractFunction meet = evaluationBatch.getMeet();
        BinaryAbstractFunction join = evaluationBatch.getJoin();
        DistanceFunction distanceFunction = evaluationBatch.getDistance();
        ContainsFunction contains = evaluationBatch.getContainsFunction();
        ConcreteOpConstraint concreteOpConstraint = evaluationBatch.getConcreteOpConstraint();
        AbstractOpConstraint abstractOpConstraint = evaluationBatch.getAbstractOpConstraint();
        ConstantAbstractFunction getTop = evaluationBatch.getGetTop();
        llvm::APInt distanceResult, baseDistanceResult;

        auto& transferFunctions = evaluationBatch.getTransferFunctions();
        auto& baseTransferFunctions = evaluationBatch.getBaseTransferFunctions();
        bool baseTransferFunctionsNonEmpty = !baseTransferFunctions.empty();
        for (size_t bitWidth :evaluationParameter.getEnumerateBitWidth()){
            EvaluationResult result(numTransferFunctions);
            llvm::errs()<<"Evaluate current bitwidth "<<bitWidth<<"\n";
            auto data=dataSampler.getData(bitWidth);
            llvm::errs()<<"Data pair size: "<<data.size()<<"\n";

            std::vector<size_t> indices(arity, 0), limits(arity, data.size());
            std::vector<AbstractValue> transferResult(numTransferFunctions, AbstractValue(arity));
            std::vector<AbstractDomain> args;

            std::function<void(size_t, size_t)> argSetter = [&args, &data](size_t index, size_t innerIndex) {
                args[index]=const_cast<AbstractDomain>(data[innerIndex].getAbstractValue().data());
            };
            for (int i=0;i<arity;++i) {
                args.push_back(const_cast<AbstractDomain>(data[0].getAbstractValue().data()));
            }

            AbstractValue baseResult(arity), tmpResult(arity), bestResult;
            bool hasBestValue;
            unsigned baseDistance;
            bool solved;
            int cnt=0, abstractOpConstraintResult;

            auto evalOnce = [&](){
                bestResult = computeBestAbstractValue(data, indices,
                                                      concreteOperation, join, fromConcrete, concreteOpConstraint, hasBestValue);
                if(hasBestValue){
                    if(baseTransferFunctionsNonEmpty) {
                        baseTransferFunctions[0](args.data(), baseResult.data());
                        for (int i = 1; i < numBaseTransferFunctions; ++i) {
                            baseTransferFunctions[i](args.data(), tmpResult.data());
                            meet(baseResult.data(), tmpResult.data(), baseResult.data());
                        }
                    }else{
                        getTop(args[0], baseResult.data());
                    }
                    distanceFunction(baseResult.data(), bestResult.data(),&baseDistanceResult);
                    baseDistance = baseDistanceResult.getZExtValue();
                    solved = (baseResult == bestResult);
                    result.addBaseResult(solved, baseDistance);


                    for (int i=0;i<numTransferFunctions;++i) {
                        transferFunctions[i](args.data(),transferResult[i].data());
                        meet(baseResult.data(), transferResult[i].data(), transferResult[i].data());
                    }
                    for (int i=0;i<numTransferFunctions;++i) {
                        // update result for all transfer functions
                        int sound;
                        contains(transferResult[i].data(), bestResult.data(), &sound);
                        bool exact = (transferResult[i] == bestResult);
                        distanceFunction(transferResult[i].data(), bestResult.data(), &distanceResult);
                        unsigned distance = distanceResult.getZExtValue();
                        unsigned soundDistance = sound? distance : baseDistance;
                        result.addIthResult(i, sound,exact,solved, distance, soundDistance);
                    }
                    ++cnt;
                }
            };

            abstractOpConstraint(args.data(),&abstractOpConstraintResult);
            if(abstractOpConstraintResult){
                evalOnce();
            }
            while (nextIndices(indices, limits, argSetter)) {
                if(abstractOpConstraintResult){
                    evalOnce();
                }
            }
            finalResult.emplace(bitWidth, result);
        }
        return finalResult;
    }
}