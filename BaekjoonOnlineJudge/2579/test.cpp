#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int s[310];
int memo[310][3]; // memo[n][i] : n번 계단에 오기 직전에 i개의 계단을 오름
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2; j++) {
      memo[i][j] = -1;
    }
  }
  memo[1][1] = s[1];
  memo[1][2] = 0;
  memo[2][1] = s[1] + s[2];
  memo[2][2] = s[2];
  for (int i = 3; i <= n; i++) {
    memo[i][1] = memo[i-1][2] + s[i];
    memo[i][2] = max(memo[i-2][1], memo[i-2][2]) + s[i];
  }

  printf("%d\n", max(memo[n][1], memo[n][2]));

  return 0;
}
