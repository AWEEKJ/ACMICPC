#include <cstdio>

int main() {
  int w[10];
  int k[10];

  for (int i = 0; i < 10; i++) {
    scanf("%d", &w[i]);
  }
  for (int i = 0; i < 10; i++) {
    scanf("%d", &k[i]);
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9 - i; j++) {
      if (w[j] > w[j+1]) {
        int tmp_w = w[j];
        w[j] = w[j+1];
        w[j+1] = tmp_w;
      }
      if (k[j] > k[j+1]) {
        int tmp_k = k[j];
        k[j] = k[j+1];
        k[j+1] = tmp_k;
      }
    }
  }
  int score_w = 0;
  int score_k = 0;
  for (int i = 7; i < 10; i++) {
    score_w += w[i];
    score_k += k[i];
  }

  printf("%d %d\n", score_w, score_k);

  return 0;
}
