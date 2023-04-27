#include <math.h>
#include <stdio.h>

int main() { 
  int n; 
  scanf("%d", &n); 
  if (n < 0) {
    printf("-"); 
    n = -n; 
  }
  for (int i = floor(log2(n)); i >= 0; --i) {
    printf("%d", (1<<i & n)>>i); 
  }
  printf("\n"); 
  return 0; 
}
