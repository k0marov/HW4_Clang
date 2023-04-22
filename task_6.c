#include <stdio.h>


int main() { 
  int n; 
  scanf("%d", &n); 
  int a, pos_cnt=0; 
  for (int _ = 0; _ < n; ++_) {
    scanf("%d", &a); 
    pos_cnt += a > 0; 
  }
  printf("%d\n", pos_cnt);

  return 0; 
}
