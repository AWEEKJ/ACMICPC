#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int p[n][2];
  vector<int> score(n, 1);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i][0], &p[i][1]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (p[i][0] < p[j][0] && p[i][1] < p[j][1]) {
        //printf("%d %d\n", score[i], j);
        score[i]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", score[i]);
  }

  return 0;
}
