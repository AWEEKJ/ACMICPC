#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);

  if ((1 <= n)&&(n <= 100)){
    for (int i = 1; i <= 2 * n; i++){
      if (i % 2 == 1) {
        for (int j = 1; j <= n; j++){
          if (j % 2 == 1) printf("*");
          else if (j % 2 == 0) printf(" ");
        }
      } else if (i % 2 == 0){
        for (int j = 1; j <= n; j++){
          if (j % 2 == 1) printf(" ");
          else if (j % 2 == 0) printf("*");
        }
      }
      printf("\n");
    }
  }
  return 0;
}
