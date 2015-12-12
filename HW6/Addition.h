#ifndef ADDH
#define ADDH

#include <string>
#include "ArithmeticExpression.h"
class Addition : public ArithmeticExpression {
	std::string evaluate();
	void print();
};

#endif