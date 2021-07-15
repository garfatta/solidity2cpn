#include "Helena.hpp"

namespace SOL2CPN {

LnaNodeType LnaNode::get_node_type() const {
    return node_type;
}

void LnaNode::append_sub_node(const LnaNodePtr& _node) {
    lna_nodes.push_back(_node);
}

void LnaNode::delete_sub_node(const unsigned int& x) {
    lna_nodes.erase(lna_nodes.begin() + x);
}

void LnaNode::update_sub_node(const unsigned int& x, const LnaNodePtr _node) {
    lna_nodes[x] = _node;
}

LnaNodePtr LnaNode::get_sub_node(const unsigned int& x) const {
    return lna_nodes[x];
}

size_t LnaNode::size() {
    return lna_nodes.size();
}

std::string NetNode::source_code() {
    std::stringstream result;
    result << name;
    if (param_nodes.size() != 0) {
        result << "(";
        for (auto it = param_nodes.begin(); it != param_nodes.end(); ++it) {
            result << (*it)->source_code();
            if (it != param_nodes.end()-1)
                result << ", ";
        }
        result << ")";
    }
    result << " {\n";
    for (auto it = lna_nodes.begin(); it != lna_nodes.end(); ++it) {
        result << (*it)->source_code();
    }
    result << "\n}";
    return result.str();
}

void NetNode::set_name(const std::string& _name) {
    name = _name;
}

std::string NetNode::get_name() const {
    return name;
}

void NetNode::add_parameter(const ParameterNodePtr& _node) {
    param_nodes.push_back(_node);
}

void NetNode::add_member(const LnaNodePtr& _node) {
    append_sub_node(_node);
}

void NetNode::delete_member(const unsigned int& x) {
    delete_sub_node(x);
}

void NetNode::update_member(const unsigned int& x, const LnaNodePtr& _node) {
    update_sub_node(x, _node);
}

LnaNodePtr NetNode::get_member(const unsigned int& x) {
    return get_sub_node(x);
}

size_t NetNode::num_members() {
    return size();
}

void NetNode::add_color(const ColorNodePtr& _color) {
    add_member(_color);
    color_nodes.push_back(_color);
}

ColorNodePtr NetNode::get_color_by_name(const string& _color) {
    for (auto it = color_nodes.begin(); it != color_nodes.end(); ++it)
            if ((*it)->get_name() == _color)
                return (*it);
    return nullptr;
}

std::string ParameterNode::source_code() {
    std::string result = name + " := " + number;
    return result;
}

void ParameterNode::set_name(const std::string& _name) {
    name = _name;
}

std::string ParameterNode::get_name() const {
    return name;
}

void ParameterNode::set_number(const std::string& _number) {
    number = _number;
}

std::string ParameterNode::get_number() const {
    return number;
}

std::string ColorNode::source_code() {
    //visit(this);
    std::string result = "type " + name + " : " + typeDef + ";\n";
    return result;
}

void ColorNode::set_name(const std::string& _name) {
    name = _name;
}

std::string ColorNode::get_name() const {
    return name;
}

void ColorNode::set_typeDef(const std::string& _typeDef) {
    typeDef = _typeDef;
}

std::string ColorNode::get_typeDef() const {
    return typeDef;
}

std::string ComponentNode::source_code() {
    std::string result = type + " " + name + ";";
    return result;
}

void ComponentNode::set_name(const std::string& _name) {
    name = _name;
}

std::string ComponentNode::get_name() const {
    return name;
}

void ComponentNode::set_type(const std::string& _type) {
    type = _type;
}

std::string ComponentNode::get_type() const {
    return type;
}

std::string SubColorNode::source_code() {
    std::string result = "subtype " + name + " : " + supColor->get_name() + " " + typeDef + ";\n";
    return result;
}

void SubColorNode::set_supColor(const ColorNodePtr _supColor) {
    supColor = _supColor;
}
ColorNodePtr SubColorNode::get_supColor() const {
    return supColor;
}

std::string StructColorNode::source_code() {
    std::string result = "type " + name + " : struct { ";
    for (auto it = components.begin(); it != components.end(); ++it)
        result += (*it)->source_code();
    result += "};\n";
    return result;
}

void StructColorNode::add_component(const ComponentNodePtr& _component) {
    components.push_back(_component);
}

ComponentNodePtr StructColorNode::get_component(const unsigned int& x) {
    return components[x];
}

ComponentNodePtr StructColorNode::get_component_by_name(const string& _name) {
    for (auto it = components.begin(); it != components.end(); ++it)
            if ((*it)->get_name() == _name)
                return (*it);
    return nullptr;
}

size_t StructColorNode::num_components() {
    return components.size();
}

std::string ListColorNode::source_code() {
    //visit(this);
    std::string result = "type " + name + " : list[" + index_type + "] of " + element_type + " with capacity " + capacity +";\n";
    return result;
}

void ListColorNode::set_index_type(const std::string& _index_type) {
    index_type = _index_type;
}

std::string ListColorNode::get_index_type() const {
    return index_type;
}

void ListColorNode::set_element_type(const std::string& _element_type) {
    element_type = _element_type;
}

std::string ListColorNode::get_element_type() const {
    return element_type;
}

void ListColorNode::set_capacity(const std::string& _capacity) {
    capacity = _capacity;
}

std::string ListColorNode::get_capacity() const {
    return capacity;
}

std::string ConstantNode::source_code() {
    //visit(this);
    std::string result = "constant " + type + " " + name + ":=" + expression + ";\n";
    return result;
}

void ConstantNode::set_name(const std::string& _name) {
    name = _name;
}

std::string ConstantNode::get_name() const {
    return name;
}

void ConstantNode::set_type(const std::string& _type) {
    type = _type;
}

std::string ConstantNode::get_type() const {
    return type;
}

void ConstantNode::set_expression(const std::string& _expression) {
    expression = _expression;
}

std::string ConstantNode::get_expression() const {
    return expression;
}

std::string ParamNode::source_code() {
    std::string result = type + " " + name;
    return result;
}

void ParamNode::set_name(const std::string& _name) {
    name = _name;
}

std::string ParamNode::get_name() const {
    return name;
}

void ParamNode::set_type(const std::string& _type) {
    type = _type;
}

std::string ParamNode::get_type() const {
    return type;
}

std::string FunctionNode::source_code() {
    std::string result = "function " + name + " (";
    for (auto it = parameters_spec.begin(); it != parameters_spec.end(); ++it) {
            result += (*it)->source_code();
            if (it != parameters_spec.end()-1)
                result += ", ";
    }
    result += ")";
    if (returnType != "")
        result += " -> " + returnType;
    if (body != "")
        result += "{\n" + body + "}\n}";
    else
        result += ";\n";
    return result;
}

void FunctionNode::set_name(const std::string& _name) {
    name = _name;
}
std::string FunctionNode::get_name() const {
    return name;
}

void FunctionNode::set_returnType(const std::string& _returnType) {
    returnType = _returnType;
}

std::string FunctionNode::get_returnType() const {
    return returnType;
}

void FunctionNode::add_parameter(const ParamNodePtr& _node) {
    parameters_spec.push_back(_node);
}

void FunctionNode::set_body(const std::string& _body) {
    body = _body;
}
std::string FunctionNode::get_body() const {
    return body;
}

std::string PlaceNode::source_code() {
    std::string result = "place " + name + " {\ndom : " + domain + ";";
    if (init != "")
        result += "\ninit : " + init + ";";
    if (capacity != "")
        result += "\ncapacity : " + capacity + ";";
    if (type != "")
        result += "\ntype : " + type + ";";
    result += "\n}";
    return result;
}

void PlaceNode::set_name(const std::string& _name) {
    name = _name;
}
std::string PlaceNode::get_name() const {
    return name;
}

void PlaceNode::set_domain(const std::string& _domain) {
    domain = _domain;
}
std::string PlaceNode::get_domain() const {
    return domain;
}

void PlaceNode::set_init(const std::string& _init) {
    init = _init;
}
std::string PlaceNode::get_init() const {
    return init;
}

void PlaceNode::set_capacity(const std::string& _capacity) {
    capacity = _capacity;
}
std::string PlaceNode::get_capacity() const {
    return capacity;
}

void PlaceNode::set_type(const std::string& _type) {
    type = _type;
}
std::string PlaceNode::get_type() const {
    return type;
}

std::string ArcNode::source_code() {
    std::string result = placeName + " : " + label + ";";
    return result;
}

void ArcNode::set_placeName(const std::string& _placeName) {
    placeName = _placeName;
}
std::string ArcNode::get_placeName() const {
    return placeName;
}

void ArcNode::set_label(const std::string& _label) {
    label = _label;
}
std::string ArcNode::get_label() const {
    return label;
}

std::string TransitionNode::source_code() {
    std::string result = "transition " + name + " {\nin {\n";
    for (auto it = inArcs.begin(); it != inArcs.end(); ++it)
        result += (*it)->source_code() + "\n";
    result += "}\nout {\n";
    for (auto it = outArcs.begin(); it != outArcs.end(); ++it)
        result += (*it)->source_code() + "\n";
    result += "}\n";
    if (inhibitArcs.size() != 0) {
        result += "inhibit {\n";
        for (auto it = inhibitArcs.begin(); it != inhibitArcs.end(); ++it)
            result += (*it)->source_code() + "\n";
        result += "}\n";
    }
    if (guard != "")
        result += "guard : " + guard + "\n";
    if (priority != "")
        result += "priority : " + priority + "\n";
    if (description != "")
        result += "description : " + description + "\n";
    if (safe != "")
        result += "safe\n";
    result += "}";
    return result;
}

void TransitionNode::set_name(const std::string& _name) {
    name = _name;
}
std::string TransitionNode::get_name() const {
    return name;
}

void TransitionNode::add_inArc(const ArcNodePtr& _node) {
    inArcs.push_back(_node);
}

void TransitionNode::add_outArc(const ArcNodePtr& _node) {
    outArcs.push_back(_node);
}

void TransitionNode::add_inhibitArc(const ArcNodePtr& _node) {
    inhibitArcs.push_back(_node);
}

void TransitionNode::set_guard(const std::string& _guard) {
    guard = _guard;
}
std::string TransitionNode::get_guard() const {
    return guard;
}

void TransitionNode::set_priority(const std::string& _priority) {
    priority = _priority;
}
std::string TransitionNode::get_priority() const {
    return priority;
}

void TransitionNode::set_description(const std::string& _description) {
    description = _description;
}
std::string TransitionNode::get_description() const {
    return description;
}

void TransitionNode::set_safe(const std::string& _safe) {
    safe = _safe;
}
std::string TransitionNode::get_safe() const {
    return safe;
}
}
