#include <iostream>
#include <fstream>
#include "lexer.h"
std::vector<std::string> readloopfile(std::string filetoread) {
    std::string line;
    int fileline = 0;
    std::vector<std::string> writeque;
    std::ifstream readingfile(filetoread);
    writeque.push_back("#include <iostream>\n\n\nint() main {\n");
	while (getline (readingfile, line)) {
		fileline++;
		std::smatch lexedLine = lex(line);
		if (lexedLine[1] == "print") {
			if (lexedLine[3].str() == "=") {
			 writeque.push_back("std::cout << \"" + lexedLine[2].str() + "\" << std::endl;\n"); 
			}
		}


		else if (lexedLine[1] == "int") {
			writeque.push_back("int " + lexedLine[2].str() + ";\n");
		}

		else {
		    std::cerr << "Line " << fileline << " with contents \"" << line << "\" does not match any known constructors.\n";
		}
		std::cout << "Processed line " << fileline << "\n";
	}
	writeque.push_back("}"); 
	return writeque;
}
