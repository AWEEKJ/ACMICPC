#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

  int memo[n];
  memo[0] = 0;
  memo[1] = memo[2] = 1;
  for (int i = 3; i <= n; i++) {
    memo[i] = memo[i-1] + memo[i-2];
  }
  printf("%d\n", memo[n]);
  return 0;
}
