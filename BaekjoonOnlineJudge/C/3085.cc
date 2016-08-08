#include <cstdio>

int n;
char board[55][55];
int ans = 0;

void eat() {
  int candy = board[0][0];
  int row[n];
  int col[n];
  int i, j;
  for (i = 0; i < n; i++) {
    row[i] = 0;
    for (j = 0; j < n; j++) {
      if (candy == board[i][j]) {
        row[i]++;
        if (ans < row[i]) ans = row[i];
      }
      else {
        candy = board[i][j];
        row[i] = 1;
      }
    }
  }
  for (j = 0; j < n; j++) {
    col[j] = 0;
    for (i = 0; i < n; i++) {
      if (candy == board[i][j]) {
        col[j]++;
        if (ans < col[j]) ans = col[j];
      }
      else {
        candy = board[i][j];
        col[j] = 1;
      }
    }
  }
}

void swap() {
  int i, j;
  char tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      tmp = board[i][j];
      board[i][j] = board[i][j+1];
      board[i][j+1] = tmp;
      eat();
      tmp = board[i][j];
      board[i][j] = board[i][j+1];
      board[i][j+1] = tmp;
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n - 1; i++) {
      tmp = board[i][j];
      board[i][j] = board[i+1][j];
      board[i+1][j] = tmp;
      eat();
      tmp = board[i][j];
      board[i][j] = board[i+1][j];
      board[i+1][j] = tmp;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
      scanf("%s", board[i]);
  }
  swap();
  printf("%d\n", ans);

  return 0;
}
