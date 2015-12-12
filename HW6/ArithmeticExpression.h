#ifndef ARITHMETICEXPR
#define ARITHMETICEXPR

#include "Expression.h"

class ArithmeticExpression{
public:
	ArithmeticExpression *left;
	ArithmeticExpression *right;
	ArithmeticExpression *parent;

	int type;
	std::string value;

	float evaluate();

	void print();

	float convert(std::string);
};

#endif