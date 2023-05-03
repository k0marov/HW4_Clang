#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

long long find_sum(long long cache[], long long a[], long long n, long long i) {
  if (i > n-1) {
    return 0; 
  }
  if (cache[i] != -1) {
    return cache[i];
  }
  if (n - i <= 3) {
    return a[n - 1] - a[i];
  }
  long long best = -1; 
  if (i + 3 != n-1) {
    long long include = a[i + 2] - a[i + 1] + find_sum(cache, a, n, i + 3);
    best = include;
  }
  if (i + 2 != n-1) {
    long long exclude = find_sum(cache, a, n, i + 2);
    if (best == -1 || exclude < best) {
      best = exclude;
    }
  }
  best += a[i + 1] - a[i];
  cache[i] = best;
  return best;
}

// A compare function needed for qsort
int compare_long_long(const void *a, const void *b) {
  return *(long long *)a - *(long long *)b;
}

int main() {
  long long n;
  scanf("%lld", &n);
  long long a[n], cache[n];
  for (long long i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    cache[i] = -1;
  }

  qsort(a, n, sizeof(long long), compare_long_long);

  printf("%lld\n", find_sum(cache, a, n, 0));

  return 0;
}
