#include <cstdio>

int main() {
  int n;
  for (scanf("%d", &n); n > 0; n--){
    char m[100001] = {};
    scanf("%s", m);

    int i, j;
    int check[26] = {};

    for (i = 0; m[i]; i++){
      j = m[i] - 'A';
      check[j] += 1;
      if (check[j] >= 3 && (check[j] % 4 == 3) && m[i] != m[i+1]) break;
    }
    printf("%s\n", !m[i]?"OK":"FAKE");
  }
  return 0;
}
