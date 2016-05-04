#include <stdio.h>

int main(){
  int a, b;

  scanf("%d%d", &a, &b);

  if((0 < a) && (a < 10) && (0 < b) && (b < 10)){
    if ((a + b) < 10) {
      printf("%d", a + b);
    }
  }
  return 0;
}
