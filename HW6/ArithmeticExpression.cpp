#include <string>
#include <iostream>
#include "Expression.h"
class ArithmeticExpression : public Expression {
public:
	ArithmeticExpression *left;
	ArithmeticExpression *right;
	ArithmeticExpression *parent;

	int type; //We'll use the same values as our tokens.
	std::string value;

	std::string evaluate() {
		//std::string x;
		//x.push_back(this->value);
		// x.push_back("  ");
		// x.push_back(evaluate(this->right));
		// x.push_back(evaluate(this->left));
		// return x;
		//return x;
	}

	void print() {
		std::cout << (this-> value) << std::endl;
		std::cout << "called" << std::endl;

		if (this->right != nullptr)
			(this->right)->print();

		if (this->left != nullptr)
			(this->left)->print();
	}

	float convert (std::string s) {
		//Converts a string (returned by evaluate) to a float
	}
};


