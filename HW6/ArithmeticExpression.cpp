#include <string>
#include <iostream>
#include "ArithmeticExpression.h"
#include "token.h"

std::string ArithmeticExpression::evaluate() {

	//All this awkward string to float conversion is due to the given specification. 
	//
	float x, y, z;

	std::string xs, ys, zs; 

	//recursion base case: a leaf, which means a number. 
	if (this->right == nullptr || this->left == nullptr) {
		return (this->value); //string

	} else {

		//Take the strings that evaluate must return. 
		xs = (this->left)->evaluate();
		ys = (this->right)->evaluate();

		//turn them into floats so they're useful
		x = std::stof(xs);
		y = std::stof(ys); 

		//do math
		if (this->type == mult_token) {
			z= y * x;

		} else if (this->type == div_token) {
			z =  y / x;

		} else if (this->type == add_token) {
			z = y + x;

		} else if (this->type == sub_token) {
			z=  y - x;
		}

		//return the result in a string because we were told to. 
		return std::to_string(z);
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
	return std::stof(s);
	//		? 
}