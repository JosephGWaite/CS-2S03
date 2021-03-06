/*
Name:  Joseph Waite, Joel Straatman
MacID: waitejg, straatjc,
Student Number:  001403712, 001314676,
Description: scientific calculator with bonus
*/
#include "Subtraction.h"
#include <string>

std::string Subtraction::evaluate() 
{ 
	float x, y, z;
	if (this->right == nullptr || this->left == nullptr) {
		return std::stof(this->value);
	} else {
		x = (this->left)->evaluate();
		y = (this->right)->evaluate();
		z = y - x;
		return std::to_string(z);
	}
}

void Subtraction::print()
{
	//does things
} 