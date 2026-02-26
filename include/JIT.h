#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_JIT_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_JIT_H

#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include <memory>
#include <string>
#include <vector>

std::pair<bool, std::string>
compile(const std::string &fileName,
        const std::vector<std::string> &compileArgs, const std::string &source);

std::unique_ptr<llvm::orc::LLJIT>
createJITModule(const std::string &fileName,
                const std::vector<std::string> &compileArgs,
                const std::string &source);

#endif // TRANSFER_FUNCTION_EVAL_ENGINE_JIT_H
