#ifndef SOL2CPN_ASTVISITOR_H_
#define SOL2CPN_ASTVISITOR_H_

#include "ASTNodes.hpp"

namespace SOL2CPN {
    void before(std::string arg = "");
    void visit(ASTNode* node);
    void after();
}

#endif //SOL2CPN_ASTVISITOR_H_