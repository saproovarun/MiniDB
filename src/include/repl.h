#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include "tokenize.h"

class REPL {
public:
    REPL();
    ~REPL();

    void run();
};