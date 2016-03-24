#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);

  if ((1 <= n)&&(n <= 100)){
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i - 1; j++){
        printf(" ");
      }
      printf("*");

      if (i) {
        for (int j = 0; j < i * 2 - 1; j++) {
          if (i == n - 1) printf("*");
          else printf(" ");
        }
        printf("*");
      }
      printf("\n");
    }
  }
  return 0;
}
