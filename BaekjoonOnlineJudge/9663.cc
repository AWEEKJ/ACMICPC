#include <cstdio>

int n;
int map[16][16];
int column[16];
int ans;

int is_ok(int row, int col) {
  int i, j;
  for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) if (map[i][j]) return 0;
  for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) if (map[i][j]) return 0;
  for (i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) if (map[i][j]) return 0;
  for (i = row + 1, j = col + 1; i < n && j < n; i++, j++) if (map[i][j]) return 0;
  return 1;
}
void dfs(int num, int row) {
  if (num == n) {
    ans++;
  }
  for (int i = 0; i < n; i++) {
    if (!column[i] && is_ok(row, i)) {
      column[i] = 1;
      map[row][i] = 1;
      dfs(num + 1, row + 1);
      map[row][i] = 0;
      column[i] = 0;
    }
  }
}
int main() {
  scanf("%d", &n);
  dfs(0, 0);
  printf("%d\n", ans);
  return 0;
}
