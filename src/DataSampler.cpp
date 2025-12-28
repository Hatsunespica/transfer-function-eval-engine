#include "DataSampler.h"
#include <filesystem>
#include <cassert>
#include <iostream>
#include <fstream>

namespace Evaluation {

DataSampler::DataSampler(const EvaluationParameter& evaluationParameter):
    dataCachePath(evaluationParameter.getDataCachePath()),
    domain(evaluationParameter.getDomain()),
    concreteDomainLength(evaluationParameter.getConcreteDomainLength()),
    abstractDomainLength(evaluationParameter.getAbstractDomainLength()){

    using namespace std::filesystem;
    assert(exists(dataCachePath) && is_directory(dataCachePath));
};


std::filesystem::path DataSampler::getDataPath(size_t bitWidth) const {
    auto newPath = dataCachePath / domain / std::to_string(bitWidth);
    if (!exists(newPath)) {
        create_directories(newPath);
    }
    assert(is_directory(newPath));
    return newPath;
}

void DataSampler::saveData(std::vector<AbstractConcreteValuePair>& data, size_t bitWidth) const {
    auto dataPath = getDataPath(bitWidth) / DATA_FILE_NAME;
    std::ofstream fout(dataPath, std::ios::binary);

    size_t count=data.size();
    assert (count>0);
    fout.write((char*)&count, sizeof(size_t));

    size_t concreteValueLength = data[0].getConcreteValues().size();
    fout.write((char*)&concreteValueLength, sizeof(size_t));
    assert(concreteValueLength>0);

    uint64_t tmp;
    for (const auto& abstractValuePair : data) {
        for (const auto& apInt: abstractValuePair.getAbstractValue()) {
            tmp = apInt.getZExtValue();
            fout.write((char*)&tmp, sizeof(uint64_t));
        }
        for (const auto& concreteValue: abstractValuePair.getConcreteValues()) {
            tmp=concreteValue.getZExtValue();
            fout.write((char*)&tmp, sizeof(uint64_t));
        }
    }
}

std::vector<AbstractConcreteValuePair> DataSampler::loadData(size_t bitWidth) {
    auto dataPath = getDataPath(bitWidth) / DATA_FILE_NAME;
    std::ifstream fin(dataPath, std::ios::binary);

    size_t count, concreteValueLength;
    fin.read((char*)&count, sizeof(size_t));
    fin.read((char*)&concreteValueLength, sizeof(size_t));
    assert(count>0);
    assert(concreteValueLength>0);

    uint64_t tmp;
    APInt tmpAPInt(bitWidth, 0);
    AbstractValue tmpAbstractValue;
    std::vector<ConcreteValue> tmpConcreteValues;

    std::vector<AbstractConcreteValuePair> result;
    result.reserve(count);
    for (size_t i=0;i<count;i++) {
        for (size_t j=0;j<abstractDomainLength;++j) {
            fin.read((char*)&tmp, sizeof(uint64_t));
            tmpAbstractValue.emplace_back(bitWidth, tmp);
        }
        for (size_t j=0;j<concreteValueLength;++j) {
            fin.read((char*)&tmp, sizeof(uint64_t));
            tmpConcreteValues.emplace_back(bitWidth, tmp);
        }
        result.emplace_back(tmpAbstractValue, tmpConcreteValues);
        tmpAbstractValue.clear();
        tmpConcreteValues.clear();
    }

    return result;
}

std::vector<AbstractConcreteValuePair> DataSampler::getData(size_t bitWidth) {

}
}

