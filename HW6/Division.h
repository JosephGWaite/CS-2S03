#ifndef DIVH
#define DIVH

#include <string>
#include "ArithmeticExpression.h"

class Division : public ArithmeticExpression{
	std::string evaluate();
	void print();
};

#endif