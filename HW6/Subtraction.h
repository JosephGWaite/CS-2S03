#ifndef SUBH
#define SUBH

#include <string>
#include "ArithmeticExpression.h"

class Subtraction : public ArithmeticExpression { 
	std::string evaluate();
	void print();
};

#endif 