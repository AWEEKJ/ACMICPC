#include <cstdio>
#include <utility>
using namespace std;

typedef struct ant {
  int x;
  int y;
  int direction; // 1,2,3,4
} ant;

bool is_corner(int x, int y, int w, int h){
  if (((x == w) && (y == h)) || ((x == w) && (y == 0)) || ((x == 0) && (y == h)) || ((x == 0) && (y == 0))) return true;
  return false;
}
bool is_edge_h(int x, int y, int w, int h){
  if ((y == h) || (y == 0)) return true;
  return false;
}
bool is_edge_v(int x, int y, int w, int h){
  if ((x == w) || (x == 0)) return true;
  return false;
}

int main(){
  int w, h;
  int p, q;
  int t;
  scanf("%d%d%d%d%d", &w, &h, &p, &q, &t);

  ant now;
  now.x = p;
  now.y = q;
  now.direction = 1;

  for (int i = 1; i <= t; i++){
    switch (now.direction) {
      case 1: now.x++; now.y++; break;
      case 2: now.x++; now.y--; break;
      case 3: now.x--; now.y--; break;
      case 4: now.x--; now.y++; break;
      default: break;
    }
    //printf("%d %d %d %d\n", i, now.x, now.y, now.direction);
    if (is_corner(now.x, now.y, w, h)){
      switch (now.direction) {
        case 1: now.direction = 3; break;
        case 2: now.direction = 4; break;
        case 3: now.direction = 1; break;
        case 4: now.direction = 2; break;
        default: break;
      }
    }
    else if (is_edge_h(now.x, now.y, w, h)){
      switch (now.direction) {
        case 1: now.direction = 2; break;
        case 2: now.direction = 1; break;
        case 3: now.direction = 4; break;
        case 4: now.direction = 3; break;
        default: break;
      }
    }
    else if (is_edge_v(now.x, now.y, w, h)){
      switch (now.direction) {
        case 1: now.direction = 4; break;
        case 2: now.direction = 3; break;
        case 3: now.direction = 2; break;
        case 4: now.direction = 1; break;
        default: break;
      }
    }
  }

  printf("%d %d\n", now.x, now.y);

  return 0;
}
