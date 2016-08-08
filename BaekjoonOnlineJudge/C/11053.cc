#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);

  int a[1111];
  int memo[1111]; // memo[i] : i번째 원소를 마지막으로 하는 LIS 길이
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int i = 0; i < n; i++) {
    memo[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) memo[i] = max(memo[j]+1, memo[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, memo[i]);
  }
  printf("%d\n", ans);
  return 0;
}
