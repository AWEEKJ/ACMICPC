#include <cstdio>

int main() {
  int n; scanf("%d", &n);
  int s[3];
  s[0] = n / 10; s[1] = n % 10;

  int cnt = 0;

  while (1) {
    cnt++;
    int tmp = s[1];
    s[1] = (s[0] + s[1]) % 10;
    s[0] = tmp;
    if (s[0] * 10 + s[1] == n) break;
  }

  printf("%d\n", cnt);

  return 0;
}
