#include "parser.h"

#include <string>
#include <iostream>
#include <sstream>

int main () {
	std::string line;
	//TODO: error handling
	
	while(std::getline(std::cin, line)){
		std::istringstream line_stream(line);

		auto ptr = parse_expression(line_stream);

		std::cout << *ptr << endl //We overloaded << in expression.h
	}
} 

