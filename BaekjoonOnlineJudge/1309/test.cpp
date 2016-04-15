#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int i, j;
  long long x[n+1];
  for (i = 0; i < n; i++) scanf("%lld", &x[i]);

  long long sum = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      sum += abs(x[i] - x[j]);
    }
  }

  printf("%lld\n", sum * 2);
  return 0;
}
