#include <cstdio>
using namespace std;

int main(){
  int score[6][5];
  int sum[5];
  int winner = 1;
  int winner_score = 0;
  int i, j;

  for (i = 1; i <= 5; i++){
    for (j = 1; j <= 4; j++){
      scanf("%d", &score[i][j]);
    }
  }

  for (i = 1; i <= 5; i++){
    sum[i] = 0;
    for (j = 1; j <= 4; j++){
      sum[i] += score[i][j];
    }
    if (sum[i] > winner_score){
      winner_score = sum[i];
      winner = i;
    }
  }

  printf("%d %d\n", winner, winner_score);

  return 0;
}
