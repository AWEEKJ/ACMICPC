#include <stdio.h>

int main(){
  int n;

  scanf("%d", &n);
  if ((1 <= n)&&(n <= 100)){
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (i % 2 == 0){
          printf(" ");
          printf("*");
        }
        if (i % 2 == 1){
          printf("*");
          printf(" ");
        }
      }
      printf("\n");
    }
  }
  return 0;
}
