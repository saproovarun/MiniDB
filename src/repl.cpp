#include "repl.h"
#include "tokenize.h"

REPL::REPL() {
}

REPL::~REPL() {
}

void REPL::run() {
    string input;
    std::cout << "MINI DB > " << std::endl;
    while(getline(std::cin, input)) {
        if(tolower(input) == "exit") {
            break;
        }
        Lexer lexer = Lexer(input);
        std::cout << "MINI DB > " << std::endl;
    }
}