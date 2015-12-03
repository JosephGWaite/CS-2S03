#include "lexer.h"
#include <string>
#include <sstream>

//This is sort of a parser at this point.
//Should be broken into parser.{h,cpp}

Token lex_op(char);  //{ = | - | * | / } //TODO add type
Token lex_num(char); // {digits}
Token lex_paren(char); // { ( | ) }

bool isop(char c) {
	std::string const ops = "+-*/"; //I'd like to add more.
	if (ops.find(c) != std::string::npos)
		return true;
	else
		return false;
}

//parse a character, and return a token.
//It should just be printed at this point, but it should change
//	so we can make it into a tree.
//this should just be run on each char in the user input.

Token parse_char(char c) {
	if (std::isdigit(c))
		return lex_num(c);

	else if (isop(c)) {
		return lex_op(c);

	} else if (c == '(') {
		return lex_paren(c);

	} else if (c == ')') {
		return lex_paren(c);

	} else {
		// TODO: error handling. throw exception and catch at print?
		// maybe an error token?
		//
	}

}

//I'm going to do more here. l8ter tho bb

Token lex_num(char c) {
	return {num_token, c};
}

Token lex_op(char c) {

	//This pos here is how stack says to do string coversion.
	//I assume that beacuse i have to do string conversion,
	// then I should restructure. 
	// 
	// I actually have to bc lex_num can't take a number bigger than 9
	// fuck. TODO: ^^^ 
	std::stringstream ss;
	std::string target;

	ss << c;
	ss >> target;


	switch (c) {
	case '+':
		return {add_token, target};
		break; //do we need these breaks? prolly not
	case '-':
		return {sub_token, target};
		break;
	case '*':
		return {mult_token, target};
		break;
	case '/':
		return {div_token, target};
		break;
	}
}

Token lex_paren(char c) {
	switch (c) {
	case '(' :
		return {open_token, c};
		break;
	case ')' :
		return {close_token, c};
		break;
	}
}
