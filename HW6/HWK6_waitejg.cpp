#include "lexer.h"
#include <string>
#include <iostream>
#include <vector> 

void print_token(Token const& curToken){
	//TODO operator overload for << so we can print easier. 
	//Could we add a .toString() and it automatically does the converstion,
	// like java?
	// I'll Get someone else to do it. JOEL joel do this 
	std::cout << "{ Type: " << curToken.type 
			  << "Value: " << curToken.value
			  << " }" << std::endl; 
}
int main () {
	std::string line;
	//TODO: error handling
	while (std::getline(std::cin, line)) {

		// User entering '#' is the defined exit condition. 
		if (line == "#") break; 

		for (char & c : line)
		{
			//call parse_char on each char
			//then print the token
			print_token(parse_char(c));
		}
	}
}

