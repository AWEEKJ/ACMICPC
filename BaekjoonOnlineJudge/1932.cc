#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int t[510][510];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      scanf("%d", &t[i][j]);
    }
  }

  for (int i = n - 1; i > 0; i--) {
    for (int j = i; j > 0; j--) {
      t[i][j] += max(t[i+1][j], t[i+1][j+1]);
    }
  }
  printf("%d\n", t[1][1]);
  return 0;
}
