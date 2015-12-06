#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <istream>
#include <vector>

std::vector<Token> parse_char(std::istream& c);

#endif