#include <stdio.h>

int memo[11];
int sum(int n) {
  if (n == 1){
    return 1;
  } else if (n == 2){
    return 2;
  } else if (n == 3){
    return 4;
  } else if (memo[n] != 0) {
    return memo[n];
  } else {
    return memo[n] = sum(n-1) + sum(n-2) + sum(n-3);
  }
}

int main() {
  int num;
  int i;
  int d;

  scanf("%d", &num);
  for (i = 0; i < num; i++){
    scanf("%d", &d);
    printf("%d\n", sum(d));
  }
}
