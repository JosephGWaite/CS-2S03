#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <istream>
#include <vector>

std::vector<Token> parse_char(std::istream& c);

Token lex_op(std::istream&);  //{ = | - | * | / } //TODO add type
Token lex_num(std::istream&); // {digits}
Token lex_paren(std::istream&); // { ( | ) }
Token lex_negnum(std::istream&); 

bool isop(char c);

#endif