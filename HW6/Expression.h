#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <ostream>

//We must use strings

class Expression{
	virtual std::string evaluate();
	virtual void print(); 
};


// inline std::ostream& operator<<(std::ostream$ os, Expression const& expr){
// 	expr.print(os);
// 	return os;
// }

#endif