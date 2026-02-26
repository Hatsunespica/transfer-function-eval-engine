#include "EvaluationResult.h"
#include "llvm/Support/raw_ostream.h"

namespace Evaluation {
    void TransferFunctionResult::print() const {
        llvm::outs() << "soundCases = " << soundCases << "\n";
        llvm::outs() << "exactCases = " << exactCases << "\n";
        llvm::outs() << "unsolvedExactCases = " << unsolvedExactCases << "\n";
        llvm::outs() << "distance = " << distance << "\n";
        llvm::outs() << "soundDistance = " << soundDistance << "\n";
    }

    void EvaluationResult::print() const {
        llvm::outs() << "Total cases: " << numCases << "\n";
        llvm::outs() << "Total unsolved cases: " << baseUnsolvedCases << "\n";
        llvm::outs() << "Base distance: " << baseDistance << "\n";
        for (const auto &result: transferFunctionResults) {
            result.print();
            llvm::outs() << "------\n";
        }
    }

    void printEvaluationResultOnAllBitWidth(
            const EvaluationResultOnBitWidth &result) {
        llvm::outs() << "print result\n";
        for (const auto &it: result) {
            llvm::outs() << "BitWidth: " << it.first << "\n";
            it.second.print();
            llvm::outs() << "=======\n";
        }
    }
} // namespace Evaluation
