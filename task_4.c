#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void reverse(char s[], int len) {
  for (int i = 0; i < len/2; ++i) {
    char tmp = s[i]; 
    s[i] = s[len-i-1]; 
    s[len-i-1] = tmp;
  }
}

void convert_positive_to_binary(unsigned int n, char* output) {
  int len = 0; 
  while (n) {
    output[len] = '0' + n % 2; 
    n /= 2; 
    ++len; 
  }
  reverse(output, len);
}

void convert_to_binary(int n, char* output) {
  convert_positive_to_binary(abs(n), output+1); 
  output[0] = n >= 0 ? '+' : '-'; 
}

int get_binary_length(int n) {
  return floor(log2(n)) + 1;
}

int main() { 
  int n; 
  scanf("%d", &n); 
  char binary[get_binary_length(n)]; 
  convert_to_binary(n, binary); 
  printf("%s\n", binary[0] == '+' ? binary+1 : binary); 
  return 0; 
}
