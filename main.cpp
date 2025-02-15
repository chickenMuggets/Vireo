#include <iostream>
#include "includes/lexer.h"

int main() {
	if (lex("print(\"hello\")") == std::smatch()) {
		std::cout << "not detected";
	}
    return 0;
}
