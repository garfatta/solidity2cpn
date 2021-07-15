#ifndef SOL2CPN_CONSTANTS_H_
#define SOL2CPN_CONSTANTS_H_

namespace SOL2CPN {
namespace ErrorCode {
    const int SUCCESS = 0;
    const int COMMAND_LINE_ARGUMENTS_ERROR = 1;
    const int TEXT_AST_FILE_NOT_PROVIDED = 2;
    const int JSON_AST_FILE_NOT_PROVIDED = 3;
    const int ABI_FILE_NOT_PROVIDED = 4;
    const int ORIGINAL_CONTRACT_NAME_NOT_PROVIDED = 5;
    const int OUTPUT_FILE_NAME_NOT_PROVIDED = 6;
}
}

#endif //SOL2CPN_CONSTANTS_H_