#include <cstdio>
// iterative method
int main() {
  int k;
  while(scanf("%d", &k)) {
    if (k == 0) return 0;
    int s[15];

    for (int i = 0; i < k; i++) scanf("%d", &s[i]);

    int a, b, c, d, e, f;

    for(a = 0; a < k; a++){
      for(b = a + 1; b < k; b++){
        for(c = b + 1; c < k; c++){
          for(d = c + 1; d < k; d++){
            for(e = d + 1; e < k; e++){
              for(f = e + 1; f < k; f++){
                printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
              }
            }
          }
        }
      }
    }
    printf("\n");
  }
  return 0;
}
