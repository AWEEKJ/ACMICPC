#include <stdio.h>

int main(){
  int nt;
  int Y, K;
  int win_Y, win_K;

  scanf("%d", &nt);

  for (int n = 0; n < nt; n++){
    win_Y = 0;
    win_K = 0;
    for (int i = 0; i < 9; i++){
      scanf("%d %d", &Y, &K);
      if (Y > K) win_Y += Y;
      else if (Y < K) win_K += K;
    }
    if (win_Y > win_K) printf("Yonsei\n");
    else if (win_Y < win_K) printf("Korea\n");
    else printf("Draw\n");
  }
  return 0;
}
