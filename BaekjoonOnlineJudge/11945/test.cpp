#include <cstdio>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  char a[n][m+1];
  for (int i = 0; i < n; i++) {
    for (int j = m; j >= 0; j--) {
      scanf("%c", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
