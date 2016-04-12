#include <cstdio>
#include <cstring>
using namespace std;

int w, h;
int map[55][55];
int visited[55][55];
int dir[2][8] = {
  {0, 1, 1, 1, 0, -1, -1, -1}, {1, 1, 0, -1, -1, -1, 0, 1}
};
int piece;
void dfs (int i, int j) {
  if (visited[i][j] || !map[i][j]) return;
  visited[i][j] = 1;
  for (int k = 0; k < 8; k++) {
    dfs(i + dir[0][k], j + dir[1][k]);
  }
  return;
}

int main() {
  while (scanf("%d%d", &w, &h)) {
    if (w == 0 && h == 0) break;

    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &map[i][j]);
      }
    }

    int piece = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (visited[i][j] == 0 && map[i][j] == 1) {
          piece++;
          printf("i: %d, j: %d, p: %d\n", i, j, piece);
          dfs(i, j);
        }
      }
    }

    printf("%d\n", piece);
  }
  return 0;
}
