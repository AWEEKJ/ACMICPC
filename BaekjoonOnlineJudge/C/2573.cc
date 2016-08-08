#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int map[301][301];
int visited[301][301];
int dir[2][4] = {
  {0, 1, 0, -1}, {1, 0, -1, 0}
};

void dfs(int i, int j) {
  if(visited[i][j]) return;
  if(!map[i][j]) return;
  visited[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    dfs(i + dir[0][k], j + dir[1][k]);
  }
}

void melt() {
  int tmp[301][301] = {0, };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j]) {
        for (int k = 0; k < 4; k++) {
          if (map[i + dir[0][k]][j + dir[1][k]] == 0) {
            tmp[i][j]++;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      map[i][j] -= tmp[i][j];
      if (map[i][j] < 0) map[i][j] = 0;
    }
  }
}


int main() {
  int cnt = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  while(1) {
    cnt++;
    melt();

    int piece = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if(!visited[i][j] && map[i][j]) {
          piece++;
          dfs(i,j);
        }
      }
    }
    if (piece > 1) {
      printf("%d\n", cnt);
      break;
    }

    int check=0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(map[i][j] != 0){
          check++;
        }
      }
    }
    if(check==0){
      printf("0\n");
      break;
    }
  }
  return 0;
}
