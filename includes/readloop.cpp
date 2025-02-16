#include <iostream>
#include <fstream>
#include "lexer.h"
std::vector<std::string> readloopfile(std::string filetoread) {
    std::string line;
    int fileline = 0;
    std::vector<std::string> writeque;
    std::ifstream readingfile(filetoread);
    writeque.push_back("#include <iostream>\n\n\nint() main {\n");
    std::string tabAmout = "	";
	while (getline (readingfile, line)) {
		fileline++;
		std::cout << "Processing line " << fileline << "\n";
		std::smatch lexedLine = lex(line);
		tabAmout = "	";
		if (lexedLine[1] == "print") {
			if (lexedLine[3].str() == "=") {
			 writeque.push_back(tabAmout + "std::cout << \"" + lexedLine[2].str() + "\" << std::endl;\n"); 
			}
		}


		else if (lexedLine[1] == "int") {
			if (lexedLine.size() > 4 && lexedLine[3].str() == "=") {
				writeque.push_back(tabAmout + "int " + lexedLine[2].str() + " = " + lexedLine[4].str() + ";\n");
			}
			else {
				writeque.push_back(tabAmout + "int " + lexedLine[2].str() + ";\n");
			}
		}

		else {
		    std::cerr << "Line " << fileline << " with contents \"" << line << "\" does not match any known constructors.\n";
		}
		std::cout << "Processed line " << fileline << "\n";
	}
	return writeque;
}
