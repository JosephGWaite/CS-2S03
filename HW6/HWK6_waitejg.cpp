/*
Name:  Joseph Waite, Joel Straatman
MacID: waitejg, straatjc,
Student Number:  001403712, 001314676,
Description: scientific calculator with bonus
*/

#include "lexer.h"
#include "parser.h"
#include "token.h"
#include "validator.cpp"

#include "ArithmeticExpression.h"
#include "Multiplication.h"
#include "Addition.h"
#include "Division.h"
#include "Subtraction.h"

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip> // for setprecision 

//BIG LIST OF TODOS:
/*

	5. 	 Make it more modular, add classes.
			a. Lexer / Parser?
			b. Validator

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

	Token curToken = postfix_list.back(); //start from the back, yay RPN
	postfix_list.pop_back();

	ArithmeticExpression *node = NULL; //create a pointer to a tree

	//if this node is an operaand. no left or right subtrees. base case for recursion.
	if (curToken.type == num_token) {
		node = new ArithmeticExpression;

		node -> value = curToken.value;
		node -> type = curToken.type;

		node -> right = nullptr;
		node -> left = nullptr;

	} else { //create a subtree

		if (curToken.type == mult_token) {
			node = new Multiplication;

		} else if (curToken.type == div_token) {
			node = new Division;

		} else if (curToken.type == add_token) {
			node = new Addition;

		} else if (curToken.type == sub_token) {
			node = new Subtraction;

		} else {
			// should not be called. but w/e
			node = new ArithmeticExpression;
		}

		// subtree value and type are the same as the tokens
		node -> value = curToken.value;
		node -> type = curToken.type;


		//recursise call, working our way through the token list,
		// the order (left | right ) must match the print and eval functions
		node -> left = toTree(postfix_list);
		node -> right = toTree(postfix_list);

	}
	return node;
}

void deleteTree (ArithmeticExpression *node) {

	if ((node->left) != nullptr || (node->right) != nullptr) {
		deleteTree(node->left);
		deleteTree(node->right);
	}
	delete node;
}

std::vector<Token> incrementBonus(std::vector<Token> token_list) {
	//This only works if its all postive numbers
	// (-2) -> (0-2) -> increment -> (1 - 3)
	for (Token &cur_token : token_list) {
		if (cur_token.type == num_token) {
			int temp;
			temp = std::stoi(cur_token.value) + 1;

			// std::string zs;
			// std::ostringstream ss;

			// ss << std::fixed << std::setprecision() << temp;
			// zs = ss.str();

			cur_token.value = std::to_string(temp);
		}
	}
	return token_list;
}

//Grabbed this input stuff from here:
//		http://www.cppsamples.com/common-tasks/read-line-by-line.html

int main () {
	std::string line;
	std::vector<Token> previous_expr; // for bonus

	std::vector<Token> prefix_list;
	std::vector<Token> postfix_list;
	//TODO: error handling
	std::cout << "Please enter an expression: ";
	while (std::getline(std::cin >> std::ws, line)) {
		// User entering '#' is the defined exit condition.

		if (line == "#") break;
		if (line == "") continue; //Stops a segfault with empty input

		//We're gonna pass this stream to the tokeniser / lexer / parser
		std::istringstream cur_line(line);





		if (line == "@") {

			if (previous_expr.empty()) {
				std::cout << "You haven't entered an equation yet" << std::endl;
				continue;
			}
			//we assume it's a valid and already in postfix.
			prefix_list = incrementBonus(previous_expr);
			postfix_list = toPostfix(prefix_list);

		} else {

			//Gets a list of tokens in infix notation, which is hard to parse.
			prefix_list = parse_char(cur_line);

			//convert the tokens to postfix notation, bc its easier to make a tree this way.
			postfix_list = toPostfix(prefix_list);
		}

		//We run a validator on the infix tokens, and make sure the input was valid.
		// if not, ask again.

		if (validator(prefix_list) == false) {
			std::cout << "\n\nPlease enter a valid expression: ";
			continue;
		}

		previous_expr = prefix_list;

		//std::for_each(prefix_list.begin(), prefix_list.end(), &print_token); // <- For testing.
		//starting point of the tree (root?)
		ArithmeticExpression *tree = new ArithmeticExpression;

		//toTree takes a list of tokens, and returns a pointer to the root of a tree it created
		tree = toTree(postfix_list);

		//call the recursive print function, which traveserse the tree in infix notation.
		tree->print();

		//call the recursive evaluate fucntion. It evaluates recursivly.
		std::cout << " = " << tree->evaluate();

		//free up the memory.
		deleteTree(tree); // will delete everything, including that *tree ^^.

		std::cout << "\n\nPlease enter an expression: ";
	}
}