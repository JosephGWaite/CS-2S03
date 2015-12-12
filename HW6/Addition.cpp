#include "Addition.h"
#include "string"

std::string Addition::evaluate()
{
	std::cout << "ADDITON EVAL CALL\n";
	float x, y, z;
	if (this->right == nullptr || this->left == nullptr) {
		return std::stof(this->value);
	} else {
		x = (this->left)->evaluate();
		y = (this->right)->evaluate();
		z = y + x;
		return std::to_string(z);
	}
}

void Addition::print()
{
	//things
}


