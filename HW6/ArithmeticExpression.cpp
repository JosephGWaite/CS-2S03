#include <string>
#include <iostream>
#include "ArithmeticExpression.h"
#include "token.h"

std::string ArithmeticExpression::evaluate() {
	//std::string x;
	//x.push_back(this->value);
	// x.push_back("  ");
	// x.push_back(evaluate(this->right));
	// x.push_back(evaluate(this->left));
	// return x;
	//return x;
	std::string x = "yeezy";
	return x;
}

// void ArithmeticExpression::print() {
// 	std::cout << "called print on : " << (this-> value) << std::endl;

// 	if (this->right != nullptr)
// 		(this->right)->print();

// 	if (this->left != nullptr)
// 		(this->left)->print();
// }

void ArithmeticExpression::print(){

	if (this->left != nullptr) {
		if ((this->value) == "+" || (this->value) == "-" || (this->value) == "*" || (this->value) == "/") {
			
			std::cout << "(";
			(this->right)->print();
			std::cout << " ";
			std::cout << this->value;
			std::cout << " ";
			(this->left)->print();
			std::cout << ")";
		}
		else {
			std::cout << (this->value);
		}
	}
	else {
		std::cout << (this->value);
	}
}

float ArithmeticExpression::convert(std::string s) {
	//Converts a string (returned by evaluate) to a float
}