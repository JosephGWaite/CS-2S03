#include "lexer.h"
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
				ii) cannot have weird signage like /* ++ --
				iii) just come up with a set of rules for these
			c. if validate fails, throw an error
		
	2.	 Convert to postfix notation
	3.	 from postfix -> make the expression tree.
	4. 	 Make the trees with recursion.
	
	5. 	 Make it more modular, add classes.
			a. Lexer / Parser?
			b. Validator
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

//Grabbed this input stuff from here:
//		http://www.cppsamples.com/common-tasks/read-line-by-line.html

int main () {
	std::string line;
	//TODO: error handling
	while (std::getline(std::cin, line)) {
		// User entering '#' is the defined exit condition.
		if (line == "#") break;
		std::istringstream cur_line(line);
		std::vector<Token> list; 

		list = parse_char(cur_line); //parse char takes a stream and returns a list of tokens

		std::for_each(list.begin(), list.end(), &print_token);
	}
}