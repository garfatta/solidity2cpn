#ifndef SOL2CPN_HELENA_H2_
#define SOL2CPN_HELENA_H2_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "Utils.hpp"

using namespace std;

namespace LNA {

//reserved
const string ASSERT_TOKEN      = "assert";
const string AND_TOKEN         = "and";
const string CAPACITY_TOKEN    = "capacity";
const string CARD_TOKEN        = "card";
const string CASE_TOKEN        = "case";
const string CONSTANT_TOKEN    = "constant";
const string DEFAULT_TOKEN     = "default";
const string DESCRIPTION_TOKEN = "description";
const string DOM_TOKEN         = "dom";
const string ELSE_TOKEN        = "else";
const string EMPTY_TOKEN       = "empty";
const string ENUM_TOKEN        = "enum";
const string EPSILON_TOKEN     = "epsilon";
const string EXISTS_TOKEN      = "exists";
const string FOR_TOKEN         = "for";
const string FORALL_TOKEN      = "forall";
const string FUNCTION_TOKEN    = "function";
const string GUARD_TOKEN       = "guard";
const string IF_TOKEN          = "if";
const string IMPORT_TOKEN      = "import";
const string IN_TOKEN          = "in";
const string INIT_TOKEN        = "init";
const string INHIBIT_TOKEN     = "inhibit";
const string LET_TOKEN         = "let";
const string LIST_TOKEN        = "list";
const string MAX_TOKEN         = "max";
const string MIN_TOKEN         = "min";
const string MOD_TOKEN         = "mod";
const string MULT_TOKEN        = "mult";
const string NOT_TOKEN         = "not";
const string OF_TOKEN          = "of";
const string OR_TOKEN          = "or";
const string OUT_TOKEN         = "out";
const string PICK_TOKEN        = "pick";
const string PLACE_TOKEN       = "place";
const string PRED_TOKEN        = "pred";
const string PRINT_TOKEN       = "print";
const string PRIORITY_TOKEN    = "priority";
const string PROPOSITION_TOKEN = "proposition";
const string PRODUCT_TOKEN     = "product";
const string RANGE_TOKEN       = "range";
const string RETURN_TOKEN      = "return";
const string STRUCT_TOKEN      = "struct";
const string SAFE_TOKEN        = "safe";
const string SET_TOKEN         = "set";
const string SUBTYPE_TOKEN     = "subtype";
const string SUCC_TOKEN        = "succ";
const string SUM_TOKEN         = "sum";
const string TRANSITION_TOKEN  = "transition";
const string TYPE_TOKEN        = "type";
const string VECTOR_TOKEN      = "vector";
const string WHILE_TOKEN       = "while";
const string WITH_TOKEN        = "with";
const list<string> ReservedTokensList {
    ASSERT_TOKEN,
    AND_TOKEN,
    CAPACITY_TOKEN,
    CARD_TOKEN,
    CASE_TOKEN,
    CONSTANT_TOKEN,
    DEFAULT_TOKEN,
    DESCRIPTION_TOKEN,
    DOM_TOKEN,
    ELSE_TOKEN,
    EMPTY_TOKEN,
    ENUM_TOKEN,
    EPSILON_TOKEN,
    EXISTS_TOKEN,
    FOR_TOKEN,
    FORALL_TOKEN,
    FUNCTION_TOKEN,
    GUARD_TOKEN,
    IF_TOKEN,
    IMPORT_TOKEN,
    IN_TOKEN,
    INIT_TOKEN,
    INHIBIT_TOKEN,
    LET_TOKEN,
    LIST_TOKEN,
    MAX_TOKEN,
    MIN_TOKEN,
    MOD_TOKEN,
    MULT_TOKEN,
    NOT_TOKEN,
    OF_TOKEN,
    OR_TOKEN,
    OUT_TOKEN,
    PICK_TOKEN,
    PLACE_TOKEN,
    PRED_TOKEN,
    PRINT_TOKEN,
    PRIORITY_TOKEN,
    PROPOSITION_TOKEN,
    PRODUCT_TOKEN,
    RANGE_TOKEN,
    RETURN_TOKEN,
    STRUCT_TOKEN,
    SAFE_TOKEN,
    SET_TOKEN,
    SUBTYPE_TOKEN,
    SUCC_TOKEN,
    SUM_TOKEN,
    TRANSITION_TOKEN,
    TYPE_TOKEN,
    VECTOR_TOKEN,
    WHILE_TOKEN,
    WITH_TOKEN
};
//net
const string Net_Token = "Net";
//parameters
const string Net_Param_Token = "Net_Param";
//colors
const string Color_Token = "Color";
const string Range_Color_Token = "Range_Color";
const string Mod_Color_Token = "Mod_Color";
const string Enum_Color_Token = "Enum_Color";
const string Vector_Color_Token = "Vector_Color";
const string Struct_Color_Token = "Struct_Color";
const string Component_Token = "Component";
const string List_Color_Token = "List_Color";
const string Set_Color_Token = "Set_Color";
const string Sub_Color_Token = "Sub_Color";
//const list<string> ColorsTokensList{};
//functions
const string Func_Prot_Token = "Func_Prot";
const string Func_Token = "Func";
const string Param_Token = "Param";
const string Var_Decl_Token = "Var_Decl";
//const list<string> FunctionsTokensList{};
//expressions
const string Num_Const_Token = "Num_Const";
const string Func_Call_Token = "Func_Call";
const string Vector_Access_Token = "Vector_Access";
const string Struct_Access_Token = "Struct_Access";
const string Bin_Op_Token = "Bin_Op";
const string Un_Op_Token = "Un_Op";
const string Vector_Aggregate_Token = "Vector_Aggregate";
const string Vector_Assign_Token = "Vector_Assign";
const string Struct_Aggregate_Token = "Struct_Aggregate";
const string Struct_Assign_Token = "Struct_Assign";
const string Symbol_Token = "Symbol";
const string Iterator_Token = "Iterator";
const string Tuple_Access_Token = "Tuple_Access";
const string Attribute_Token = "Attribute";
const string Container_Aggregate_Token = "Container_Aggregate";
const string Empty_Token = "Empty";
const string List_Slice_Token = "List_Slice";
//const list<string> ExpressionsTokensList{};
//iterator types
const string card_iterator_Token = "card_iterator";
const string mult_iterator_Token = "mult_iterator";
const string forall_iterator_Token = "forall_iterator";
const string exists_iterator_Token = "exists_iterator";
const string max_iterator_Token = "max_iterator";
const string min_iterator_Token = "min_iterator";
const string sum_iterator_Token = "sum_iterator";
const string product_iterator_Token = "product_iterator";
//const list<string> IteratorTypesTokensList{};
//unary operators
const string Pred_Op_Token = "Pred_Op";
const string Succ_Op_Token = "Succ_Op";
const string Plus_Op_Token = "Plus_Op";
const string Minus_Op_Token = "Minus_Op";
const string Not_Op_Token = "Not_Op";
//const list<string> UnaryOperatorsTokensList{};
//binary operators
const string Mult_Op_Token = "Mult_Op";
const string Div_Op_Token = "Div_Op";
const string Mod_Op_Token = "Mod_Op";
const string And_Op_Token = "And_Op";
const string Or_Op_Token = "Or_Op";
const string Sup_Op_Token = "Sup_Op";
const string Sup_Eq_Op_Token = "Sup_Eq_Op";
const string Inf_Op_Token = "Inf_Op";
const string Inf_Eq_Op_Token = "Inf_Eq_Op";
const string Eq_Op_Token = "Eq_Op";
const string Neq_Op_Token = "Neq_Op";
const string Amp_Op_Token = "Amp_Op";
const string In_Op_Token = "In_Op";
//const list<string> BinaryOperatorsTokensList{};
//statements
const string Assign_Token = "Assign";
const string If_Then_Else_Token = "If_Then_Else";
const string Case_Stat_Token = "Case_Stat";
const string Case_Alternative_Token = "Case_Alternative";
const string While_Stat_Token = "While_Stat";
const string Print_Stat_Token = "Print_Stat";
const string Return_Stat_Token = "Return_Stat";
const string For_Stat_Token = "For_Stat";
const string Block_Stat_Token = "Block_Stat";
//const list<string> StatementsTokensList{};
//places
const string Place_Token = "Place";
const string Place_Init_Token = "Place_Init";
const string Place_Capacity_Token = "Place_Capacity";
const string Place_Type_Token = "Place_Type";
//const list<string> PlacesTokensList{};
//transitions
const string Transition_Token = "Transition";
const string Transition_Description_Token = "Transition_Description";
const string Transition_Guard_Token = "Transition_Guard";
const string Transition_Priority_Token = "Transition_Priority";
const string Transition_Safe_Token = "Transition_Safe";
//const list<string> TransitionsokensList{};
//mappings
const string Arc_Token = "Arc";
const string Mapping_Token = "Mapping";
const string Tuple_Token = "Tuple";
const string Simple_Tuple_Token = "Simple_Tuple";
//const list<string> MappingsTokensList{};
//propositions
const string Proposition_Token = "Proposition";
//others
const string Assert_Token = "Assert";
const string Iter_Variable_Token = "Iter_Variable";
const string Low_High_Range_Token = "Low_High_Range";
const string Name_Token = "Name";
const string A_String_Token = "A_String";
const string Number_Token = "Number";
const string List_Token = "List";
//const list<string> OthersTokensList{};

enum NodeType {
    NodeTypeNet,
    NodeTypeNet_Param,
    NodeTypeColor,
    NodeTypeRange_Color,
    NodeTypeMod_Color,
    NodeTypeEnum_Color,
    NodeTypeVector_Color,
    NodeTypeStruct_Color,
    NodeTypeComponent,
    NodeTypeListColor,
    NodeTypeSet_Color,
    NodeTypeSub_Color,
    NodeTypeFunc_Prot,
    NodeTypeFunc,
    NodeTypeParam,
    NodeTypeVar_Decl,
    NodeTypeNum_Const,
    NodeTypeFunc_Call,
    NodeTypeVector_Access,
    NodeTypeStruct_Access,
    NodeTypeBin_Op,
    NodeTypeUn_Op,
    NodeTypeVector_Aggregate,
    NodeTypeVector_Assign,
    NodeTypeStruct_Aggregate,
    NodeTypeStruct_Assign,
    NodeTypeSymbol,
    NodeTypeIterator,
    NodeTypeTuple_Access,
    NodeTypeAttribute,
    NodeTypeContainer_Aggregate,
    NodeTypeEmpty,
    NodeTypeList_Slice,
    NodeTypecard_iterator,
    NodeTypemult_iterator,
    NodeTypeforall_iterator,
    NodeTypeexists_iterator,
    NodeTypemax_iterator,
    NodeTypemin_iterator,
    NodeTypesum_iterator,
    NodeTypeproduct_iterator,
    NodeTypePred_Op,
    NodeTypeSucc_Op,
    NodeTypePlus_Op,
    NodeTypeMinus_Op,
    NodeTypeNot_Op,
    NodeTypeMult_Op,
    NodeTypeDiv_Op,
    NodeTypeMod_Op,
    NodeTypeAnd_Op,
    NodeTypeOr_Op,
    NodeTypeSup_Op,
    NodeTypeSup_Eq_Op,
    NodeTypeInf_Op,
    NodeTypeInf_Eq_Op,
    NodeTypeEq_Op,
    NodeTypeNeq_Op,
    NodeTypeAmp_Op,
    NodeTypeIn_Op,
    NodeTypeAssign,
    NodeTypeIf_Then_Else,
    NodeTypeCase_Stat,
    NodeTypeCase_Alternative,
    NodeTypeWhile_Stat,
    NodeTypePrint_Stat,
    NodeTypeReturn_Stat,
    NodeTypeFor_Stat,
    NodeTypeBlock_Stat,
    NodeTypePlace,
    NodeTypePlace_Init,
    NodeTypePlace_Capacity,
    NodeTypePlace_Type,
    NodeTypeTransition,
    NodeTypeTransition_Description,
    NodeTypeTransition_Guard,
    NodeTypeTransition_Priority,
    NodeTypeTransition_Safe,
    NodeTypeArc,
    NodeTypeMapping,
    NodeTypeTuple,
    NodeTypeSimple_Tuple,
    NodeTypeProposition,
    NodeTypeAssert,
    NodeTypeIter_Variable,
    NodeTypeLow_High_Range,
    NodeTypeName,
    NodeTypeA_String,
    NodeTypeNumber,
    NodeTypeList
};

class LnaNode;
typedef shared_ptr<LnaNode> LnaNodePtr;

class LnaNode {
public:
    explicit LnaNode(NodeType _node_type) : node_type(_node_type), text_before(""), text_after("") {}
    virtual std::string source_code() = 0;
    NodeType get_node_type() const;
    size_t size();
    void insert_text_before(const std::string& _text);
    void insert_text_after(const std::string& _text);
    std::string get_added_text_before() const;
    std::string get_added_text_after() const;
protected:
    void append_sub_node(const LnaNodePtr& _node);
    void delete_sub_node(const unsigned int& x);
    void update_sub_node(const unsigned int& x, const LnaNodePtr _node);
    LnaNodePtr get_sub_node(const unsigned int& x) const;
    LnaNodePtr operator[] (const unsigned int& x);

    NodeType node_type;
    std::vector<LnaNodePtr> lna_nodes;
    std::string text_before;
    std::string text_after;
};

class NetNode : public LnaNode {
public:
    NetNode() : LnaNode(NodeTypeNet) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void add_member(const LnaNodePtr& _node);
    void delete_member(const unsigned int& x);
    void update_member(const unsigned int& x, const LnaNodePtr& _node);
    LnaNodePtr get_member(const unsigned int& x);
    size_t num_members();

    LnaNodePtr operator[] (const unsigned int& x);
private:
    std::string name;
};
typedef std::shared_ptr<NetNode> NetNodePtr;

class NetNode : public LnaNode {
public:
    NetNode() : LnaNode(NodeTypeNet) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void add_member(const LnaNodePtr& _node);
    void delete_member(const unsigned int& x);
    void update_member(const unsigned int& x, const LnaNodePtr& _node);
    LnaNodePtr get_member(const unsigned int& x);
    size_t num_members();
    
    LnaNodePtr operator[] (const unsigned int& x);
private:
    std::string name;
};
typedef std::shared_ptr<NetNode> NetNodePtr;
}

#endif //HELENA_H2_
