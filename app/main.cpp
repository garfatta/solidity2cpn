#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

#include <CLI11.hpp>
#include <json.hpp>

#include "ASTAnalyser.hpp"
#include "Constants.hpp"
#include "Utils.hpp"

#include "Helena.hpp"
#include "Translator.hpp"

int main(int argc, char** argv){
    CLI::App app{"Solidity2CPN tool"};

    std::string ast_file_name;
    app.add_option("--ast", ast_file_name, "Syntax Tree of Solidity Contract")
        ->required()
        ->check(CLI::ExistingFile);

    std::string ast_json_file_name;
    app.add_option("--json", ast_json_file_name, "JSON AST of Solidity Contract")
        ->required()
        ->check(CLI::ExistingFile);

    std::string context_filename;
    app.add_option("--context", context_filename, "Context file");

    std::string property_filename;
    app.add_option("--property", property_filename, "Property file");

    std::string output_file_name;
    app.add_option("--output", output_file_name, "Output file")->default_val("output.lna");

    CLI11_PARSE(app, argc, argv);

    // string buffers
    std::stringstream ast_text_stream;
    std::string new_line;

    std::ifstream ast_text_file_stream(ast_file_name);
    while (getline(ast_text_file_stream, new_line)) {
        ast_text_stream << new_line << "\n";
    }
    ast_text_file_stream.close();

    // TODO: maybe it can be refactored
    std::string sol_name;
    std::string ast_json_content;
    std::ifstream ast_json_file_stream(ast_json_file_name);
    while (getline(ast_json_file_stream, new_line)) {
        // Get the smart contract name
        if (new_line.find(".sol =======") != std::string::npos) {
            sol_name = SOL2CPN::Utils::substr_by_edge(new_line, "======= ", " =======");
            break;
        }
    }

    while (getline(ast_json_file_stream, new_line)) {
        if (new_line.find(".sol =======") == std::string::npos) {
            ast_json_content = ast_json_content + new_line + "\n";
        } else {
            nlohmann::json ast_json = nlohmann::json::parse(ast_json_content);
            sol_name = SOL2CPN::Utils::substr_by_edge(new_line, "", "");
            ast_json_content = "";
        }
    }
    ast_json_file_stream.close();

    if (ast_json_content != "") {
        // parse AST file into JSON format
        nlohmann::json ast_json = nlohmann::json::parse(ast_json_content);

        // analyse AST
        SOL2CPN::ASTAnalyser ast_analyser(ast_text_stream, ast_json, true, sol_name, "");
        SOL2CPN::RootNodePtr root_node = ast_analyser.analyse();

        // translate smart contrat AST into CPN
        SOL2CPN::Translator nettranslator(root_node);
        SOL2CPN::NetNodePtr net_node = nettranslator.translate();

        // get Helena code of the CPN
        std::string new_source = net_node->source_code();

        // save output to a file
        std::ofstream output_file_stream(output_file_name);
        output_file_stream << new_source;
        output_file_stream.close();

        std::cout << "lna file generated: SUCESS" << std::endl;
    }


    exit(SOL2CPN::ErrorCode::SUCCESS);

    return 0;
}
