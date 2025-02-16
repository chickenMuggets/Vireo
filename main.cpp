#include <iostream>
#include <fstream>
#include "includes/lexer.h"
#include "includes/readloop.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input file provided.\n";
        return 1;
    }
    std::string inputfile = argv[1];  
    std::string outputfile = (argc > 2) ? argv[2] : "output.cpp"; // Default output file

    std::ifstream programfile(inputfile);
    if (!programfile) {
        std::cerr << "Error: Could not open input file: " << inputfile << "\n";
        return 1;
    }

    std::ofstream outfile(outputfile);
    if (!outfile) {
        std::cerr << "Error: Could not open output file: " << outputfile << "\n";
        return 1;
    }

    std::cout << "Processing file...\n";
    
    std::string line;
    int fileline = 0;
    std::vector<std::string> writeque = readloopfile(inputfile);

	std::cout << "writing to file" << "\n";
	for(std::string que : writeque) {
		outfile << que;
	}
	outfile << "\n}";
	outfile.close();
	std::cout << "writing finished" << "\n";
	
    return 0;
}
