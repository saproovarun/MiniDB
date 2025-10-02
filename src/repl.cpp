#include "repl.h"
#include "tokenize.h"
#include "macro.h"
#include <vector>

REPL::REPL() {
}

REPL::~REPL() {
}

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TOKEN_TYPE_SELECT: return "SELECT";
        case TOKEN_TYPE_FROM: return "FROM";
        case TOKEN_TYPE_WHERE: return "WHERE";
        case TOKEN_TYPE_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_TYPE_STRING: return "STRING";
        case TOKEN_TYPE_NUMBER: return "NUMBER";
        case TOKEN_TYPE_AND: return "AND";
        case TOKEN_TYPE_OR: return "OR";
        case TOKEN_TYPE_STAR: return "STAR";
        case TOKEN_TYPE_COMMA: return "COMMA";
        case TOKEN_TYPE_EQUALS: return "EQUALS";
        case TOKEN_TYPE_END_OF_FILE: return "EOF";
        default: return "UNKNOWN";
    }
}


void REPL::run() {
    std::string input  = "SELECT * FROM table_1 WHERE X = 23";
    // std::cout << "MINI DB > " << std::endl;
    // while(getline(std::cin, input)) {
    //     if(TO_LOWER(input) == "exit") {
    //         break;
    //     }
    //     std::cout << "MINI DB > " << std::endl;
    // }
    std::vector<Token> tokens = Tokenize::allTokens(input);

    for (const auto& tok : tokens) {
    std::cout << "Type: " << tokenTypeToString(tok.type) << " | Value: ";

    if (std::holds_alternative<std::string>(tok.val)) {
        std::cout << std::get<std::string>(tok.val);
    }
    else if (std::holds_alternative<int>(tok.val)) {
        std::cout << std::get<int>(tok.val);
    }

    std::cout << "\n";
}

    
}