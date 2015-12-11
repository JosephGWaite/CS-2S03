class Multiply: public ArithmeticExpression { 

	string evaluate(&left_node, &right_node){ 
		return evaluate(left_node) * evaluate(right_node)
	} 
	void print(){ } // left `*` right
};

