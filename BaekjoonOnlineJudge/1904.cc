#include <cstdio>
#include <cstring>
// same as fibonacci, bottom up
const int MOD = 15746;
int n;
int memo[1000111];
int main() {
  scanf("%d", &n);
  memset(memo, -1, sizeof(memo));
  memo[1] = 1;
  memo[2] = 2;
  if (n >= 3){
    for (int i = 3; i <= n; i++) {
      memo[i] = (memo[i-1] + memo[i-2]) % MOD;
    }
  }
  printf("%d", memo[n] % MOD);
  return 0;
}
