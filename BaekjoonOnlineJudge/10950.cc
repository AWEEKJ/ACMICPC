#include <cstdio>

int main() {
  int t;
  for (scanf("%d", &t); t--; ) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a+b);
  }
  return 0;
}
