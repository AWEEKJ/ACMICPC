#include <cstdio>
#include <queue>
using namespace std;

int n;
int map[1001][1001];
int dfs_visited[1001];
int bfs_visited[1001];

void dfs(int v) {
  dfs_visited[v] = 1;
  for (int i = 1; i <= n ; i++) {
    if (map[v][i] == 1 && !dfs_visited[i]) {
      printf("%d ", i);
      dfs(i);
    }
  }
}

void bfs(int v) {
  queue<int> q;
  q.push(v);
  bfs_visited[v] = 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (map[now][i] == 1 && !bfs_visited[i]) {
        printf("%d ", i);
        q.push(i);
        bfs_visited[i] = 1;
      }
    }
  }
}

int main() {
  int m, v;
  scanf("%d%d%d", &n, &m, &v);

  while (m--) {
    int tmp1, tmp2;
    scanf("%d%d", &tmp1, &tmp2);
    map[tmp1][tmp2] = map[tmp2][tmp1] = 1;
  }

  printf("%d ", v);
  dfs(v);
  printf("\n");

  printf("%d ", v);
  bfs(v);
  printf("\n");

  return 0;
}
