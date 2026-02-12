#include "EvaluationResult.h"
#include "llvm/Support/raw_ostream.h"

namespace Evaluation {
    void TransferFunctionResult::print() const {
        llvm::errs() << "soundCases = " << soundCases << "\n";
        llvm::errs() << "exactCases = " << exactCases << "\n";
        llvm::errs() << "unsolvedExactCases = " << unsolvedExactCases << "\n";
        llvm::errs() << "distance = " << distance << "\n";
        llvm::errs() << "soundDistance = " << soundDistance << "\n";

    }

    void EvaluationResult::print() const {
        llvm::errs()<<"Total cases: "<<numCases<<"\n";
        llvm::errs()<<"Total unsolved cases: "<<baseUnsolvedCases<<"\n";
        llvm::errs()<<"Base distance: "<<baseDistance<<"\n";
        for (const auto& result:transferFunctionResults) {
            result.print();
            llvm::errs()<<"------\n";
        }
    }

    void printEvaluationResultOnAllBitWidth(const EvaluationResultOnBitWidth& result) {
       llvm::errs()<<"print result\n";
        for (const auto& it : result) {
            llvm::errs()<<"BitWidth: "<<it.first<<"\n";
            it.second.print();
            llvm::errs()<<"=======\n";
        }
    }
}
