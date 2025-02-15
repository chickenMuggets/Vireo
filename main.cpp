#include <iostream>
#include "includes/lexer.h"
#include <fstream>

int main(int argc, char **argv) {

	//defining input and output file names
	std::string inputfile = argv[1];
	std::string outputfile = argv[2];
	std::ifstream programfile(inputfile);
	std::ofstream outfile(outputfile);


	std::string line;
	int fileline = 0;
	
	outfile << "#include <iostream>\n\n\nint main(int argc, char **argv) {\n";
	std::vector<std::string> writeque;
	while (getline (programfile, line)) {
		fileline++;
		std::smatch lexedLine = lex(line);
		if (lexedLine[1] == "print") {
			
		}
		else if (lexedLine[1] == "int") {
			
		}
		else if (lexedLine == std::smatch()) {
		    std::cerr << "line " << fileline << " with contents \"" << line << "\" does not match any known constructors \n";
		    std::cerr << "Lexed line: " << lexedLine[1] << "\n";
		    return 1;
		}
	}
	std::cout << "writing to file" << "\n";
	for(std::string que : writeque) {
		outfile << que;
	}
	outfile << "\n}";
	outfile.close();
	std::cout << "writing finished" << "\n";
	
    return 0;
}
