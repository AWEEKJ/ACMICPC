#include <cstdio>
#include <cstring>
// same as fibonacci, top down
const int MOD = 10007;
int n;
long long memo[1111];
long long solve (int n) {
  long long &ret = memo[n];
  if (n == 1) return 1;
  else if (n == 2) return 2;
  else if (ret != -1) return ret;

  ret = (solve(n-1) + solve(n-2)) % MOD;
  return ret;

}
int main() {
  scanf("%d", &n);
  memset(memo, -1, sizeof(memo));
  printf("%lld\n", solve(n));
  return 0;
}
