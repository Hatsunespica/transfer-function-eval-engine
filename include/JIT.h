#ifndef TRANSFER_FUNCTION_EVAL_ENGINE_JIT_H
#define TRANSFER_FUNCTION_EVAL_ENGINE_JIT_H
#include<string>
#include <vector>

std::pair<bool, std::string> compile(const std::string& fileName,
                                     const std::vector<std::string>& compileArgs,
                                     const std::string& source);

#endif //TRANSFER_FUNCTION_EVAL_ENGINE_JIT_H
