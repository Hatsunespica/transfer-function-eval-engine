#include "EvaluationEngine.h"
#include <chrono>
#include <cstdio>
#include <cinttypes>
#include <random>
#include <execution>

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
        if (isWrite) {
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
        if (isWrite) {
            cacheStream = std::fstream(cacheFilePath, std::ios::binary | std::ios::out | std::ios::trunc);
            sampleParameter.saveToFile(cacheStream);
            return;
        }
        assert(false);
    }

    void AbstractValueCache::getAbstractValue(AbstractValue &abstractValue, bool &hasBestValue) {
        uint64_t tmp;
        cacheStream.read((char *) &tmp, sizeof(uint64_t));
        hasBestValue = tmp;
        abstractValue.clear();
        if (hasBestValue) {
            for (size_t i = 0; i < abstractDomainLength; ++i) {
                cacheStream.read((char *) &tmp, sizeof(uint64_t));
                abstractValue.emplace_back(bitWidth, tmp);
            }
        }
    }

    void AbstractValueCache::writeAbstractValue(const AbstractValue &abstractValue, const bool &hasBestValue) {
        uint64_t tmp = hasBestValue;
        cacheStream.write((char *) &tmp, sizeof(uint64_t));
        if (hasBestValue) {
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
              abstractValueCache(evaluationParameter) {}

    bool EvaluationEngine::nextIndices(
            std::vector<size_t> &indices, const std::vector<size_t> &limits,
            const size_t& step,
            std::function<void(size_t, size_t)> argSetter) {
        int n=indices.size()-1, carry = step, newValue;
        while(n>=0 && carry > 0){
            newValue = indices[n] + carry;
            indices[n] = newValue % limits[n];
            carry = newValue / limits[n];
            argSetter(n, indices[n]);
            --n;
        }
        return carry==0;
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
            while (nextIndices(innerIndices, limits, 1, argSetter)) {
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
            while (nextIndices(innerIndices, limits, 1, argSetter)) {
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
        size_t abstractDomainLength = evaluationParameter.getAbstractDomainLength();
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
            if (isReadCache) {
                abstractValueCache.loadCache(bitWidth);
            }
            const auto& sampleParameter = evaluationParameter.getSampleParameterByBitWidth(bitWidth);
            size_t step = sampleParameter.getStep();
            EvaluationResult result(numTransferFunctions);
            llvm::errs() << "Evaluate current bitwidth " << bitWidth << "\n";
            auto data = dataSampler.getData(bitWidth);
            llvm::errs() << "Data pair size: " << data.size() << "\n";

            std::vector<size_t> indices(arity, 0), limits(arity, data.size());
            std::vector<AbstractValue> transferResult(numTransferFunctions,
                                                      AbstractValue(abstractDomainLength));
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

            AbstractValue baseResult(abstractDomainLength), tmpResult(abstractDomainLength), bestResult;
            bool hasBestValue;
            unsigned baseDistance;
            bool solved;
            int cnt = 0;

            auto evalOnce = [&]() {
                if (isReadCache) {
                    abstractValueCache.getAbstractValue(bestResult, hasBestValue);
                } else {
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

#pragma omp parallel for schedule(dynamic)
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
                while (nextIndices(indices, limits, step, argSetter)) {
                    evalOnce();
                }
            } else {
                // In the else branch, we need to check abstractOpConstraint for every
                // inputs
                abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                if (abstractOpConstraintResult) {
                    evalOnce();
                }
                while (nextIndices(indices, limits, step, argSetter)) {
                    abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                    if (abstractOpConstraintResult) {
                        evalOnce();
                    }
                }
            }

            finalResult.emplace(bitWidth, result);
        }

        if (!evaluationParameter.getExternalDataPath().empty()) {
            ExternalDataLoader dataLoader(evaluationParameter);
            auto dataSet = dataLoader.loadFromExternalData();
            evaluateOnExternalData(dataSet, finalResult);
        }
        return finalResult;
    }

    void EvaluationEngine::computeAndSaveAbstractValues() {
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
            const SampleParameter& sampleParameter = evaluationParameter.getSampleParameterByBitWidth(bitWidth);
            size_t step = sampleParameter.getStep();
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
                while (nextIndices(indices, limits, step, argSetter)) {
                    evalOnce();
                }
            } else {
                // In the else branch, we need to check abstractOpConstraint for every
                // inputs
                abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                if (abstractOpConstraintResult) {
                    evalOnce();
                }
                while (nextIndices(indices, limits, step, argSetter)) {
                    abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                    if (abstractOpConstraintResult) {
                        evalOnce();
                    }
                }
            }
        }
    }

    void
    EvaluationEngine::evaluateOnExternalData(const ExternalDataSet &dataSet, EvaluationResultOnBitWidth &finalResult) {
        size_t numTransferFunctions =
                evaluationParameter.getTransferFunctionNames().size();
        size_t numBaseTransferFunctions =
                evaluationParameter.getBaseTransferFunctionNames().size();
        size_t arity = evaluationParameter.getTransferFunctionArity();
        size_t abstractDomainLength = evaluationParameter.getAbstractDomainLength();
        llvm::errs() << "Evaluate on external data with arity " << arity << "\n";
        ConcreteOperation concreteOperation = evaluationBatch.getConcreteFunction();
        BinaryAbstractFunction meet = evaluationBatch.getMeet();
        DistanceFunction distanceFunction = evaluationBatch.getDistance();
        ContainsFunction contains = evaluationBatch.getContainsFunction();
        AbstractOpConstraint abstractOpConstraint =
                evaluationBatch.getAbstractOpConstraint();
        ConstantAbstractFunction getTop = evaluationBatch.getGetTop();
        bool trivialAbstractOpConstraint =
                evaluationBatch.isTrivialAbstractOpConstraint();
        llvm::APInt distanceResult, baseDistanceResult;

        auto &transferFunctions = evaluationBatch.getTransferFunctions();
        auto &baseTransferFunctions = evaluationBatch.getBaseTransferFunctions();
        bool baseTransferFunctionsNonEmpty = !baseTransferFunctions.empty();
        for (const auto &[bitWidth, dataPoints]: dataSet) {
            EvaluationResult result(numTransferFunctions);
            if (auto it = finalResult.find(bitWidth);it != finalResult.end()) {
                result = it->second;
            }
            llvm::errs() << "Evaluate current bitwidth " << bitWidth << "\n";
            llvm::errs() << "Data pair size: " << dataPoints.size() << "\n";

            std::vector<AbstractValue> transferResult(numTransferFunctions,
                                                      AbstractValue(abstractDomainLength));
            std::vector<AbstractDomain> args(arity, nullptr);
            AbstractDomain bestResult = nullptr;


            AbstractValue baseResult(abstractDomainLength), tmpResult(abstractDomainLength);
            unsigned baseDistance;
            bool solved;
            int cnt = 0;

            auto evalOnce = [&](const std::vector<AbstractValue> &dataPoint) {
                if (baseTransferFunctionsNonEmpty) {
                    baseTransferFunctions[0](args.data(), baseResult.data());
                    for (int i = 1; i < numBaseTransferFunctions; ++i) {
                        baseTransferFunctions[i](args.data(), tmpResult.data());
                        meet(baseResult.data(), tmpResult.data(), baseResult.data());
                    }
                } else {
                    getTop(args[0], baseResult.data());
                }
                distanceFunction(baseResult.data(), bestResult,
                                 &baseDistanceResult);
                baseDistance = baseDistanceResult.getZExtValue();
                solved = (baseResult == dataPoint.back());
                result.addBaseResult(solved, baseDistance);

#pragma omp parallel for schedule(dynamic)
                for (int i = 0; i < numTransferFunctions; ++i) {
                    transferFunctions[i](args.data(), transferResult[i].data());
                    meet(baseResult.data(), transferResult[i].data(),
                         transferResult[i].data());
                }

                for (int i = 0; i < numTransferFunctions; ++i) {
                    // update result for all transfer functions
                    int sound;
                    contains(transferResult[i].data(), bestResult, &sound);
                    bool exact = (transferResult[i] == dataPoint.back());
                    distanceFunction(transferResult[i].data(), bestResult,
                                     &distanceResult);
                    unsigned distance = distanceResult.getZExtValue();
                    unsigned soundDistance = sound ? distance : baseDistance;
                    result.addIthResult(i, sound, exact, solved, distance, soundDistance);
                }
                ++cnt;
            };

            if (trivialAbstractOpConstraint) {
                for (const auto &dataPoint: dataPoints) {
                    for (int i = 0; i < dataPoint.size() - 1; ++i) {
                        args[i] = const_cast<AbstractDomain >(dataPoint[i].data());
                    }
                    bestResult = const_cast<AbstractDomain >(dataPoint.back().data());
                    evalOnce(dataPoint);
                }
            } else {
                int abstractOpConstraintResult = 1;
                for (const auto &dataPoint: dataPoints) {
                    for (int i = 0; i < dataPoint.size() - 1; ++i) {
                        args[i] = const_cast<AbstractDomain >(dataPoint[i].data());
                    }
                    bestResult = const_cast<AbstractDomain >(dataPoint.back().data());

                    abstractOpConstraint(args.data(), &abstractOpConstraintResult);
                    if (abstractOpConstraintResult) {
                        evalOnce(dataPoint);
                    }
                }
            }


            if (auto it = finalResult.find(bitWidth);it != finalResult.end()) {
                it->second = result;
            } else {
                finalResult.emplace(bitWidth, result);
            }
        }
    }
} // namespace Evaluation