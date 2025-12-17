#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H

#include "EvaluationTypes.h"
#include <vector>

namespace Evaluation {

class DataSampler {
    public:
    DataSampler();
    std::vector<AbstractDomain> getAbstractValues(size_t bitwidth);
    std::vector<ConcreteDomain> getConcreteValues(size_t bitwidth);
    std::vector<std::vector<AbstractDomain>> getHistoryConterexamples(size_t bitwidth, size_t arity);
};

}



#endif //TRANSFER_FUNCTION_EVAL_ENGINE_DATASAMPLER_H