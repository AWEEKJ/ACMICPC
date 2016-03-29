#include <cstdio>
#include <queue>
using namespace std;

typedef struct knight{
  int x;
  int y;
  int cnt;
}knight;

int dir[2][8] = {
  {-2, -1, 1, 2, 2, 1, -1, -2},
  {1, 2, 2, 1, -1, -2, -2, -1}
};

int main() {
  int n;
  scanf("%d", &n);

  while (n--){
    int l;
    knight start;
    knight end;

    scanf("%d", &l);
    scanf("%d%d", &start.x, &start.y);
    scanf("%d%d", &end.x, &end.y);

    if ((start.x == end.x) && (start.y == end.y)) {
      printf("0\n");
      continue;
    }

    queue<knight> q;
    q.push(start);
    q.front().cnt = 0;
    bool visited[301][301] = {};
    visited[start.x][start.y] = true;

    while (!q.empty()){
      int qSize = q.size();
      while (qSize--){
        knight now = q.front();
        q.pop();

        if ((now.x == end.x) && (now.y == end.y)) {
          printf("%d\n", now.cnt);
          break;
        }

        for (int i = 0 ; i < 8; i++){
          knight tmp;
          tmp.x = now.x + dir[0][i];
          tmp.y = now.y + dir[1][i];
          tmp.cnt = now.cnt + 1;

          if (tmp.x < 0 || tmp.x >= l || tmp.y < 0 || tmp.y >= l || visited[tmp.x][tmp.y] == true) continue;
          visited[tmp.x][tmp.y] = true;
          q.push(tmp);
        }
      }
    }
  }
  return 0;
}
