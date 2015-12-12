#include "lexer.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

//Currently a bunch of global functions used.

//

bool isop(char c) {
	std::string const ops = "+-*/"; //I'd like to add more. //but IDGAF
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

	std::vector<Token> listOfTokens;

	char c;
	char next;
	while (our_stream.get(c)) { //as long as we can grab a char then do our loop.
		next = our_stream.peek();
		our_stream.unget(); //put the char we grabbed back.


		if (c == ' ') { //Ignore whitespace.
			our_stream.get();

		} else if (c == '(' && next == '-' ) { //negative numbers (-70) - (-1)
			listOfTokens.push_back(lex_negnum(our_stream));

		} else if (c == '(') {
			listOfTokens.push_back(lex_paren(our_stream));

		} else if (c == ')') {
			listOfTokens.push_back(lex_paren(our_stream));

		} else if (isop(c)) {
			listOfTokens.push_back(lex_op(our_stream));

		} else if (std::isdigit(c)) {
			listOfTokens.push_back(lex_num(our_stream));
		} else {
			break;
		}
	}

	return listOfTokens;
}

//Returns a negative number token.
Token lex_negnum(std::istream& our_stream) {
	char c;
	our_stream.get(); //should be a paren. discard it. 
	our_stream.get(c); //should be a negative sign.

	std::string number;
	number.push_back(c); //push the negative sign onto the token. 
	while (std::isdigit(our_stream.peek())) { //pushes all following digits on the token. 
		char x;
		our_stream.get(x);
		number.push_back(x);
	}
	our_stream.get(); //should be closing paren. discard
	return {num_token, number};
}

//Returns a number token
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

//returns an operator token + - * /
Token lex_op(std::istream& our_stream) {

	char c;
	our_stream.get(c);

	//Stack says this is how to do (char -> string) conversion. 
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

// returns paren tokens 
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
