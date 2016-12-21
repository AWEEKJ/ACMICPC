#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct place {
  int x;
  int y;
  int r;
  int n;
};

int square (int a) {
  return a * a;
}

bool is_group(place a, place b) {
  // square of distance between a and b
  int sqd = square(a.x - b.x) + square(a.y - b.y);
  return (sqd > square(a.r + b.r)) ? false : true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    place map[3111];
    int group[3111];

    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &map[i].x, &map[i].y, &map[i].r);
    }

    for (int i = 1; i <= n; i++) map[i].n = i;

    for (int i = 1; i <= n; i++) {
      int flag = 0;
      for (int j = i; j <= n; j++) {
        if (is_group(map[i], map[j])) {
          map[i].n = map[j].n = min(map[i].n, map[j].n);
        }
      }
    }
    //for (int i = 1; i <= n; i++) printf("%d ", map[i].n);
    //printf("\n");

    memset(group, 0, sizeof(group));
    for (int i = 1; i<= n; i++) group[map[i].n] = 1;

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += group[i];
    printf("%d\n", ans);

  }
  return 0;
}

/*
1
15
220 0 1
5 0 1
1 0 1
9 0 1
20 0 5
21 1 5
19 0 2
100 0 3
3 0 1
300 0 1
99 0 1
98 0 1
102 0 1
400 0 1
8 1 1
*/
