#include <stdio.h>

int main() {
  int score[6];
  int i;
  int sum = 0;
  for(i = 0; i < 5; i++){
    scanf("%d", &score[i]);
  }

  for(i = 0; i < 5; i++){
    if(score[i] < 40) score[i] = 40;
    sum += score[i];
  }

  printf("%d", sum/5);
  return 0;
}
