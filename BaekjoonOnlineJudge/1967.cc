#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int tree[10001][10001];

int cal_cost(int start, int end, int n) {
  int result = 0;
  queue<int> q;
  vector<int> visited;
  vector<int> tmp_cost;

  visited.resize(n+1, 0);
  tmp_cost.resize(n+1, 0);

  if(start == end) return 0;

  q.push(start);
  visited[start] = 1;

  while (!q.empty()){
    int now = q.front();
    q.pop();

    for (int i = 1; i <= n; i++) {
      if (now == i) continue;
      if (visited[i]) continue;
      if (tree[now][i] > 0){
        tmp_cost[i] = tmp_cost[now] + tree[now][i];
        //printf("%d -> %d /// %d -> %d, cost: %d, total: %d\n", start, end, now, i, tree[now][i], tmp_cost[i]);
        if (i == end) {
          return tmp_cost[i];
          break;
        }
        visited[i] = 1;
        q.push(i);
      }
    }
  }
  return tmp_cost[end];
}

int main() {
  int n;
  int i, j;
  int tmp_i, tmp_j, tmp_len;
  int max = 0;

  scanf("%d", &n);

  for (i = 1; i <= n - 1; i++) {
    scanf("%d%d%d", &tmp_i, &tmp_j, &tmp_len);
    tree[tmp_i][tmp_j] = tmp_len;
    tree[tmp_j][tmp_i] = tmp_len;
  }

  int cost[n+1][n+1];

  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++){
      cost[i][j] = cal_cost(i, j, n);
      if (cost[i][j] > max) max = cost[i][j];
      //printf("%d ", cost[i][j]);
    }
    //printf("\n");
  }

  printf("%d\n", max);

  return 0;
}
