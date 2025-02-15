#include <iostream>
#include "includes/lexer.h"
#include <fstream>

int main(int argc, char **argv) {
	std::string fileselected = argv[1];
	std::ifstream programfile(fileselected);

	std::string line;
	int fileline = 0;
	

	while (getline (programfile, line)) {
		fileline++;
		std::cout << fileline << "\n";
		std::smatch lexedLine = lex(line);
		if (lexedLine == std::smatch()) {
			std::cout << "not detected";
		}
	}
	
    return 0;
}
