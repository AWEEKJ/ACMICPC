#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int w, h;
vector<vector<char> > map;
vector<vector<bool> > visited;

int dir[2][4] = {
  {1, -1, 0, 0}, {0, 0, 1, -1}
};

int is_ok_visit(int i, int j) {
  return (i < 0) || (i >= h) || (j < 0) || (j >= w) || (map[i][j] == '#') || (map[i][j] == '*') || (visited[i][j] == true) ? 0 : 1;
}

int is_ok_escape(int i, int j) {
  return (i == 0) || (i == h - 1) || (j == 0) || (j == w - 1) ? 1 : 0;
}

int is_ok_fire(int i, int j) {
  return (i < 0) || (i >= h) || (j < 0) || (j >= w) || (map[i][j] == '#') || (map[i][j] == '*') ? 0 : 1;
}

void fire_move() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (map[i][j] == '*') {
        for (int k = 0; k < 4; k++) {
          int tmp_i = i + dir[0][k];
          int tmp_j = j + dir[1][k];
          if (is_ok_fire(tmp_i, tmp_j)) map[tmp_i][tmp_j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (map[i][j] == 1) {
        map[i][j] = '*';
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
  printf("\n");

}

int escape(int w, int h) {

  int i, j;
  int sx, sy;

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      scanf(" %c", &map[i][j]);
      if (map[i][j] == '@') {
        sx = i;
        sy = j;
      }
    }
  }

  queue<pair<int, int> > q;
  q.push(make_pair(sx, sy));
  visited[sx][sy] = true;
  int cnt«»;

  for (cnt = 2; ; cnt++){
    fire_move();
    int can_visit = 0;
    int q_size = q.size();

    while (q_size--) {
      pair<int, int> now = q.front();
      q.pop();
      for (i = 0; i < 4; i++) {
        pair<int, int> next;
        next.first = now.first + dir[0][i];
        next.second = now.second + dir[1][i];

        if (is_ok_visit(next.first, next.second)) {
          visited[next.first][next.second] = true;
          q.push(next);
          can_visit = 1;
          //printf("%d, %d, %d\n", cnt, next.first, next.second);

          if (is_ok_escape(next.first, next.second)) {
            printf("%d\n", cnt);
            return 0;
          }
        }
      }
    }
    if (can_visit == 0) break;
  }
  printf("IMPOSSIBLE\n");
  return 0;
}


int main() {
  int n;
  int result;
  for(scanf("%d", &n); n--; ) {
    scanf("%d%d", &w, &h);
    map.resize(h, vector<char>(w, 0));
    visited.resize(h, vector<bool>(w, false));
    result = escape(w, h);
  }
  return 0;
}
