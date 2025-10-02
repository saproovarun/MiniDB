#pragma once
#include <iostream>
#include <string>
#include <cctype>

class Parser {
public:
    Parser();
    ~Parser();

    void parse(const std::string& input);
    void run();
};