#include <cstdio>

long long memo[111];
long long solve (int n) {
  long long &ret = memo[n];
  if (n == 1 || n == 2) return 1;
  if (ret != -1) return ret;
  ret = solve(n - 1) + solve(n - 2);
  return ret;
}
int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < 111; i++) memo[i] = -1;
  printf("%lld\n", solve(n));
  return 0;
}
