#include "EvaluationEngine.h"
#include <chrono>
#include <cstdio>
#include <cinttypes>
#include <random>

namespace Evaluation {
    std::filesystem::path
    AbstractValueCache::getCacheFilePath() const {
        auto newPath = cachePath / std::to_string(bitWidth);
        if (!exists(newPath)) {
            create_directories(newPath);
        }
        assert(is_directory(newPath));
        return newPath / CACHE_FILE_NAME;
    }

    AbstractValueCache::AbstractValueCache(
            const EvaluationParameter &evaluationParameter) : abstractDomainLength(
            evaluationParameter.getAbstractDomainLength()),
                                                              bitWidthToSampleParameter(
                                                                      evaluationParameter.getBitWidthToSampleParameter()) {
        isRead = !evaluationParameter.getAbstractValueCacheName().empty();
        isWrite = evaluationParameter.getWriteAbstractValue();
        if (isRead) {
            cachePath = std::filesystem::path(evaluationParameter.getDataCachePath()) /
                        evaluationParameter.getAbstractValueCacheName();
            assert(is_directory(cachePath));
        }
        if(isWrite){
            auto dataPath = std::filesystem::path(evaluationParameter.getDataCachePath());
            cachePath = createUniqueFolder(dataPath);
        }
        bitWidth = 0;
    }

    std::filesystem::path
    AbstractValueCache::createUniqueFolder(const std::filesystem::path &path) {
        namespace fs = std::filesystem;
        static std::mt19937_64 rng(
                (std::random_device{}()) ^
                static_cast<uint64_t>(std::chrono::high_resolution_clock::now()
                        .time_since_epoch()
                        .count()));

        std::uniform_int_distribution<uint64_t> dist;

        while (true) {
            uint64_t value = dist(rng);

            // 16 hex digits + null terminator
            char buffer[17];
            std::snprintf(buffer, sizeof(buffer), "%016" PRIx64, value);

            std::string name(buffer);

            fs::path candidate = path / name;

            // Race-safe uniqueness check
            if (fs::create_directory(candidate)) {
                return candidate;
            }
        }
    }

    void AbstractValueCache::loadCache(size_t bitWidth) {
        this->bitWidth = bitWidth;
        auto cacheFilePath = getCacheFilePath();
        const auto &sampleParameter = bitWidthToSampleParameter.find(bitWidth)->second;
        if (isRead) {
            cacheStream = std::fstream(cacheFilePath, std::ios::binary | std::ios::in);
            auto fileSampleParameter = SampleParameter::loadFromFile(cacheStream);
            assert(sampleParameter == fileSampleParameter);
            return;
        }
        if(isWrite) {
            cacheStream = std::fstream(cacheFilePath, std::ios::binary | std::ios::out| std::ios::trunc);
            sampleParameter.saveToFile(cacheStream);
            return;
        }
        assert(false);
    }

    void AbstractValueCache::getAbstractValue(AbstractValue& abstractValue, bool& hasBestValue) {
        uint64_t tmp;
        cacheStream.read((char *) &tmp, sizeof(uint64_t));
        hasBestValue = tmp;
        abstractValue.clear();
        if(hasBestValue){
            for (size_t i = 0; i < abstractDomainLength; ++i) {
                cacheStream.read((char *) &tmp, sizeof(uint64_t));
                abstractValue.emplace_back(bitWidth, tmp);
            }
        }
    }

    void AbstractValueCache::writeAbstractValue(const AbstractValue &abstractValue,const bool& hasBestValue) {
        uint64_t tmp=hasBestValue;
        cacheStream.write((char *) &tmp, sizeof(uint64_t));
        if(hasBestValue){
            for (const auto &apInt: abstractValue) {
                tmp = apInt.getZExtValue();
                cacheStream.write((char *) &tmp, sizeof(uint64_t));
            }
        }
    }

    EvaluationEngine::EvaluationEngine(
            const EvaluationParameter &evaluationParameter,
            const EvaluationBatch &evaluationBatch)
            : evaluationParameter(evaluationParameter),
              evaluationBatch(evaluationBatch),
              dataSampler(evaluationParameter, evaluationBatch),
              abstractValueCache(evaluationParameter){}

    bool EvaluationEngine::nextIndices(
            std::vector<size_t> &indices, const std::vector<size_t> &limits,
            std::function<void(size_t, size_t)> argSetter) {
        indices.back()++;
        bool carry = indices.back() == limits.back();
        if (carry) {
            int n = indices.size() - 1;
            for (; carry && n >= 1; --n) {
                indices[n] = 0;
                argSetter(n, 0);
                indices[n - 1]++;
                carry = indices[n - 1] == limits[n - 1];
            }
            if (indices[0] == limits[0]) {
                return false;
            }
            argSetter(n, indices[n]);
            return true;
        } else {
            argSetter(indices.size() - 1, indices.back());
            return true;
        }
    }

    AbstractValue EvaluationEngine::computeBestAbstractValue(
            const std::vector<AbstractConcreteValuePair> &abstractConcreteValuePairs,
            const std::vector<size_t> &indices, ConcreteOperation concreteOperation,
            BinaryAbstractFunction join, FromConcreteFunction fromConcreteFunction,
            ConcreteOpConstraint concreteOpConstraint, bool trivialOpConstraint,
            bool &hasBestValue) {
        std::vector<size_t> innerIndices(indices.size(), 0);
        std::vector<llvm::APInt> args;
        llvm::APInt concreteResult;
        std::vector<size_t> limits;
        for (size_t index: indices) {
            limits.push_back(
                    abstractConcreteValuePairs[index].getConcreteValues().size());
            args.push_back(abstractConcreteValuePairs[index].getConcreteValues()[0]);
        }
        std::function<void(size_t, size_t)> argSetter =
                [&args, &indices, &abstractConcreteValuePairs](size_t index,
                                                               size_t innerIndex) {
                    args[index] = abstractConcreteValuePairs[indices[index]]
                            .getConcreteValues()[innerIndex];
                };

        AbstractValue result(evaluationParameter.getAbstractDomainLength()),
                tmpResult(evaluationParameter.getAbstractDomainLength());
        hasBestValue = false;
        int opConstraintResult = 1;
        if (trivialOpConstraint) {
            concreteOperation(args.data(), &concreteResult);
            fromConcreteFunction(&concreteResult, result.data());
            hasBestValue = true;
            while (nextIndices(innerIndices, limits, argSetter)) {
                concreteOperation(args.data(), &concreteResult);
                fromConcreteFunction(&concreteResult, tmpResult.data());
                join(result.data(), tmpResult.data(), result.data());

            }
        } else {
            // In the else branch, we need to check concreteOpConstraint for every
            // inputs
            concreteOpConstraint(args.data(), &opConstraintResult);
            if (opConstraintResult) {
                concreteOperation(args.data(), &concreteResult);
                fromConcreteFunction(&concreteResult, result.data());
                hasBestValue = true;
            }
            while (nextIndices(innerIndices, limits, argSetter)) {
                concreteOpConstraint(args.data(), &opConstraintResult);
                if (opConstraintResult) {
                    concreteOperation(args.data(), &concreteResult);
                    if (hasBestValue) {
                        fromConcreteFunction(&concreteResult, tmpResult.data());
                        join(result.data(), tmpResult.data(), result.data());
                    } else {
                        fromConcreteFunction(&concreteResult, result.data());
                        hasBestValue = true;
                    }
                }
            }
        }
        return result;
    }

    void dump(const AbstractValue &absVal) {
        for (int i = 0; i < absVal.size(); ++i) {
            absVal[i].dump();
        }
        llvm::errs() << "\n";
    }

    void dump(const AbstractDomain &absVal, size_t len) {
        for (int i = 0; i < len; ++i) {
            absVal[i].dump();
        }
        llvm::errs() << "\n";
    }

    EvaluationResultOnBitWidth EvaluationEngine::evaluateBatch() {
        size_t numTransferFunctions =
                evaluationParameter.getTransferFunctionNames().size();
        size_t numBaseTransferFunctions =
                evaluationParameter.getBaseTransferFunctionNames().size();
        size_t arity = evaluationParameter.getTransferFunctionArity();
        EvaluationResultOnBitWidth finalResult;
        llvm::errs() << "Only enumerate all bit width with arity " << arity << "\n";
        ConcreteOperation concreteOperation = evaluationBatch.getConcreteFunction();
        FromConcreteFunction fromConcrete = evaluationBatch.getFromConcrete();
        BinaryAbstractFunction meet = evaluationBatch.getMeet();
        BinaryAbstractFunction join = evaluationBatch.getJoin();
        DistanceFunction distanceFunction = evaluationBatch.getDistance();
        ContainsFunction contains = evaluationBatch.getContainsFunction();
        ConcreteOpConstraint concreteOpConstraint =
                evaluationBatch.getConcreteOpConstraint();
        AbstractOpConstraint abstractOpConstraint =
                evaluationBatch.getAbstractOpConstraint();
        ConstantAbstractFunction getTop = evaluationBatch.getGetTop();
        bool trivialConcreteOpConstraint =
                evaluationBatch.isTrivialConcreteOpConstraint();
        bool trivialAbstractOpConstraint =
                evaluationBatch.isTrivialAbstractOpConstraint();
        bool isReadCache = abstractValueCache.isReadCache();
        llvm::APInt distanceResult, baseDistanceResult;

        auto &transferFunctions = evaluationBatch.getTransferFunctions();
        auto &baseTransferFunctions = evaluationBatch.getBaseTransferFunctions();
        bool baseTransferFunctionsNonEmpty = !baseTransferFunctions.empty();
        for (size_t bitWidth: evaluationParameter.getEnumerateBitWidth()) {
            if(isReadCache){
                abstractValueCache.loadCache(bitWidth);
            }
            EvaluationResult result(numTransferFunctions);
            llvm::errs() << "Evaluate current bitwidth " << bitWidth << "\n";
            auto data = dataSampler.getData(bitWidth);
            llvm::errs() << "Data pair size: " << data.size() << "\n";

            std::vector<size_t> indices(arity, 0), limits(arity, data.size());
            std::vector<AbstractValue> transferResult(numTransferFunctions,
                                                      AbstractValue(arity));
            std::vector<AbstractDomain> args;

            std::function<void(size_t, size_t)> argSetter =
                    [&args, &data](size_t index, size_t innerIndex) {
                        args[index] = const_cast<AbstractDomain>(
                                data[innerIndex].getAbstractValue().data());
                    };
            for (int i = 0; i < arity; ++i) {
                args.push_back(
                        const_cast<AbstractDomain>(data[0].getAbstractValue().data()));
            }

            AbstractValue baseResult(arity), tmpResult(arity), bestResult;
            bool hasBestValue;
            unsigned baseDistance;
            bool solved;
            int cnt = 0;

            auto evalOnce = [&]() {
                if(isReadCache){
                    abstractValueCache.getAbstractValue(bestResult, hasBestValue);
                }else{
                    bestResult = computeBestAbstractValue(
                            data, indices, concreteOperation, join, fromConcrete,
                            concreteOpConstraint, trivialConcreteOpConstraint, hasBestValue);
                }

                if (hasBestValue) {
                    if (baseTransferFunctionsNonEmpty) {
                        baseTransferFunctions[0](args.data(), baseResult.data());
                        for (int i = 1; i < numBaseTransferFunctions; ++i) {
                            baseTransferFunctions[i](args.data(), tmpResult.data());
                            meet(baseResult.data(), tmpResult.data(), baseResult.data());
                        }
                    } else {
                        getTop(args[0], baseResult.data());
                    }
                    distanceFunction(baseResult.data(), bestResult.data(),
                                     &baseDistanceResult);
                    baseDistance = baseDistanceResult.getZExtValue();
                    solved = (baseResult == bestResult);
                    result.addBaseResult(solved, baseDistance);

                    for (int i = 0; i < numTransferFunctions; ++i) {
                        transferFunctions[i](args.data(), transferResult[i].data());
                        meet(baseResult.data(), transferResult[i].data(),
                             transferResult[i].data());
                    }
                    for (int i = 0; i < numTransferFunctions; ++i) {
                        // update result for all transfer functions
                        int sound;
                        contains(transferResult[i].data(), bestResult.data(), &sound);
                        bool exact = (transferResult[i] == bestResult);
                        distanceFunction(transferResult[i].data(), bestResult.data(),
                                         &distanceResult);
                        unsigned distance = distanceResult.getZExtValue();
                        unsigned soundDistance = sound ? distance : baseDistance;
                        result.addIthResult(i, sound, exact, solved, distance, soundDistance);
                    }
                    ++cnt;
                }
            };

            int abstractOpConstraintResult = 1;

            if (trivialAbstractOpConstraint) {
                evalOnce();
                while (nextIndices(indices, limits, argSetter)) {
                    evalOnce();
                }
            } else {
                // In the else branch, we need to check abstractOpConstraint for every
                // inputs
                abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                if (abstractOpConstraintResult) {
                    evalOnce();
                }
                while (nextIndices(indices, limits, argSetter)) {
                    abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                    if (abstractOpConstraintResult) {
                        evalOnce();
                    }
                }
            }

            finalResult.emplace(bitWidth, result);
        }
        return finalResult;
    }

    void EvaluationEngine::computeAndSaveAbstractValues(){
        size_t numTransferFunctions =
                evaluationParameter.getTransferFunctionNames().size();
        size_t arity = evaluationParameter.getTransferFunctionArity();
        EvaluationResultOnBitWidth finalResult;
        llvm::errs() << "Only enumerate all bit width with arity " << arity << "\n";
        ConcreteOperation concreteOperation = evaluationBatch.getConcreteFunction();
        FromConcreteFunction fromConcrete = evaluationBatch.getFromConcrete();
        BinaryAbstractFunction join = evaluationBatch.getJoin();
        ConcreteOpConstraint concreteOpConstraint =
                evaluationBatch.getConcreteOpConstraint();
        AbstractOpConstraint abstractOpConstraint =
                evaluationBatch.getAbstractOpConstraint();
        bool trivialConcreteOpConstraint =
                evaluationBatch.isTrivialConcreteOpConstraint();
        bool trivialAbstractOpConstraint =
                evaluationBatch.isTrivialAbstractOpConstraint();
        llvm::APInt distanceResult, baseDistanceResult;

        for (size_t bitWidth: evaluationParameter.getEnumerateBitWidth()) {
            EvaluationResult result(numTransferFunctions);
            llvm::errs() << "Evaluate current bitwidth " << bitWidth << "\n";
            auto data = dataSampler.getData(bitWidth);
            llvm::errs() << "Data pair size: " << data.size() << "\n";
            assert(abstractValueCache.isWriteCache());
            abstractValueCache.loadCache(bitWidth);

            std::vector<size_t> indices(arity, 0), limits(arity, data.size());
            std::vector<AbstractDomain> args;

            std::function<void(size_t, size_t)> argSetter =
                    [&args, &data](size_t index, size_t innerIndex) {
                        args[index] = const_cast<AbstractDomain>(
                                data[innerIndex].getAbstractValue().data());
                    };
            for (int i = 0; i < arity; ++i) {
                args.push_back(
                        const_cast<AbstractDomain>(data[0].getAbstractValue().data()));
            }

            AbstractValue bestResult;
            bool hasBestValue;

            auto evalOnce = [&]() {
                bestResult = computeBestAbstractValue(
                        data, indices, concreteOperation, join, fromConcrete,
                        concreteOpConstraint, trivialConcreteOpConstraint, hasBestValue);
                abstractValueCache.writeAbstractValue(bestResult, hasBestValue);
            };

            int abstractOpConstraintResult = 1;

            if (trivialAbstractOpConstraint) {
                evalOnce();
                while (nextIndices(indices, limits, argSetter)) {
                    evalOnce();
                }
            } else {
                // In the else branch, we need to check abstractOpConstraint for every
                // inputs
                abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                if (abstractOpConstraintResult) {
                    evalOnce();
                }
                while (nextIndices(indices, limits, argSetter)) {
                    abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                    if (abstractOpConstraintResult) {
                        evalOnce();
                    }
                }
            }
        }
    }
} // namespace Evaluation