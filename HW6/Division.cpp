#include <cstring> 
class Divide : public ArithmeticExpression{
	
	string evaluate() {
		return this->evaluate(this->right) / evaluate(this->right)
	}

	void print(){} //left `/` right
	float convert (string s) { 
		//Converts String (returned by eval to float) 
	}
};
