#include "lexer.h"
#include <regex>
#include <iostream>


std::smatch lex(const std::string& input) {
	std::regex ints("(int)\\s([a-zA-Z_-][a-zA-Z0-9_]*)\\s(=)\\s*(\\d+)");
	std::regex prints("(print)\\s?\\(\"?[a-zA-Z0-9_-]+\"?");
	std::smatch match;
	
	if (std::regex_search(input, match, prints) or std::regex_search(input, match, ints)){
        return match;
	}
	else {
		  return std::smatch();  // Return an empty match result if no match
	}
	
    
}
