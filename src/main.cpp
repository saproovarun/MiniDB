#include "REPL.h"

int main() {
    REPL repl;
    repl.tokenize("SELECT * FROM users");
    return 0;
}