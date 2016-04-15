#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("You get %d piece(s) and your dad gets %d piece(s).\n", n/m, n%m);
  }
  return 0;
}
