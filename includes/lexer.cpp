#include "lexer.h"
#include <regex>
std::regex ints("(int)\\s([a-zA-Z_-][a-zA-Z0-9_]*)\\s(=)\\s*(\\d+)");
std::regex prints("(print)\\s?\\((\")?([a-zA-Z_-])(\"?)\\)");


std::string lex(const std::string& input) {
    return input; // Dummy implementation
}
