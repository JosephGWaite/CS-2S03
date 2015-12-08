#ifndef TOKEN_H 
#define TOKEN_H

#include <string>

// Value is not precedent. This has been flipped around a couple times
// precedence is determined 
int const open_token = 1;  // (
int const close_token = 2; // (
int const add_token = 3;   // + 
int const sub_token = 4;   // - 
int const div_token = 5;   // / 
int const mult_token = 6;  // * 
int const num_token = 7;   // 1,2,3,4,5,6,7,8,9,
int const eol_token =8;
 
struct Token { 
	int type; 
	std::string value;
};

#endif 