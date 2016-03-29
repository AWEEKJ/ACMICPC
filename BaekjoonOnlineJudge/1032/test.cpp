#include <cstdio>

char file[51][51];
int main() {
  int n;
  char result[51];
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%s", file[i]);
  if (n == 1) {
    printf("%s\n", file[0]);
    return 0;
  }


  for (int j = 0; j < 51; j++) {
    for (int i = 1; i < n; i++) {
      //printf("file[%d][%d] = %c, file[%d][%d] = %c, ", i-1, j, file[i-1][j], i, j, file[i][j]);
      if (file[i-1][j] == file[i][j]) {
        result[j] = file[i][j];
        //printf(" result[%d] = %c\n", j, result[j]);
      }

      else {
        result[j] = '?';
        //printf(" result[%d] = %c\n", j, result[j]);
        break;
      }
    }
  }

  printf("%s\n", result);

  return 0;
}
