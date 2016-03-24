#include <stdio.h>

int main(){
  int n;
  long sum = 0;
  int i;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++){
    sum += i;
  }
  printf("%d", sum);
  return 0;
}
