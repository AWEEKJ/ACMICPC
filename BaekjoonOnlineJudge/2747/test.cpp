#include <cstdio>
#include <cstring>
using namespace std;

int memo[50];
int solve(int n) {
  int &ret = memo[n];
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (ret != -1) return ret;
  ret = solve(n-1) + solve(n-2);
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  memset(memo, -1, sizeof(memo));
  printf("%d\n", solve(n));
  return 0;
}
