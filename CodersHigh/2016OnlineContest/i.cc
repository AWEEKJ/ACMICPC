#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int n, q;
int map[4111][4111];
queue<Pair> visit;
vector<Pair> dir;
int dir[2][6] = {{0, 1, 1, 0, -1, -1}, {1, 1, 0, -1, -1, 0}};

void printMap(int X, int Y, int R) {
  for (int i = X-R; i <= X+R; i++) {
    for (int j = Y-R; j <= Y+R; j++) {
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
}

void printVisited(int X, int Y, int R) {
  for (int i = X-R; i <= X+R; i++) {
    for (int j = Y-R; j <= Y+R; j++) {
      printf("%d ", visited[i][j]);
    }
    printf("\n");
  }
}

void f1(int X, int Y, int R) {

  dir.push_back(make_pair(0, 1));
  int x = X+2000;
  int y = Y+2000;

  visited[x][y] = 1;

  for (int t = 0; t < R; t++) {
    for (int i = x-t; i <= x+t; i++) {
      for (int j = y-t; j <= y+t; j++) {
        if (visited[i][j] == 1) {
          for (int k = 0; k < 6; k++) {
            if (visited[i+dir[0][k]][j+dir[1][k]] == 0) {
              visited[i+dir[0][k]][j+dir[1][k]] = 2;
            }
          }
        }
      }
    }

    for (int i = x-R; i <= x+R; i++) {
      for (int j = y-R; j <= y+R; j++) {
        if (visited[i][j] == 2) {
          visited[i][j] = 1;
        }
      }
    }
    //printVisited(x, y, R);
  }



  for (int i = x-R; i <= x+R; i++) {
    for (int j = y-R; j <= y+R; j++) {
      if (visited[i][j] == 1) {
        map[i][j] += 1;
      }
    }
  }
  //printMap(x, y, R);
}

int f2(int X, int Y) {
  return map[X+2000][Y+2000];
}

int main() {
  scanf("%d", &n);
  scanf("%d", &q);
  memset(map, 0, sizeof(map));

  for (int i = 0; i < q; i++) {
    int qType;
    scanf("%d", &qType);

    int x, y, r;

    if (qType == 1) {
      scanf("%d%d%d", &x, &y, &r);
      f1(y, x, r);
    }

    if (qType == 2) {
      scanf("%d%d", &x, &y);
      printf("%d\n", f2(y, x));
    }
  }
  return 0;
}
