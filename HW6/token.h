#ifndef TOKEN_H 
#define TOKEN_H

#include <string>

int const open_token = 0;  // (
int const close_token = 1; // (
int const add_token = 2;   // + 
int const sub_token = 3;   // - 
int const div_token = 4;   // / 
int const mult_token = 5;  // * 
int const num_token = 6;   // 1,2,3,4,5,6,7,8,9,
int const eol_token =7;
struct Token { 
	int type; 
	std::string value;
};

#endif 
