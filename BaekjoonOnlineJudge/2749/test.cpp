#include <cstdio>
#include <cstring>
using namespace std;

long long memo[100];
long long solve(int n) {
  long long &ret = memo[n];
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (ret != -1) return ret;
  ret = (solve(n-1) + solve(n-2));
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  memset(memo, -1, sizeof(memo));
  printf("%lld\n", solve(n));
  return 0;
}
