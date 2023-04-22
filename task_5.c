#include <stdio.h>


int main() { 
  int sum = 0, n = -1, a = 0; 
  do {
    scanf("%d", &a); 
    sum += a; 
    ++n; 
  } while (a); 

  if (n) {
    printf("%f\n", (double)sum/n);
  } else {
    printf("Error: empty sequence entered.\n"); 
    return 1; 
  }

  return 0; 
}
