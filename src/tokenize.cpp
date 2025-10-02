#include "tokenize.h"
#include "macro.h"
#include <vector>

using std::string;

void skipWhitespace(const std::string& input, int& pos) {
    while (pos < (int)input.length() && std::isspace(input[pos])) {
        pos++;
    }
}

template <typename F>
string readWhile(const std::string& input, int& pos, F cond) {
    string result;
    while (pos < (int)input.length() && cond(input[pos])) {
        result += input[pos++];
    }
    return result;
}

std::vector<Token> Tokenize::allTokens(const std::string& input)
{
    int pos = 0;
    Token token;
    std::vector<Token> collectionTokens;

    while(true)
    {
        token = nextToken(input, pos);
        if(token.type == TOKEN_TYPE_END_OF_FILE)
        {
            break;
        }
        collectionTokens.push_back(token);
    }

    return collectionTokens;
}

Token Tokenize::nextToken(const std::string& input, int& pos) {
    Token token;

    skipWhitespace(input, pos);

    if (pos >= (int)input.length()) {
        token.type = TOKEN_TYPE_END_OF_FILE;
        token.val = "";
        return token;
    }

    char c = input[pos];

    if (std::isalpha(c)) {
        token.type = TOKEN_TYPE_IDENTIFIER;
        token.val = readWhile(input, pos, [](char ch) { return std::isalnum(ch) || ch == '_'; });
    }
    else if (std::isdigit(c)) {
        token.type = TOKEN_TYPE_NUMBER;
        string numStr = readWhile(input, pos, [](char ch) { return std::isdigit(ch); });
        token.val = std::stoi(numStr); // store as int in variant
    }
    else if (c == '*') {
        pos++;
        token.type = TOKEN_TYPE_STAR;
        token.val = "*";
    }
    else if (c == ',') {
        pos++;
        token.type = TOKEN_TYPE_COMMA;
        token.val = ",";
    }
    else if (c == '=') {
        pos++;
        token.type = TOKEN_TYPE_EQUALS;
        token.val = "=";
    }
    else {
        pos++;
        token.type = TOKEN_TYPE_UNKNOWN;
        token.val = string(1, c);
    }

    // Check for SQL keywords (case-insensitive)
    if (token.type == TOKEN_TYPE_IDENTIFIER) {
        string tmp = TO_UPPER(std::get<string>(token.val));
        if (tmp == "SELECT") token.type = TOKEN_TYPE_SELECT;
        else if (tmp == "FROM") token.type = TOKEN_TYPE_FROM;
        else if (tmp == "WHERE") token.type = TOKEN_TYPE_WHERE;
        else if (tmp == "AND") token.type = TOKEN_TYPE_AND;
        else if (tmp == "OR") token.type = TOKEN_TYPE_OR;
    }

    return token;
}
