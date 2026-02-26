#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H

#include "EvaluationBatch.h"

namespace Evaluation {

    class AbstractConcreteValuePair {
        AbstractValue abstractValue;
        std::vector<ConcreteValue> concreteValues;

    public:
        // Constructor
        AbstractConcreteValuePair(const AbstractValue &abstractValue,
                                  const std::vector<ConcreteValue> &concreteValues)
                : abstractValue(abstractValue), concreteValues(concreteValues) {}

        // Getters
        const AbstractValue &getAbstractValue() const { return abstractValue; }

        const std::vector<ConcreteValue> &getConcreteValues() const {
            return concreteValues;
        }
    };

    class DataSampler {
        const static inline std::string DATA_FILE_NAME = "data";

        const std::filesystem::path dataCachePath;
        const size_t &maxOperationLength;
        const std::string &domain;
        const size_t &concreteDomainLength;
        const size_t &abstractDomainLength;
        const std::unordered_map<size_t, SampleParameter> &bitWidthToSampleParameter;

        std::filesystem::path getDataPath(size_t bitWidth) const;

        std::filesystem::path getDataFilePath(size_t bitWidth) const;

        AbstractDomainConstraint abstractDomainConstraint;
        InstanceConstraint instanceConstraint;

        void saveData(const std::filesystem::path &path,
                      std::vector<AbstractConcreteValuePair> &data,
                      size_t bitWidth) const;

        std::vector<AbstractConcreteValuePair>
        loadData(const std::filesystem::path &path, size_t bitWidth) const;

        std::vector<AbstractConcreteValuePair> sampleData(size_t bitWidth) const;

        AbstractValue initAbstractValue(size_t bitWidth) const;

        bool nextAbstractValue(AbstractValue &abstractValue) const;

        std::vector<ConcreteValue> sampleConcreteValues(AbstractValue &abstractValue,
                                                        size_t bitWidth) const;

    public:
        DataSampler(const EvaluationParameter &evaluationParameter,
                    const EvaluationBatch &evaluationBatch);

        std::vector<AbstractConcreteValuePair> getData(size_t bitWidth);

        std::vector<std::vector<AbstractDomain>>
        getHistoryConterexamples(size_t bitwidth, size_t arity);
    };

} // namespace Evaluation

#endif // TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H