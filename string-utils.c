#include <string.h>

#include "string-utils.h"

int num_tokens(const char* s, const char* delim) {
  int n_tokens = 0;
  char _s[strlen(s)];
  strcpy(_s, s);
  if(strtok(_s, delim)) ++n_tokens;
  else return 0;
  for(; strtok(NULL, delim); ++n_tokens);
  return n_tokens;
}

// returns NULL only if strtok returns NULL on first call
void strsplit(char* s, const char* delim, int n_tokens, char* tokens[n_tokens]) {
  if(n_tokens == 0) return;
  tokens[0] = strtok(s, delim);
  for(int i = 1; i < n_tokens; ++i)
    tokens[i] = strtok(NULL, delim);
}

void strreplace(char* s, const char* replace_this, const char* with_this) {
  const int rt_len = strlen(replace_this);
  const int wt_len = strlen(with_this);
  const int diff = wt_len - rt_len;
  for(char* _r; _r = strstr(s, replace_this);) {
    char* to_be_moved = _r + rt_len;
    strncpy(to_be_moved+diff, to_be_moved, strlen(to_be_moved));
    (to_be_moved+diff)[tbm_len] = '\0';
    strncpy(_r, with_this, wt_len);
  }
}

void strerase(char* s, const char* erase) {
  for(char e; e = *erase; ++erase) {
    for(char* _r; _r = strchr(s, e);) {
      for(int i = 0; _r[i]; ++i)
        _r[i] = _r[i+1];
    }
  }
}
