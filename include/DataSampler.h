#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H

#include "EvaluationTypes.h"
#include "EvaluationParameter.h"

namespace Evaluation {

class AbstractConcreteValuePair {
    AbstractDomain abstractValue;
    std::vector<ConcreteDomain> concreteValues;

public:
    // Constructor
    AbstractConcreteValuePair(
        AbstractDomain abstractValue,
        std::vector<ConcreteDomain> concreteValues)
        : abstractValue(std::move(abstractValue)),
          concreteValues(std::move(concreteValues)) {}

    // Getters
    const AbstractDomain& getAbstractValue() const {
        return abstractValue;
    }

    const std::vector<ConcreteDomain>& getConcreteValues() const {
        return concreteValues;
    }
};



class DataSampler {
    const std::string& dataCachePath;
    const std::string& domain;
public:
    DataSampler(const std::string& dataCachePath,
        const std::string& domain):dataCachePath(dataCachePath), domain(domain){};
    std::vector<AbstractConcreteValuePair> getData(size_t bitWidth);
    std::vector<std::vector<AbstractDomain>> getHistoryConterexamples(size_t bitwidth, size_t arity);
};

}



#endif //TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H