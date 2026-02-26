#include "EvaluationParameter.h"
#include <cassert>
#include <fstream>
#include <iostream>

namespace Evaluation {
    void SampleParameter::saveToFile(std::fstream &fout) const {
        size_t policy = samplePolicy;
        fout.write((char *) &policy, sizeof(size_t));
        fout.write((char *) &randomSeed, sizeof(size_t));
        fout.write((char *) &numConcreteSamples, sizeof(size_t));
        fout.write((char *) &numAbstractSamples, sizeof(size_t));
    }

    SampleParameter SampleParameter::loadFromFile(std::fstream &fin) {
        size_t policy, randomSeed, numConcreteSamples, numAbstractSamples;
        fin.read((char *) &policy, sizeof(size_t));
        fin.read((char *) &randomSeed, sizeof(size_t));
        fin.read((char *) &numConcreteSamples, sizeof(size_t));
        fin.read((char *) &numAbstractSamples, sizeof(size_t));
        return SampleParameter((SamplePolicy) policy, randomSeed, numConcreteSamples,
                               numAbstractSamples);
    }

    EvaluationParameter::EvaluationParameter(
            const std::string &dataCachePath,
            const std::string &abstractValueCacheName,
            const std::vector<std::string> &transferFunctionNames,
            const std::vector<std::string> &baseTransferFunctionNames,
            const size_t &maxOperationLength, const std::string &domain,
            const size_t &concreteDomainLength, const size_t &abstractDomainLength,
            const size_t &transferFunctionArity,
            const std::vector<size_t> &enumerateBitWidth,
            const std::vector<size_t> &sampleBitWidth,
            const std::vector<size_t> &sampleAbstractAmount,
            const std::vector<size_t> &sampleConcreteAmount, const size_t &randomSeed)
            : dataCachePath(dataCachePath), abstractValueCacheName(abstractValueCacheName),
              transferFunctionNames(transferFunctionNames),
              baseTransferFunctionNames(baseTransferFunctionNames),
              maxOperationLength(maxOperationLength), domain(domain),
              concreteDomainLength(concreteDomainLength),
              abstractDomainLength(abstractDomainLength),
              transferFunctionArity(transferFunctionArity),
              enumerateBitWidth(enumerateBitWidth), sampleBitWidth(sampleBitWidth),
              sampleAbstractAmount(sampleAbstractAmount),
              sampleConcreteAmount(sampleConcreteAmount), randomSeed(randomSeed) {

        for (size_t bitWidth: enumerateBitWidth) {
            bitWidthToSampleParameter.emplace(
                    bitWidth, SampleParameter(SamplePolicy::FULL_ENUMERATION, randomSeed));
        }

        assert(sampleBitWidth.size() == sampleAbstractAmount.size() &&
               sampleBitWidth.size() == sampleConcreteAmount.size());

        for (size_t i = 0; i < sampleBitWidth.size(); ++i) {
            if (sampleAbstractAmount[i] == 0) {
                bitWidthToSampleParameter.emplace(
                        sampleBitWidth[i],
                        SampleParameter(SamplePolicy::SAMPLE_CONCRETE, randomSeed,
                                        sampleConcreteAmount[i]));
            } else {
                bitWidthToSampleParameter.emplace(
                        sampleBitWidth[i],
                        SampleParameter(SamplePolicy::SAMPLE_ABSTRACT_AND_CONCRETE,
                                        randomSeed, sampleAbstractAmount[i],
                                        sampleConcreteAmount[i]));
            }
        }
    }
} // namespace Evaluation
