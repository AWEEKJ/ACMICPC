#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int s[n];
  for (int i = 0; i < n; i++) scanf("%d", &s[i]);

  int memo[n]; // memo[i]: i번째 원소까지의 LIS
  for (int i = 0; i < n; i++) {
    memo[i] = 1;
    for (int j = i-1; j >= 0; j--) {
      if (s[j] < s[i]) {
        memo[i] = max(memo[j]+1, memo[i]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, memo[i]);
  }
  printf("%d\n", ans);

  return 0;
}
