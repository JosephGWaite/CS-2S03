#include "lexer.h"
#include "parser.h"
#include "token.h"
#include "validator.cpp"
#include "ArithmeticExpression.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

//BIG LIST OF TODOS:
/*

	2.	 Postfix Notation calculator has bugs

	4. 	 Traverse the tree with infix and print

	5. 	 Make it more modular, add classes.
			a. Lexer / Parser?
			b. Validator

	6.	 Fix the inevitable shittonne of memory leaks

	7.	 -ve numbers are a token. change the dfa
			//Fairly high priority
			//Will not eval or print infix without this


	8.	Evalute different types.
*/


void print_token(Token const& curToken) {
	std::cout << "{ Type: " << curToken.type
	          << " Value: " << curToken.value
	          << " }" << std::endl;
}

void print_expr(Token const& curToken) {
	std::cout << " " << curToken.value ;
}




ArithmeticExpression* toTree(std::vector<Token> & postfix_list) {

	Token curToken = postfix_list.back();
	postfix_list.pop_back();

	ArithmeticExpression *node = new ArithmeticExpression;
	//if this node is an operaand. no left or right subtrees. base case for recursion.
	if (curToken.type == num_token) {



		node -> value = curToken.value;
		node -> type = curToken.type;
		std::cout << "leaf " << curToken.value << std::endl;

		node -> right = nullptr;
		node -> left = nullptr;

	} else {

		// switch (curToken.type) {
		// case mult_token:
		// 	ArithmeticExpression *node = new ArithmeticExpression;
		// 	break;
		// case div_token:
		// 	ArithmeticExpression *node = new ArithmeticExpression;
		// 	break;
		// case add_token:
		// 	ArithmeticExpression *node = new ArithmeticExpression;
		// 	break;
		// case sub_token:
		// 	ArithmeticExpression *node = new ArithmeticExpression;
		// 	break;
		// }

		node -> value = curToken.value;
		node -> type = curToken.type;


		std::cout << "right " << curToken.value << std::endl;
		node -> right = toTree(postfix_list);

		std::cout << "left " << curToken.value << std::endl;
		node -> left = toTree(postfix_list);
	}
	return node;
}


//Grabbed this input stuff from here:
//		http://www.cppsamples.com/common-tasks/read-line-by-line.html

int main () {
	std::string line;
	//TODO: error handling
	while (std::getline(std::cin, line)) {
		// User entering '#' is the defined exit condition.
		if (line == "#") break;

		//We're gonna pass this stream to
		std::istringstream cur_line(line);

		std::vector<Token> prefix_list;
		std::vector<Token> postfix_list;
		std::vector<Token> previous_expr;

		//Comments :P
		prefix_list = parse_char(cur_line);

		//validator(prefix_list);

		postfix_list = toPostfix(prefix_list);

		// ArithmeticExpression *tree = new ArithmeticExpression;

		// tree = toTree(postfix_list);

		// tree->print();

		std::for_each(postfix_list.begin(), postfix_list.end(), &print_expr);
	}
}