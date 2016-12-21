#include <stdio.h>
int memo[21][21][21];

int w(int a, int b, int c){
  if ((a == -1) && (b == -1) && (c == -1)) return -1;
  else if (memo[a][b][c]) return memo[a][b][c];
  else if ((a <= 0) || (b <= 0) || (c <= 0)) return 1;
  else if ((a < b) && (b < c)) return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
  else if ((a > 20) || (b > 20) || (c > 20)) return w(20, 20, 20);
  else return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(){
  int a, b, c;
  int answer;
  int tmp;

  for (int i = 1; i <= 20; i++){
    for (int j = 1; j <= 20; j++){
      for (int k = 1; k <= 20; k++){
        tmp = w(i, j, k);
      }
    }
  }

  for (; scanf("%d%d%d", &a, &b, &c); ){
    answer = w(a, b, c);
    if (answer == -1) break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, answer);

  }
  return 0;
}
