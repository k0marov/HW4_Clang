#include <stdio.h>

int month_length(int month, int year) {
  if (month == 2) {
    int is_leap = !(year % 4) && (year % 100 || !(year % 400)); 
    return is_leap ? 29 : 28; 
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30; 
  } else {
    return 31; 
  }
}


int main() { 
  int month, year; 
  scanf("%d %d", &month, &year); 
  printf("%d\n", month_length(month, year));   
  return 0; 
}
