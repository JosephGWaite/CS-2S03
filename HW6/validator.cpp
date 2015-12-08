#include "token.h"
#include <vector>
#include <iostream>
void errorMessage(int type)
{
	if (type == 1)
	{
		std::cout << "ERROR: Invalid first character.";
	}
	if (type == 2)
	{
		std::cout << "ERROR: Invalid operator usage";
	}
	if (type == 3)
	{
		std::cout << "ERROR: Two adjacent numbers";
	}
	if (type == 4)
	{
		std::cout << "ERROR: Unbalanced parentheses";
	}
}

void validator(std::vector<Token> input)
{
	//Set up counters for parentheses. Used to check equal numbers of each.

	int close_counter = 0;
	int open_counter = 0;

	//First character can only be a number or an open parentheses

	if (input[0].type != num_token && input[0].type != open_token)
	{
		errorMessage(1);
	}
	
	for (int i = 0; i<input.size(); i++)
	{

	//Weed out all invalid instances of "+", "*", and "/". 
	//"+" "*", and "/" can only be preceded by a number or a parentheses 
	//"+" "*", and "/" can only be followed by a number or a parentheses
	
		if (input[i].type == add_token || input[i].type == mult_token || input[i].type == div_token)
		{
			if (input[i-1].type != num_token && input[i-1].type != close_token)
			{
				errorMessage(2);
			}
			if (input[i+1].type != num_token && input[i+1].type != open_token)
			{
				errorMessage(2);
			}
		}
	
	//"-" will be handled slightly differently, since it is also used to denote negative numbers
	//Two valid cases are added:
	//(  "-"  "number"  )
	//(  "-"  (

		if (input[i].type == sub_token)
		{
			if (input[i-1].type != num_token && input[i-1].type != close_token && input[i-1].type != open_token)
			{
				errorMessage(2);
			}
			if (input[i-1].type == open_token)
			{
				if ((input[i+1].type != num_token || input[i+2].type != close_token) && input[i+1].type != open_token)
				{
					errorMessage(2);
				}
			}
		}
	
	//A number cannot be preceded or followed by another number
	//Also must check if number is first in vector to avoid errors
	
		if (input[i].type == num_token)
		{
			if (i==0)
			{
				if (input[i+1].type == num_token)
				{
					errorMessage(3);
				}
			}
			else
			{
				if (input[i-1].type == num_token || input[i+1].type == num_token)
				{
					errorMessage(3);
				}
			}
		}

	//Count the number of each type of parentheses

		if (input[i].type == open_token)
		{
			open_counter++;
		}	
		if (input[i].type == close_token)
		{
			close_counter++;
		}
	}

	//Compare amounts of parentheses

	if (open_counter != close_counter)
	{
		errorMessage(4);
	}
}

int main()
{
	return 0;
}