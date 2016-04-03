#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    char name[60];
    scanf("%s", name);
    printf("Hello, %s!\n", name);
  }
  return 0;
}
