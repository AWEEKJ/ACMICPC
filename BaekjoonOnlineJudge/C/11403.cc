#include <cstdio>
int n;
int graph[101][101];
bool visited[101][101];

void dfs(int now, int next) {
  for (int i = 0; i < n; i++) {
    if (graph[now][i] == 1 && visited[next][i] == false) {
      visited[next][i] = true;
      dfs(i, next);
    }
  }
}

int main() {

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    dfs(i, i);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", visited[i][j]);
    }
    printf("\n");
  }
  return 0;
}
