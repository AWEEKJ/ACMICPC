#include <cstdio>
#include <vector>
using namespace std;

int w, h;
vector<vector<int> > map;
int dir[2][8] = {
  {0, 1, 1, 1, 0, -1, -1, -1}, {1, 1, 0, -1, -1, -1, 0, 1}
};

void print_maze(){
	printf("\n");
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void f(int x, int y, int num) {
  print_maze();
  int nx, ny;
  for (int k = 0; k < 8; k++) {
    nx = x + dir[0][k];
    ny = y + dir[1][k];
    if (map[nx][ny] == 1) {
      map[nx][ny] = num;
      printf("add %d %d\n", nx, ny);
      f(nx, ny, num);
      map[nx][ny] = 0;
    }
  }
}

int main() {
  while(1){
    scanf("%d%d", &w, &h);
    if (w == 0 && h == 0) return 0;

    map.resize(h, vector<int> (w, 0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &map[i][j]);
      }
    }

    int island = 1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (map[i][j] == 1) {
          island++;
          map[i][j] = island;
          f(i, j, island);
        }
      }
    }
    printf("%d\n", island - 1);
  }
  return 0;
}
