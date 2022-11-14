#ifndef string_utils
#define string_utils

#include <string.h>

int num_tokens(const char* s, const char* delim);
void strsplit(char* s, const char* delim, int n_tokens, char* tokens[]);
void strreplace(char* s, const char* replace_this, const char* with_this);
void strerase(char* s, const char* chars_to_erase);

#endif
