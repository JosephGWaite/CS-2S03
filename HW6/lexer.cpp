#include "lexer.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

//This is sort of a parser at this point.
//Should be broken into parser.{h,cpp}

Token lex_op(std::istream&);  //{ = | - | * | / } //TODO add type
Token lex_num(std::istream&); // {digits}
Token lex_paren(std::istream&); // { ( | ) }

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

std::vector<Token> parse_char(std::istream& our_stream) {


	//skip over whitespace!!
	std::vector<Token> listOfTokens;

	// while (our_stream.peek() == ' ')
	// 	our_stream.ignore(1, ' ');


	//if (!our_stream) return idk

	char c;

	while (our_stream.get(c)) { //as long as we can grab a char then do our loop.
		our_stream.unget(); //put the char we grabbed back.

		if (c == ' ') { //Ignore whitespace.
			our_stream.get();

		} else if (c == '(') {
			listOfTokens.push_back(lex_paren(our_stream));

		} else if (c == ')') {
			listOfTokens.push_back(lex_paren(our_stream));

		} else if (isop(c)) {
			listOfTokens.push_back(lex_op(our_stream));

		} else if (std::isdigit(c)) {
			listOfTokens.push_back(lex_num(our_stream));
		} else {
			std::cout << "UNRECOGNISED CHAR";
			break;
		}
	}

	return listOfTokens;
}

//I'm going to do more here. l8ter tho bb

Token lex_num(std::istream& our_stream) {
	char c;
	our_stream.get(c);
	std::string number;
	number.push_back(c);
	while (std::isdigit(our_stream.peek())) {
		char x;
		our_stream.get(x);
		number.push_back(x);
	}
	return {num_token, number};
}

Token lex_op(std::istream& our_stream) {

	//This pos here is how stack says to do string coversion.
	//I assume that beacuse i have to do string conversion,
	// then I should restructure.
	//
	char c;
	our_stream.get(c);

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

Token lex_paren(std::istream& our_stream) {
	char c;
	our_stream.get(c);

	std::stringstream ss;
	std::string target;

	ss << c;
	ss >> target;

	switch (c) {
	case '(' :
		return {open_token, target};
		break;
	case ')' :
		return {close_token, target};
		break;
	}
}
