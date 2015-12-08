#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include <vector>

int precedence(Token a); 

std::vector<Token> toPostfix(std::vector<Token> token_list);

#endif