#include <cstdio>
#include <algorithm>
using namespace std;

int minimum(int a, int b, int c) {
  if (a <= b && b <= c) return a;
  else if (a <= c && c <= b) return a;
  else if (c <= a && a <= b) return c;
  else if (b <= a && a <= c) return b;
  else if (b <= c && c <= a) return b;
  else if (c <= b && b <= a) return c;
}

int main() {
  int n;
  int memo[1111][4];
  int tmp[1111][4] = {0, };

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &memo[i][j]);
    }
  }
  if (n == 1) {
    printf("%d\n", minimum(memo[0][0], memo[0][1], memo[0][2]));
    return 0;
  }

  for (int i = 1; i < n; i++) {
    memo[i][0] += min(memo[i-1][1], memo[i-1][2]);
    memo[i][1] += min(memo[i-1][0], memo[i-1][2]);
    memo[i][2] += min(memo[i-1][0], memo[i-1][1]);
    //printf("%d %d %d\n", memo[i][0], memo[i][1], memo[i][2]);
  }
  printf("%d\n", minimum(memo[n-1][0], memo[n-1][1], memo[n-1][2]));
  return 0;
}
