#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

  while(1) {
    if (n % 2 != 0) break;
    n /= 2;
    if (n == 1){
      printf("1\n");
      return 0;
    }
  }
  if (n == 1) printf("1\n");
  else printf("0\n");
  return 0;
}
