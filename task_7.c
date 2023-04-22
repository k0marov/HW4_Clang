#include <stdio.h>


int main() { 
  int n; 
  scanf("%d", &n); 
  int a, pos_cnt=0, zero_cnt=0, neg_cnt=0; 
  for (int _ = 0; _ < n; ++_) {
    scanf("%d", &a); 
    pos_cnt += a > 0; 
    zero_cnt += a == 0; 
    neg_cnt += a < 0; 
  }
  printf("%d %d %d\n", zero_cnt, pos_cnt, neg_cnt);

  return 0; 
}
