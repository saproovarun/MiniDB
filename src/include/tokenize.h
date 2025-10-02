#pragma once

#include <string>
#include <variant>
#include <vector>

enum TokenType {
    TOKEN_TYPE_UNKNOWN,
    TOKEN_TYPE_SELECT,
    TOKEN_TYPE_FROM,
    TOKEN_TYPE_WHERE,
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_AND,
    TOKEN_TYPE_OR,
    TOKEN_TYPE_STAR,
    TOKEN_TYPE_COMMA,
    TOKEN_TYPE_EQUALS,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_END_OF_FILE
};

typedef std::variant<std::string, int> TokenValue;

struct Token {
    TokenType type;
    TokenValue val;
};

namespace Tokenize {
    Token nextToken(const std::string& input, int& pos);
    std::vector<Token> allTokens(const std::string& input);
}
