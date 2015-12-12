#ifndef ADDH
#define ADDH

#include <string>
#include "ArithmeticExpression.h"
class addition : public ArithmeticExpression {
	std::string evaluate();
	void print();
};

#endif