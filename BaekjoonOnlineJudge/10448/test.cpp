#include <cstdio>
int main() {
  int t;
  scanf("%d", &t);

  int a[50];
  int result[1001][4] = {};
  for (int i = 1; i <= 45; i++) {
    a[i] = i * (i + 1) / 2;
  }

  result[0][0] = 1;

  for (int sum = 1; sum <= 1000; sum++) {
    for (int i = 1; i <= 45 && a[i] <= sum; i++) {
      for (int j = 1; j <= 3; j++) {
        if (result[sum-a[i]][j-1]) result[sum][j] = 1;
      }
    }
  }

  while (t--) {
    int k;
    scanf("%d", &k);
    printf("%d\n", result[k][3]);
  }
  return 0;
}
