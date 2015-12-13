/*
Name:  Joseph Waite, Joel Straatman
MacID: waitejg, straatjc,
Student Number:  001403712, 001314676,
Description: scientific calculator with bonus
*/

#include <string>
#include <iostream>
#include "ArithmeticExpression.h"
#include "token.h"
#include <iomanip> // for setprecision 
#include <sstream>

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
			z = y * x;

		} else if (this->type == div_token) {
			z =  y / x;

		} else if (this->type == add_token) {
			z = y + x;

		} else if (this->type == sub_token) {
			z =  y - x;
		}

		//return the result in a string because we were told to.
		std::ostringstream ss;
		ss << std::fixed << std::setprecision(2) << z;
		zs = ss.str();

		return zs;
	}
}

void ArithmeticExpression::print() {
	std::ostringstream ss;
	std::string zs;

	if (this->left != nullptr) {
		if ((this->value) == "+" || (this->value) == "-" || (this->value) == "*" || (this->value) == "/") {

			std::cout << "(";
			(this->right)->print();
			std::cout << " ";
			std::cout << (this->value);
			std::cout << " ";
			(this->left)->print();
			std::cout << ")";
		}
		else {
			ss << std::fixed << std::setprecision(2) << (this->value);
			zs = ss.str();

			std::cout << "zs" <<zs;
		}
	}
	else {
		ss << std::fixed << std::setprecision(2) << (this->value);
		zs = ss.str();
		std::cout << zs ;
	}
}

float ArithmeticExpression::convert(std::string s) {
	return std::stof(s);
	//		?
}