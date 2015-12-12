#ifndef MULTH
#define MULTH 

#include <string>
#include "ArithmeticExpression.h"

class Multiplication : public ArithmeticExpression {
	std::string evaluate();
	void print();
};

#endif