#include "lexer.h"
#include <regex>
#include <iostream>


std::smatch lex(const std::string& input) {
	std::regex ints("(int)\\s([a-zA-Z_-][a-zA-Z0-9_]*)\\s(=)\\s*(\\d+)");
	std::regex prints("(print)\\s?\\((\")?([a-zA-Z_-]+)(\"?)\\)");
	std::smatch match;
	
	if (std::regex_search(input, match, prints)){
		std::cout << "Matched: " << match.str() << std::endl;
		std::cout << "Captured Group 1: " << match[1] << std::endl; // "print"
        std::cout << "Captured Group 2: " << match[2] << std::endl; // "("
		std::cout << "Captured Group 3: " << match[3] << std::endl; // Optional double quote, if any (")
        std::cout << "Captured Group 4: " << match[4] << std::endl; // The character, e.g., "A"
        return match; // Dummy implementation
	}
	else {
		  return std::smatch();  // Return an empty match result if no match
	}
	
    
}
