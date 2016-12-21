#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    int c[n];
    double g[n];
    for (int i = 0; i < n; i++) scanf("%d%lf", &c[i], &g[i]);

    int csum = 0;
    for (int i = 0; i < n; i++) csum += c[i];
    printf("%d ", csum);

    double gsum = 0;
    for (int i = 0; i < n; i++) gsum += c[i] * g[i];
    printf("%.1lf\n", gsum/csum);
  }
  return 0;
}
