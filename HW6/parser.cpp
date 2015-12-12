#include <stack>
#include <vector>
#include <iostream>
#include "token.h"
#include "parser.h"
#include "lexer.h" //for isop() function

// our function should take a vector of tokens and return a vector of tokens in the post-fix notation
// then we can easily do postfix to trees using our class structure thing

int precedence(Token a) {

	if (a.type == add_token || a.type == sub_token) {
		return 1;
	} else if (a.type == mult_token || a.type == div_token) {
		return 2;
	} else if (a.type == open_token) { // (
		return 5;
	} else if (a.type == close_token) { // )
		return 4;
	} else {
		return 0;
	}

}


std::vector<Token> toPostfix(std::vector<Token> token_list) {
	std::stack<Token> operators;
	std::vector<Token> postfix;

	//We use token.type for precedence
	//loop through each token.
	for (Token &cur_token : token_list) {

		if (cur_token.type == num_token) { //if the token is an operand:
			postfix.push_back(cur_token);
			//std::cout << "PRINTING num_token : " << cur_token.value << std::endl;

		} else { //token must be an operator.

			//add to stack if:
			//   stack is empty
			// | if token has higher precendece than op on top of stack
			// | if top is open_token token.
			if (operators.empty() || precedence(cur_token) > precedence(operators.top()) || (operators.top().type == open_token)) {

				operators.push(cur_token);
				//std::cout << "pushed on stack: " << cur_token.value << std::endl;

			} else { //remove ops which have a higher

				int orphans = 0;
				//remove all ops that have a high precedence.
				//If closing paren, we need to find the opener



				while (!operators.empty()
				        && ((precedence(operators.top()) >= precedence(cur_token))
				            || orphans)
				        && !(!orphans && operators.top().type == open_token) ) {

					if (operators.top().type == close_token) {
						orphans++;

					} else if (operators.top().type == open_token) {
						orphans--;

					} else {
						//std::cout << "PRINTING 1st while: " << operators.top().value << std::endl;
						postfix.push_back(operators.top());
						
					}
					operators.pop();
				}
				operators.push(cur_token);
			}
		}
	}
	while (!operators.empty()) {
		if ((operators.top().type != open_token) && (operators.top().type != close_token)) {
			postfix.push_back(operators.top());
		} 
			operators.pop();
	}
	return postfix;
}

