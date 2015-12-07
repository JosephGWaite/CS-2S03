#ifndef TOKEN_H 
#define TOKEN_H

#include <string>

//Value is basically precedent. 
// it's used in the 
int const open_token = 7;  // (
int const close_token = 7; // (
int const add_token = 5;   // + 
int const sub_token = 5;   // - 
int const div_token = 6;   // / 
int const mult_token = 6;  // * 
int const num_token = 1;   // 1,2,3,4,5,6,7,8,9,
int const eol_token =7;
 
struct Token { 
	int type; 
	std::string value;
};

#endif 
