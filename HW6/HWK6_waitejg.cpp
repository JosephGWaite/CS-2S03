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
	1. 	 We need a validator.
			a. loop through the infix notation tokens
			b. compare them against a set of rules
				i) equal # of open and closing parens
				ii) cannot have weird signage like /* ++
				iii) just come up with a set of rules for these
			c. if validate fails, throw an error
			d. check piazza for info.

	2.	 Convert to postfix notation.

	3.	 from postfix -> make the expression tree.

	4. 	 Make the trees with recursion.

	5. 	 Make it more modular, add classes.
			a. Lexer / Parser?
			b. Validator

	6.	 Fix the inevitable shittonne of memory leaks

	7.	 -ve numbers are a token. change the dfa
*/

void print_token(Token const& curToken) {
	//TODO operator overload for << so we can print easier.
	//Could we add a .toString() and it automatically does the converstion,
	// like java?
	// I'll Get someone else to do it. JOEL joel do this
	std::cout << "{ Type: " << curToken.type
	          << " Value: " << curToken.value
	          << " }" << std::endl;
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

		ArithmeticExpression *tree = toTree(postfix_list);

		//tree->print();

		std::for_each(postfix_list.begin(), postfix_list.end(), &print_token);
	}
}