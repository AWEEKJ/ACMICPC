#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int s[2][100100];
int memo[2][100100]; // memo[i][j] : 뒤에서부터 선택하여 s[i][j]를 선택했을때의 최대값
int n;

int solve(int a, int b) {
  int &ret = memo[a][b];
  if (b > n) return 0;
  if (ret != -1) return ret;
  if (a==0) ret = max(solve(1, b+1), solve(1, b+2)) + s[a][b];
  else ret = max(solve(0, b+1), solve(0, b+2)) + s[a][b];
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    memset(s, 0, sizeof(s));
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &s[i][j]);
      }
    }

    printf("%d\n", max(solve(0, 0), solve(1, 0)));
    /*
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        printf("%d ", memo[i][j]);
      }
      printf("\n");
    }
    */
  }
  return 0;
}
