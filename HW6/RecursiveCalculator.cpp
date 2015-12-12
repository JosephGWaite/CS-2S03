#include "token.h"
#include <iostream>
#include <vector>

using namespace std;

double recurCalc(std::vector<Token> &vec, int n)

//Recursively calculates any postfix expression.
//
//'int n' is the length of the token vector, calculate separately beforehand.
//
//I'm reusing ')' as an escape character. It it just there to signify that
//this token has already been used, move onto the next one. Not sure if I'm
//doing that replacement properly, could be changed for improvement.
//Maybe a whole new character could be added.
//
//Disclaimer: 	This function actually changes the token vector. It 
//				may be wise to create a copy of the original vector,
//				or at least perform all necessary actions on the 
//				original before calling this function.
//
//TO DO:
//1. It's functional without OOP, but needs to be changed to include all the class
//   files and their methods to please based borzoo.
//2. Not sure if your lexer deals with empty inputs or not. If it doesn't, put a 
//   condition in here to deal with that.
//3. Just in a temporary file for now. I'm sure this could be put elsewhere to
//   minimize header files and reduce length of makefile.
//4. Doesn't compile. All errors are due to the fact that I don't know how to
//   play with tokens to make them do my bidding. fuck

{
	if (vec[n].type == num_token)
	{
		int temp = vec[n];
		vec[n] = {open_token, ')'}
		return (double)temp;
	}
	else if(vec[n].type == close_token)
	{
		return recurCalc(vec, n-1);
	}
	else if(vec[n].type == add_token)
	{
		vec[n] = ')';
		return recurCalc(vec, n-1) + recurCalc(vec, n-2);
	}	
	else if(vec[n].type == sub_token)
	{
		vec[n] = ')';
		return recurCalc(vec, n-1) - recurCalc(vec, n-2);
	}
	else if(vec[n].type == mult_token)
	{
		vec[n] = ')';
		return recurCalc(vec, n-1) * recurCalc(vec, n-2);
	}
	else 
	{
		vec[n] = ')';
		return recurCalc(vec, n-1) / recurCalc(vec, n-2);
	}
}

int main()
{
	return 0;
}