#include <stdio.h>

int main(){
  char card[101][101];
  int r, c;
  int x, y;
  int i, j;
  char tmp;

  scanf("%d%d ", &r, &c);

  for (i = 0; i < r; i++){
    scanf("%s", card[i]);
  }

  for (i = 0; i < r; i++){
    for (j = c; j < 2 * c; j++){
      card[i][j] = card[i][2*c - j - 1];
    }
  }
  for (i = r; i < 2 * r; i++){
    for (j = 0; j < c; j++){
      card[i][j] = card[2*r - i - 1][j];
    }
  }
  for (i = r; i < 2 * r; i++){
    for (j = c; j < 2 * c; j++){
      card[i][j] = card[2*r - i - 1][2*c - j - 1];
    }
  }
  scanf("%d%d", &x, &y);
  tmp = card[x-1][y-1];
  if (tmp == '.') card[x-1][y-1] = '#';
  if (tmp == '#') card[x-1][y-1] = '.';

  for (i = 0; i < 2 * r; i++){
    for (j = 0; j < 2 * c; j++){
      printf("%c", card[i][j]);
    }
    printf("\n");
  }
  return 0;
}
