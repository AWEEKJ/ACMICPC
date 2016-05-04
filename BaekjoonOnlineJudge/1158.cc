#include <cstdio>

int main() {
  int n, m;
  int list[5001];
  int i, j, k;

  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) list[i] = i+1;

  printf("<");
  for (i = -1, j = n; j; j--) {
    // x : index
    // j : # of elements in list
    i = (i + m) % j;
    if (j != 1) printf("%d, ", list[i]);
    else printf("%d", list[i]);
    for (k = i; k < j; k++) list[k] = list[k+1];
    i--;
  }
  printf(">");

  return 0;
}
