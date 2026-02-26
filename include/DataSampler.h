#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H

#include "EvaluationBatch.h"
#include <filesystem>
#include <unordered_map>

namespace Evaluation {

class AbstractConcreteValuePair {
    AbstractValue abstractValue;
    std::vector<ConcreteValue> concreteValues;

public:
    // Constructor
    AbstractConcreteValuePair(
        const AbstractValue& abstractValue,
        const std::vector<ConcreteValue>& concreteValues)
        : abstractValue(abstractValue),
          concreteValues(concreteValues) {}

    // Getters
    const AbstractValue& getAbstractValue() const {
        return abstractValue;
    }

    const std::vector<ConcreteValue>& getConcreteValues() const {
        return concreteValues;
    }
};

enum SamplePolicy {
    FULL_ENUMERATION,
    SAMPLE_CONCRETE,
    SAMPLE_ABSTRACT_AND_CONCRETE
};

class SampleParameter {
    SamplePolicy samplePolicy;
    size_t randomSeed;
    size_t numConcreteSamples;
    size_t numAbstractSamples;


public:
    explicit SampleParameter(SamplePolicy samplePolicy,
                    size_t randomSeed = 0,
                    size_t numConcreteSamples = 0,
                    size_t numAbstractSamples = 0)
        : samplePolicy(samplePolicy),
          randomSeed(randomSeed),
          numConcreteSamples(numConcreteSamples),
          numAbstractSamples(numAbstractSamples){}


    const SamplePolicy& getSamplePolicy() const {
        return samplePolicy;
    }

    const size_t& getNumConcreteSamples() const {
        return numConcreteSamples;
    }

    const size_t& getNumAbstractSamples() const {
        return numAbstractSamples;
    }

    const size_t& getRandomSeed()const{
        return randomSeed;
    }

    void saveToFile(std::ofstream& fout)const;

    static SampleParameter loadFromFile(std::ifstream& fin);

    static bool matchSampleParameter(const std::filesystem::path& path, const SampleParameter& sampleParameter);

    bool operator==(const SampleParameter& s)const{
        return samplePolicy == s.samplePolicy &&
               randomSeed == s.randomSeed &&
               numConcreteSamples == s.numConcreteSamples &&
               numAbstractSamples == s.numAbstractSamples;
    }
};



class DataSampler {
    const static inline std::string DATA_FILE_NAME="data";

    const std::filesystem::path dataCachePath;
    const size_t& maxOperationLength;
    const std::string& domain;
    const size_t& concreteDomainLength;
    const size_t& abstractDomainLength;
    std::unordered_map<size_t, SampleParameter> bitWidthToSampleParameter;
    std::filesystem::path getDataPath(size_t bitWidth) const;
    std::filesystem::path getDataFilePath(size_t bitWidth) const;

    AbstractDomainConstraint abstractDomainConstraint;
    InstanceConstraint instanceConstraint;

    void saveData(const std::filesystem::path& path, std::vector<AbstractConcreteValuePair>& data, size_t bitWidth) const;
    std::vector<AbstractConcreteValuePair> loadData(const std::filesystem::path& path, size_t bitWidth)const;
    std::vector<AbstractConcreteValuePair> sampleData(size_t bitWidth)const;

    AbstractValue initAbstractValue(size_t bitWidth)const;
    bool nextAbstractValue(AbstractValue& abstractValue)const;
    std::vector<ConcreteValue> sampleConcreteValues(AbstractValue& abstractValue, size_t bitWidth)const;
public:
    DataSampler(const EvaluationParameter& evaluationParameter, const EvaluationBatch& evaluationBatch);
    std::vector<AbstractConcreteValuePair> getData(size_t bitWidth);
    std::vector<std::vector<AbstractDomain>> getHistoryConterexamples(size_t bitwidth, size_t arity);
};

}



#endif //TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H