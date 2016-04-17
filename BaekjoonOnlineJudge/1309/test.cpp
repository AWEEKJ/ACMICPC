#include <cstdio>
// f(n) = f(n-1) * 2 + f(n-2)
int const MOD = 9901;

int main() {
  int n;
  scanf("%d", &n);

  int memo[n];
  memo[1] = 3;
  memo[2] = 7;
  for (int i = 3; i <= n; i++) {
    memo[i] = (memo[i-1] * 2 + memo[i-2]) % MOD;
  }

  printf("%d\n", memo[n]);
  return 0;
}
