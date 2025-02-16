#include <iostream>
#include <fstream>
#include "lexer.h"
std::vector<std::string> readloopfile(std::string filetoread) {
    std::string line;
    int fileline = 0;
    std::vector<std::string> writeque;
    std::ifstream readingfile(filetoread);

	while (getline (readingfile, line)) {
		fileline++;
		std::smatch lexedLine = lex(line);
		if (lexedLine[1] == "print") {
			 writeque.push_back("std::cout << \"" + line.substr(6) + "\" << std::endl;\n"); 
		}
		else if (lexedLine[1] == "int") {
			writeque.push_back("int " + line.substr(4) + ";\n");
		}
		else {
		    std::cerr << "Line " << fileline << " with contents \"" << line << "\" does not match any known constructors.\n";
		}
		std::cout << "Processed line " << fileline << "\n";
	}
	return writeque;
}
