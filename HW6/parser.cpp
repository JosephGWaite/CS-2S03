#include <stack>
#include <vector> 
#include "token.h"
// our function should take a vector of tokens and return a vector of tokens in the post-fix notation
// then we can easily do postfix to trees using our class structure thing 

std::vector<Token> toPostfix(std::vector<Token> token_list){
	std::stack operators;
	std::stack postfix;
	//We use token.type for precedence
	for (Token &token : token_list){

	}
}

