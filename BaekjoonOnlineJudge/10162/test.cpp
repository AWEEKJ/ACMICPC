#include <cstdio>
typedef struct button{
  int s_300;
  int s_60;
  int s_10;
}button;
int main() {
  int t;
  scanf("%d", &t);
  button b;
  b.s_300 = t / 300;
  b.s_60 = (t - 300 * b.s_300) / 60;
  b.s_10 = (t - 300 * b.s_300 - 60 * b.s_60) / 10;

  if (t != b.s_300 * 300 + b.s_60 * 60 + b.s_10 * 10) {
    printf("-1\n");
  } else {
    printf("%d %d %d\n", b.s_300, b.s_60, b.s_10);
  }
  return 0;
}
