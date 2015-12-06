#include "lexer.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> 

//BIG LIST OF TODOS:
/*
	1. 	How we we redo parsing? We cannot call parse char on each;
	make it parse token and it figure out the token length on its own,

		a. bugs include whitespace casuing core dump
		b. we need to handle -5 + 1, 1 + -5, etc

	2.	 We've gotta work around the types given in the assignment
	I think we should do parsing by stream,
	then convert out vector of tokens to whatever the assngment says

	3.	 Figure out the recursion things + how we handle bedmas.
	I think its done properly already.

	4. 	 Make the trees with recursion.
	5. 	 Then we need to do a sort of graph reduction. cool
	6. 	 Make it more modular, add classes.
	7.
Thought on parsing

while(std::cin != "#"){
	then pass the cin stream to the tokenizer
	tokeniser(std::cin)
	{
		logic in here for tokens
		Tested. Does not work.
	}
}
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