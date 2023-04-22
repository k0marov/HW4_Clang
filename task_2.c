#include <stdio.h>

int main() { 
  int start, cnt; 
  scanf("%d %d", &start, &cnt); 

  for (int i = 0; i < start-1; ++i) {
    printf("   "); 
  }

  for (int i = 1; i <= cnt; ++i) {
    if (i < 10) printf(" ");
    printf("%d ", i);
    if ((i+start-1) % 7 == 0) printf("\n"); 
  }
  printf("\n");

  return 0; 
}
