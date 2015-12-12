#include "Subtraction.h"

Subtraction::evaluate() 
{ 
	return this->evaluate(this->left) - this->evaluate(this->right);
}

Subtraction::print()
{
	//does things
} 