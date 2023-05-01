#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int MINLEN = 8; 
const int MAXLEN = 14; 

// Since all passwords with length > 14 don't fit the reqiurements, 
// We can read just MAXLEN+1 characters. 
// (The other +1 is for the '\0' character)
const int MAXSIZE = MAXLEN+1+1;

const char MINCHAR = 33; 
const char MAXCHAR = 126; 

int validate_length(int len) {
  return len >= MINLEN && len <= MAXLEN; 
}

int validate_chars(char pass[], int len) {
  int has_lower=0, has_upper=0, has_digit=0, has_other=0; 
  for (int i = 0; i < len; ++i) {
    char c = pass[i]; 
    if (c < MINCHAR || c > MAXCHAR) {
      return 0; 
    }
    if (islower(c)) {
      has_lower = 1; 
    } else if (isupper(c)) {
      has_upper = 1; 
    } else if (isdigit(c)) {
      has_digit = 1; 
    } else {
      has_other = 1; 
    }
  }
  return (has_lower+has_upper+has_digit+has_other) >= 3; 
}

int validate_password(char pass[]) {
  int len = strlen(pass); 
  return validate_length(len) && validate_chars(pass, len); 
}

int main() { 
  char pass[MAXSIZE]; 
  scanf("%s", pass); 
  printf("%s\n", validate_password(pass) ? "YES" : "NO"); 
  return 0; 
}
