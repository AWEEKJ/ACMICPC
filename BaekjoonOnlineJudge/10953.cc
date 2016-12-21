#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  char input[5];
  while (t--) {
    scanf("%s", input);
    printf("%d\n", input[0] + input[2] - 96);
  }
  return 0;
}
