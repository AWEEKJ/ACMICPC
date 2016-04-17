#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int s[n];
  for (int i = 0; i < n; i++) scanf("%d", &s[i]);

  // memo[i][0]: 앞에서부터 i번째 원소까지의 가장 긴 증가하는 부분 수열
  // memo[i][1]: 뒤에서부터 i번째 원소까지의 가장 긴 증가하는 부분 수열
  // memo[i][2]: i번째 원소까지의 가장 긴 바이토닉 부분 수열
  int memo[n][3];
  for (int i = 0; i < n; i++) {
    memo[i][0] = 1;
    for (int j = i-1; j >= 0; j--) {
      if (s[j] < s[i]) {
        memo[i][0] = max(memo[j][0]+1, memo[i][0]);
      }
    }
  }
  for (int i = n-1; i >= 0; i--) {
    memo[i][1] = 1;
    for (int j = i+1; j < n; j++) {
      if (s[i] > s[j]) {
        memo[i][1] = max(memo[j][1]+1, memo[i][1]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    memo[i][2] = memo[i][1] + memo[i][0] - 1;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, memo[i][2]);
  }
  printf("%d\n", ans);

  return 0;
}
