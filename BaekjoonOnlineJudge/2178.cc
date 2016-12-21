#include <cstdio>
#include <queue>
using namespace std;

typedef struct data{
  int x;
  int y;
  int cnt;
} data;
int dir[2][4] = {
  {1, -1, 0, 0},
  {0, 0, -1, 1}
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  char map[n+1][m+1];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &map[i][j]);
      map[i][j]-=48;
    }
  }

  queue<data> q;
  data start;
  start.x = 0;
  start.y = 0;
  start.cnt = 1;
  q.push(start);

  while (!q.empty()){
    int qSize = q.size();
    while (qSize--){
      data now = q.front();
      q.pop();

      if ((now.x == n - 1) && (now.y == m - 1)) {
        printf("%d\n", now.cnt);
        return 0;
      }
      //printf("%d %d %d %d\n", map[now.x][now.y], now.x, now.y, now.cnt);
      for (int i = 0; i < 4; i++){
        data tmp;
        tmp.x = now.x + dir[0][i];
        tmp.y = now.y + dir[1][i];
        tmp.cnt = now.cnt + 1;

        if ( !map[tmp.x][tmp.y] || (tmp.x < 0) || (tmp.y < 0) || (tmp.x >= n) || (tmp.y >= m))
          continue;

        map[tmp.x][tmp.y] = 0;
        q.push(tmp);
        //printf("%d %d %d %d\n", map[tmp.x][tmp.y], tmp.x, tmp.y, tmp.cnt);
      }
    }
  }
  return 0;
}
