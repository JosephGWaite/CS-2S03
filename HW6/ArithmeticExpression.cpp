#include <string>
#include <iostream>
#include "ArithmeticExpression.h"
#include "token.h"

float ArithmeticExpression::evaluate() {
	float x, y, z;
	if (this->right == nullptr || this->left == nullptr) {
		return std::stof(this->value);
	} else {
		//std::cout << "If this is called, oops" << std::endl;
		x = (this->left)->evaluate();
		y = (this->right)->evaluate();

		if (this->type == mult_token) {
			z= y * x;

		} else if (this->type == div_token) {
			z =  y / x;

		} else if (this->type == add_token) {
			z = y + x;

		} else if (this->type == sub_token) {
			z=  y - x;
		}

		return z;
	}
}

void ArithmeticExpression::print() {

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