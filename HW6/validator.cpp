/*
Name:  Joseph Waite, Joel Straatman
MacID: waitejg, straatjc,
Student Number:  001403712, 001314676,
Description: scientific calculator with bonus
*/
#include "token.h"
#include <vector>
#include <iostream>
bool errorMessage()
{
	std::cout << "Expression is not well formed.";
	return false;
}

bool validator(std::vector<Token> input)
{
	//Set up counters for parentheses. Used to check equal numbers of each.

	int close_counter = 0;
	int open_counter = 0;

	//First character can only be a number or an open parentheses

	if (input[0].type != num_token && input[0].type != open_token) {
		return errorMessage();
	}

	for (int i = 0; i < input.size(); i++) {

		//Weed out all invalid instances of "+", "*", and "/".
		//"+" "*", and "/" can only be preceded by a number or a parentheses
		//"+" "*", and "/" can only be followed by a number or a parentheses

		if (input[i].type == add_token || input[i].type == mult_token || input[i].type == div_token) {
			if (input[i - 1].type != num_token && input[i - 1].type != close_token) {
				return errorMessage();
			}
			if (input[i + 1].type != num_token && input[i + 1].type != open_token) {
				return errorMessage();
			}
		}

		//"-" will be handled slightly differently, since it is also used to denote negative numbers
		//Two valid cases are added:
		//(  "-"  "number"  )
		//(  "-"  (

		if (input[i].type == sub_token) {
			if (input[i - 1].type != num_token && input[i - 1].type != close_token && input[i - 1].type != open_token) {
				return errorMessage();
			}
			if (input[i - 1].type == open_token) {
				if ((input[i + 1].type != num_token || input[i + 2].type != close_token) && input[i + 1].type != open_token) {
					return errorMessage();
				}
			}
		}

		//A number cannot be preceded or followed by another number
		//Also must check if number is first in vector to avoid errors

		if (input[i].type == num_token) {
			if (i == 0) {
				if (input[i + 1].type == num_token) {
					return errorMessage();
				}
			}
			else
			{
				if (input[i - 1].type == num_token || input[i + 1].type == num_token) {
					return errorMessage();
				}
			}
		}

		//Count the number of each type of parentheses

		if (input[i].type == open_token) {
			open_counter++;
		}
		if (input[i].type == close_token) {
			close_counter++;
		}
	}

	//Compare amounts of parentheses

	if (open_counter != close_counter) {
		return errorMessage();
	}

	return true; 
}
