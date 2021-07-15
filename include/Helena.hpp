#ifndef SOL2CPN_HELENA_H_
#define SOL2CPN_HELENA_H_

#include <algorithm>
//#include <fstream>
//#include <iostream>
#include <list>
//#include <map>
#include <memory>
#include <sstream>
//#include <string>
//#include <vector>

//#include "Utils.hpp"
#include <vector>

using namespace std;

namespace SOL2CPN {

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

enum LnaNodeType {
    LnaNodeTypeNet,
    LnaNodeTypeNet_Param,
    LnaNodeTypeColor,
    LnaNodeTypeRange_Color,
    LnaNodeTypeMod_Color,
    LnaNodeTypeEnum_Color,
    LnaNodeTypeVector_Color,
    LnaNodeTypeStruct_Color,
    LnaNodeTypeComponent,
    LnaNodeTypeListColor,
    LnaNodeTypeSet_Color,
    LnaNodeTypeSub_Color,
    //
    LnaNodeTypeConstant,
    //
    LnaNodeTypeFunc_Prot,
    LnaNodeTypeFunc,
    LnaNodeTypeParam,
    LnaNodeTypeVar_Decl,
    LnaNodeTypeNum_Const,
    LnaNodeTypeFunc_Call,
    LnaNodeTypeVector_Access,
    LnaNodeTypeStruct_Access,
    LnaNodeTypeBin_Op,
    LnaNodeTypeUn_Op,
    LnaNodeTypeVector_Aggregate,
    LnaNodeTypeVector_Assign,
    LnaNodeTypeStruct_Aggregate,
    LnaNodeTypeStruct_Assign,
    LnaNodeTypeSymbol,
    LnaNodeTypeIterator,
    LnaNodeTypeTuple_Access,
    LnaNodeTypeAttribute,
    LnaNodeTypeContainer_Aggregate,
    LnaNodeTypeEmpty,
    LnaNodeTypeList_Slice,
    LnaNodeTypecard_iterator,
    LnaNodeTypemult_iterator,
    LnaNodeTypeforall_iterator,
    LnaNodeTypeexists_iterator,
    LnaNodeTypemax_iterator,
    LnaNodeTypemin_iterator,
    LnaNodeTypesum_iterator,
    LnaNodeTypeproduct_iterator,
    LnaNodeTypePred_Op,
    LnaNodeTypeSucc_Op,
    LnaNodeTypePlus_Op,
    LnaNodeTypeMinus_Op,
    LnaNodeTypeNot_Op,
    LnaNodeTypeMult_Op,
    LnaNodeTypeDiv_Op,
    LnaNodeTypeMod_Op,
    LnaNodeTypeAnd_Op,
    LnaNodeTypeOr_Op,
    LnaNodeTypeSup_Op,
    LnaNodeTypeSup_Eq_Op,
    LnaNodeTypeInf_Op,
    LnaNodeTypeInf_Eq_Op,
    LnaNodeTypeEq_Op,
    LnaNodeTypeNeq_Op,
    LnaNodeTypeAmp_Op,
    LnaNodeTypeIn_Op,
    LnaNodeTypeAssign,
    LnaNodeTypeIf_Then_Else,
    LnaNodeTypeCase_Stat,
    LnaNodeTypeCase_Alternative,
    LnaNodeTypeWhile_Stat,
    LnaNodeTypePrint_Stat,
    LnaNodeTypeReturn_Stat,
    LnaNodeTypeFor_Stat,
    LnaNodeTypeBlock_Stat,
    LnaNodeTypePlace,
    LnaNodeTypePlace_Init,
    LnaNodeTypePlace_Capacity,
    LnaNodeTypePlace_Type,
    LnaNodeTypeTransition,
    LnaNodeTypeTransition_Description,
    LnaNodeTypeTransition_Guard,
    LnaNodeTypeTransition_Priority,
    LnaNodeTypeTransition_Safe,
    LnaNodeTypeArc,
    LnaNodeTypeMapping,
    LnaNodeTypeTuple,
    LnaNodeTypeSimple_Tuple,
    LnaNodeTypeProposition,
    LnaNodeTypeAssert,
    LnaNodeTypeIter_Variable,
    LnaNodeTypeLow_High_Range,
    LnaNodeTypeName,
    LnaNodeTypeA_String,
    LnaNodeTypeNumber,
    LnaNodeTypeList
};

class LnaNode;
typedef shared_ptr<LnaNode> LnaNodePtr;

class ColorNode;
typedef shared_ptr<ColorNode> ColorNodePtr;

class LnaNode {
public:
    explicit LnaNode(LnaNodeType _node_type) : node_type(_node_type) {}
    virtual std::string source_code() = 0;
    LnaNodeType get_node_type() const;
    size_t size();
    //void insert_text_before(const std::string& _text);
    //void insert_text_after(const std::string& _text);
    //std::string get_added_text_before() const;
    //std::string get_added_text_after() const;
protected:
    void append_sub_node(const LnaNodePtr& _node);
    void delete_sub_node(const unsigned int& x);
    void update_sub_node(const unsigned int& x, const LnaNodePtr _node);
    LnaNodePtr get_sub_node(const unsigned int& x) const;
    //LnaNodePtr operator[] (const unsigned int& x);

    LnaNodeType node_type;
    std::vector<LnaNodePtr> lna_nodes;
    //std::string text_before;
    //std::string text_after;
};

class ParameterNode : public LnaNode {
public:
    ParameterNode() : LnaNode(LnaNodeTypeNet_Param) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;
    void set_number(const std::string& _number);
    std::string get_number() const;
private:
    std::string name;
    std::string number;
};
typedef std::shared_ptr<ParameterNode> ParameterNodePtr;

class NetNode : public LnaNode {
public:
    NetNode() : LnaNode(LnaNodeTypeNet) {}
    NetNode(std::string _name) : LnaNode(LnaNodeTypeNet), name(_name) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void add_parameter(const ParameterNodePtr& _node);

    void add_member(const LnaNodePtr& _node);
    void delete_member(const unsigned int& x);
    void update_member(const unsigned int& x, const LnaNodePtr& _node);
    LnaNodePtr get_member(const unsigned int& x);
    size_t num_members();

    void add_color(const ColorNodePtr& _color);
    ColorNodePtr get_color_by_name(const string& _name);

private:
    std::string name;
    std::vector<ParameterNodePtr> param_nodes;
    std::vector<ColorNodePtr> color_nodes;    
};
typedef std::shared_ptr<NetNode> NetNodePtr;

//TODO: define classes for each type of color (range, mod, struct..)..
class ColorNode : public LnaNode {
public:
    ColorNode() : LnaNode(LnaNodeTypeColor) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void set_typeDef(const std::string& _typeDef);
    std::string get_typeDef() const;

protected:
    std::string name;
    std::string typeDef;
};
typedef std::shared_ptr<ColorNode> ColorNodePtr;

class SubColorNode : public LnaNode, public ColorNode {
public:
    SubColorNode(ColorNodePtr _supColor) : LnaNode(LnaNodeTypeSub_Color), supColor(_supColor) {}
    std::string source_code();

    void set_supColor(const ColorNodePtr _supColor);
    ColorNodePtr get_supColor() const;

private:
    ColorNodePtr supColor;
};
typedef std::shared_ptr<SubColorNode> SubColorNodePtr;

class ComponentNode : public LnaNode {
public:
    ComponentNode() : LnaNode(LnaNodeTypeComponent) {}
    ComponentNode(std::string _name, std::string _type) : LnaNode(LnaNodeTypeComponent), name(_name), type(_type) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void set_type(const std::string& _type);
    std::string get_type() const;


private:
    std::string name;
    std::string type;
};
typedef std::shared_ptr<ComponentNode> ComponentNodePtr;

class StructColorNode : public LnaNode, public ColorNode {
public:
    StructColorNode() : LnaNode(LnaNodeTypeStruct_Color) {}
    std::string source_code();

    void add_component(const ComponentNodePtr& _component);
    ComponentNodePtr get_component(const unsigned int& x);
    ComponentNodePtr get_component_by_name(const string& _name);

    size_t num_components();

private:
    std::vector<ComponentNodePtr> components;

};
typedef std::shared_ptr<StructColorNode> StructColorNodePtr;

class ListColorNode : public LnaNode, public ColorNode {
public:
    ListColorNode() : LnaNode(LnaNodeTypeListColor) {}
    std::string source_code();

    void set_index_type(const std::string& _name);
    std::string get_index_type() const;

    void set_element_type(const std::string& _name);
    std::string get_element_type() const;

    void set_capacity(const std::string& _name);
    std::string get_capacity() const;

private:
    std::string index_type;
    std::string element_type;
    std::string capacity;

};
typedef std::shared_ptr<ListColorNode> ListColorNodePtr;

class ConstantNode : public LnaNode {
public:
    ConstantNode() : LnaNode(LnaNodeTypeConstant) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void set_type(const std::string& _type);
    std::string get_type() const;

    void set_expression(const std::string& _expression);
    std::string get_expression() const;

private:
    std::string name;
    std::string type;
    std::string expression;
};
typedef std::shared_ptr<ConstantNode> ConstantNodePtr;

class ParamNode : public LnaNode {
public:
    ParamNode() : LnaNode(LnaNodeTypeParam) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;
    void set_type(const std::string& _type);
    std::string get_type() const;
private:
    std::string name;
    std::string type;
};
typedef std::shared_ptr<ParamNode> ParamNodePtr;

class FunctionNode : public LnaNode {
public:
    FunctionNode() : LnaNode(LnaNodeTypeFunc) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void set_returnType(const std::string& _returnType);
    std::string get_returnType() const;

    void add_parameter(const ParamNodePtr& _node);

    void set_body(const std::string& _body);
    std::string get_body() const;

private:
    std::string name;
    std::string returnType;
    std::vector<ParamNodePtr> parameters_spec;
    std:: string body;
};
typedef std::shared_ptr<FunctionNode> FunctionNodePtr;

class PlaceNode : public LnaNode {
public:
    PlaceNode() : LnaNode(LnaNodeTypePlace) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void set_domain(const std::string& _domain);
    std::string get_domain() const;

    void set_init(const std::string& _init);
    std::string get_init() const;

    void set_capacity(const std::string& _capacity);
    std::string get_capacity() const;

    void set_type(const std::string& _type);
    std::string get_type() const;
private:
    std::string name;
    std::string domain;
    std::string init;
    std::string capacity;
    std::string type;
};
typedef std::shared_ptr<PlaceNode> PlaceNodePtr;

class ArcNode : public LnaNode {
public:
    ArcNode() : LnaNode(LnaNodeTypeArc) {}
    std::string source_code();

    void set_placeName(const std::string& _placeName);
    std::string get_placeName() const;

    void set_label(const std::string& _label);
    std::string get_label() const;

private:
    std::string placeName;
    std::string label;
};
typedef std::shared_ptr<ArcNode> ArcNodePtr;

class TransitionNode : public LnaNode {
public:
    TransitionNode() : LnaNode(LnaNodeTypeTransition) {}
    std::string source_code();

    void set_name(const std::string& _name);
    std::string get_name() const;

    void add_inArc(const ArcNodePtr& _node);

    void add_outArc(const ArcNodePtr& _node);

    void add_inhibitArc(const ArcNodePtr& _node);

    void set_guard(const std::string& _guard);
    std::string get_guard() const;

    void set_priority(const std::string& _priority);
    std::string get_priority() const;

    void set_description(const std::string& _description);
    std::string get_description() const;

    void set_safe(const std::string& _safe);
    std::string get_safe() const;
private:
    std::string name;
    std::vector<ArcNodePtr> inArcs;
    std::vector<ArcNodePtr> outArcs;
    std::vector<ArcNodePtr> inhibitArcs;
    std::string guard;
    std::string priority;
    std::string description;
    std::string safe;
};
typedef std::shared_ptr<TransitionNode> TransitionNodePtr;

}
#endif //SOL2CPN_HELENA_H_
