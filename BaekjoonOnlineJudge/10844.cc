#include <cstdio>
#include <cstring>
int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  long long memo[10]; // memo[i] = 1의 자리가 i인 수의 개수
  long long tmp[10];
  memset(tmp, 0, sizeof(tmp));

  memo[0] = 0;
  for (i = 1; i <= 9; i++) memo[i] = 1;

  for (i = 1; i < n; i++) {
    tmp[0] = memo[1];
    for (j = 1; j <= 8; j++) {
      tmp[j] = (memo[j-1] + memo[j+1]) % 1000000000;
    }
    tmp[9] = memo[8];

    for (j = 0; j < 10; j++) memo[j] = tmp[j];
  }
  long long ans = 0;
  for (i = 0; i < 10; i++) ans += memo[i];
  printf("%lld\n", ans % 1000000000);

  return 0;
}
