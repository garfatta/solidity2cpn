#include "include/Translator.hpp"
#include "include/Utils.hpp"
#include "include/ASTNodes.hpp"

namespace SOL2CPN {

NetNodePtr Translator::translate() {
    net = std::make_shared<NetNode>();
    
    for (int i = 0; i < rootNode->num_fields(); i++)
            if (rootNode->get_field(i)->get_node_type() == NodeTypeContractDefinition) {
                //create the net
                auto contractNode = std::static_pointer_cast<ContractDefinitionNode>(rootNode->get_field(i));
                net->set_name(contractNode->get_name());
                generatePredefinedColors();
                generateUserBehaviourColors();
                
                for (int i = 0; i < contractNode->num_members(); i++){
                    auto member = contractNode->get_member(i);
                    if (member->get_node_type() == NodeTypeStructDefinition) {
                        auto structNode = std::static_pointer_cast<StructDefinitionNode>(contractNode->get_member(i));
                        net->add_color(translateStruct(structNode));
                    }
                    else if (member->get_node_type() == NodeTypeVariableDeclaration) {
                        auto varNode = std::static_pointer_cast<VariableDeclarationNode>(member);
                        if (varNode->get_type()->get_node_type() == NodeTypeMapping) {
                            net->add_color(translateMapping(member));
                        }
                    }
                    else if (member->get_node_type() == NodeTypeFunctionDefinition) {
                        auto func = std::static_pointer_cast<FunctionDefinitionNode>(member);
                        //parameters are handled as variable declarations..
                        
                    }
                }
            }
    return net;
}

void Translator::generatePredefinedColors() {
    ColorNodePtr address (new ColorNode());
    address->set_name("ADDRESS");
    address->set_typeDef("range 0 .. 100");
    net->add_color(address);
    
    ColorNodePtr eth (new ColorNode());
    eth->set_name("ETH");
    eth->set_typeDef("range 0 .. 1000");
    net->add_color(eth);

    ColorNodePtr user (new ColorNode());
    user->set_name("USER");
    user->set_typeDef("struct { ADDRESS adr;ETH balance;}");
    net->add_color(user);
}

void Translator::generateUserBehaviourColors() {
    SubColorNodePtr bid_value (new SubColorNode(net->get_color_by_name("ETH")));
    bid_value->set_name("BID_VALUE");
    bid_value->set_typeDef("range 0 .. 25");
    net->add_color(bid_value);

    ColorNodePtr list_values (new ColorNode());
    list_values->set_name("LIST_VALUES");
    list_values->set_typeDef("list [nat] of BID_VALUE with capacity 100");
    net->add_color(list_values);

    ColorNodePtr blind_bid (new ColorNode());
    blind_bid->set_name("BLIND_BID");
    blind_bid->set_typeDef("range 0 .. 1000");
    net->add_color(blind_bid);

    ColorNodePtr list_bb (new ColorNode());
    list_bb->set_name("LIST_BB");
    list_bb->set_typeDef("list [nat] of BLIND_BID with capacity 100");
    net->add_color(list_bb);

    ColorNodePtr secret_key (new ColorNode());
    secret_key->set_name("SECRET_KEY");
    secret_key->set_typeDef("range 0 .. 100");
    net->add_color(secret_key);

    ColorNodePtr list_keys (new ColorNode());
    list_keys->set_name("LIST_KEYS");
    list_keys->set_typeDef("list [nat] of SECRET_KEY with capacity 100");
    net->add_color(list_keys);

    SubColorNodePtr deposit (new SubColorNode(net->get_color_by_name("ETH")));
    deposit->set_name("DEPOSIT");
    deposit->set_typeDef("range 0 .. 25");
    net->add_color(deposit);

    ColorNodePtr list_deposit (new ColorNode());
    list_deposit->set_name("LIST_DEPOSIT");
    list_deposit->set_typeDef("list [nat] of DEPOSIT with capacity 100");
    net->add_color(list_deposit);

    ColorNodePtr last_bid (new ColorNode());
    last_bid->set_name("LAST_BID");
    last_bid->set_typeDef("struct { ADDRESS bidder; ETH bidValue;}");
    net->add_color(last_bid);

    ColorNodePtr full_bid (new ColorNode());
    full_bid->set_name("FULL_BID");
    full_bid->set_typeDef("struct { ADDRESS bidder; BLIND_BID blindBid; ETH deposit; BID_VALUE revealedBid; SECRET_KEY secret;}");
    net->add_color(full_bid);

    ColorNodePtr full_bidder (new ColorNode());
    full_bidder->set_name("FULL_BIDDER");
    full_bidder->set_typeDef("struct { ADDRESS bidder; ETH balance; LIST_BB blindBids; LIST_DEPOSIT deposits; LIST_VALUES revealedBids; LIST_KEYS secrets;}");
    net->add_color(full_bidder);

    ColorNodePtr list_fb (new ColorNode());
    list_fb->set_name("LIST_FB");
    list_fb->set_typeDef("struct { ADDRESS bidder; LIST_BB blindBids; LIST_DEPOSIT deposits; LIST_VALUES revealedBids; LIST_KEYS secrets;}");
    net->add_color(list_fb);
}

StructColorNodePtr Translator::translateStruct(StructDefinitionNodePtr struct_node) {
    StructColorNodePtr struct_color = std::make_shared<StructColorNode>();
    struct_color->set_name(struct_node->get_name());
            
    for (int i = 0; i < struct_node->num_fields(); i++) {
        VariableDeclarationNodePtr variable = std::static_pointer_cast<VariableDeclarationNode>(struct_node->get_field(i));
        ComponentNodePtr component = std::make_shared<ComponentNode>();
        component->set_name(variable->get_variable_name());
        component->set_type(std::static_pointer_cast<ElementaryTypeNameNode>(variable->get_type())->get_type_name());
        struct_color->add_component(component);
    }
    return struct_color;
}

ListColorNodePtr Translator::translateMapping(ASTNodePtr _node) {
    ListColorNodePtr list_color = std::make_shared<ListColorNode>();
    StructColorNodePtr struct_color = std::make_shared<StructColorNode>();
    auto var_node = std::static_pointer_cast<VariableDeclarationNode>(_node);
    auto mapNode = std::static_pointer_cast<MappingNode>(var_node->get_type());
    struct_color->set_name("struct_" + var_node->get_variable_name());
    ComponentNodePtr key = std::make_shared<ComponentNode>();
    key->set_name("key");
    if (mapNode->get_key_type()->get_node_type() == NodeTypeElementaryTypeName) {
        auto key_type = std::static_pointer_cast<ElementaryTypeNameNode>(mapNode->get_key_type());
        key->set_type(key_type->get_type_name());
    }
    else {
        auto key_type = std::static_pointer_cast<UserDefinedTypeNameNode>(mapNode->get_key_type());
        key->set_type(key_type->get_type_name());
    }
    ComponentNodePtr value = std::make_shared<ComponentNode>();



    value->set_name("value");
    if (mapNode->get_value_type()->get_node_type() == NodeTypeElementaryTypeName) {
        auto value_type = std::static_pointer_cast<ElementaryTypeNameNode>(mapNode->get_value_type());
        value->set_type(value_type->get_type_name());
    }
    else if (mapNode->get_value_type()->get_node_type() == NodeTypeArrayTypeName) {
        auto value_type = std::static_pointer_cast<ArrayTypeNameNode>(mapNode->get_value_type());
        auto base_type = std::static_pointer_cast<UserDefinedTypeNameNode>(value_type->get_base_type());
        value->set_type(base_type->get_type_name()+"[]");
    }
    struct_color->add_component(key);
    struct_color->add_component(value);
    net->add_color(struct_color);
    list_color->set_name("list_"+ var_node->get_variable_name());
    list_color->set_index_type("nat");
    list_color->set_element_type(struct_color->get_name());
    list_color->set_capacity("100");

    return list_color;
}

}