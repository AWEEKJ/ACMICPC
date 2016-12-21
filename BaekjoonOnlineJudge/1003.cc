#include <cstdio>

int d[2][50]; // 0 호출 횟수, 1 호출 횟수
int main() {
  d[0][0] = 1; d[0][1] = 0;
  d[1][0] = 0; d[1][1] = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 2; j < 50; j++) {
      d[i][j] = d[i][j-1] + d[i][j-2];
    }
  }
  int t; scanf("%d", &t);
  while (t--) {
    int n; scanf("%d", &n);
    printf("%d %d\n", d[0][n], d[1][n]);
  }
  return 0;
}
