#ifndef SOL2CPN_TRANSLATOR_H_
#define SOL2CPN_TRANSLATOR_H_

/*#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

*/
#include <json.hpp>
#include "Helena.hpp"
#include "ASTNodes.hpp"

namespace SOL2CPN {

class Translator {
public:
    Translator(RootNodePtr _rootNode) : rootNode(_rootNode) {}
    NetNodePtr translate();

private:
RootNodePtr rootNode;
NetNodePtr net;

void generatePredefinedColors();
void generateUserBehaviourColors();
StructColorNodePtr translateStruct(StructDefinitionNodePtr struct_node);
ListColorNodePtr translateMapping(ASTNodePtr _node);

};

}

#endif //SOL2CPN_TRANSLATOR_H_
