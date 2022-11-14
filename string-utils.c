#include <string.h>

int num_tokens(const char* s, const char* delim) {
  int n_tokens = 0;
  char _s[strlen(s)];
  strcpy(_s, s);
  //trim_whitespace(_s);
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
  char* _r;
  while(_r = strstr(s, replace_this)) {
    char* to_be_moved = _r + rt_len;
    strcpy(to_be_moved+diff, to_be_moved);
    strncpy(_r, with_this, wt_len);
  }
}
