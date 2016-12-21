#include <stdio.h>

int list[10][4] ={{},{1}, {6, 2, 4, 8}, {1, 3, 9, 7},{6,4},{5},{6}, {1, 7, 9, 3}, {6, 8, 4, 2}, {1,9} };
int main(){
  int t;
  int a;
  int b;
  int answer;

  scanf("%d", &t);

  for(int i = 0; i < t; i++) {
    scanf("%d%d", &a, &b);
    int mod = a % 10;
    if (mod == 0){
      answer = 10;
    } else if (mod == 1 || mod == 5 || mod == 6){
      answer = mod;
    } else if (mod == 2 || mod == 3 || mod == 7 || mod == 8){
      b = b % 4;
      answer = list[mod][b];
    } else if (mod == 4 || mod == 9){
      b = b % 2;
      answer = list[mod][b];
    }

    printf("%d\n", answer);
  }
  return 0;
}
