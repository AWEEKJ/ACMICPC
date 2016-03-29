#include <stdio.h>

int main()
{
  int num;
  char PS[51];
  int i, j;
  int count;

  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    scanf("%s", PS);
    count = 0;

    if (PS[0] == ')') {
      printf("NO\n");
    } else {

      for (j = 0; PS[j]; j++) {
        if (PS[j] == '(') {
          count++;
        }
        if (PS[j] == ')') {
          if(count == 0) {
            break;
          }
          count--;
        }
      }
      puts(PS[j]||count?"NO":"YES");
    }
  }
}
