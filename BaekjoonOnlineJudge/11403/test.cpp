#include <cstdio>
#include <queue>
using namespace std;

int n;
int a[100][100];

int bfs(int start, int end) {

  int visited[n];
  queue<int> q;
  q.push(start);
  //visited[start] = 1;
  printf("%d ", start);

  int j = n;
  while(!q.empty() && j--){
    int now = q.front();
    q.pop();

    if (now == end) {
      return 1;
    }

    for (int i = 1; i <= n; i++) {
      if (a[now][i] == 1 && !visited[i]) {
        printf("%d ", i);
        q.push(i);
        visited[i] = 1;
      }
    }
  }
  return 0;
}

int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      bfs(i, j);
      //printf("%d ", bfs(i, j));
    }
    //printf("\n");
  }

  return 0;
}
