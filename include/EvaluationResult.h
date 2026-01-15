#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONRESULT_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONRESULT_H

#include "EvaluationParameter.h"

namespace Evaluation {

class TransferFunctionResult {
    size_t soundCases;
    size_t exactCases;
    size_t unsolvedExactCases;
    size_t distance;
    size_t soundDistance;

public:
    TransferFunctionResult(bool isSound=false,
                     bool isExact=false,
                     bool isSolved=false,
                     size_t distance = 0,
                     size_t soundDistance = 0)
        : soundCases(isSound),
          exactCases(isExact),
          distance(distance),
          soundDistance(soundDistance) {
        unsolvedExactCases = isSolved ? isExact : 0;
    }

    void addResult(bool isSound, bool isExact, bool isSolved, size_t distance, size_t soundDistance) {
        soundCases += isSound;
        exactCases += isExact;
        this->distance += distance;
        this->soundDistance += soundDistance;
        unsolvedExactCases += (isSolved ? isExact : 0);
    }
};

class EvaluationResult {
    std::vector<TransferFunctionResult> transferFunctionResults;
    size_t baseDistance;
    size_t baseUnsolvedCases;
public:
    EvaluationResult(size_t numberOfTransferFunctions=0) {
        transferFunctionResults.resize(numberOfTransferFunctions);
        baseDistance=0;
        baseUnsolvedCases=0;
    }

    void addIthResult(size_t i, bool isSound, bool isExact, bool isSolved, size_t distance, size_t soundDistance) {
        transferFunctionResults[i].addResult(isSound, isExact, isSolved, distance, soundDistance);
    }

    void addBaseResult(bool solved, size_t baseDiatance) {
        baseUnsolvedCases += solved? 0 : 1;
        this->baseDistance += baseDiatance;
    }
};

}



#endif //TRANSFER_FUNCTION_EVAL_ENGINE_EVALUATIONRESULT_H