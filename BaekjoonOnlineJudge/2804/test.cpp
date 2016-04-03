#include <cstdio>
#include <cstring>

char a[35];
char b[35];
int cross_a, cross_b;
int len_a, len_b;

int find_cross(){
  for (int i = 0; i < len_a; i++) {
    for (int j = 0; j < len_b; j++) {
      if (b[j] == a[i]) {
        cross_a = i;
        cross_b = j;
        return 0;
      }
    }
  }
  return 0;
}

int main() {
  scanf("%s%s", a, b);
  len_a = strlen(a);
  len_b = strlen(b);
  int tmp = find_cross();

  for (int i = 0; i < len_b; i++) {
    for (int j = 0; j < len_a; j++) {
      if (j == cross_a) printf("%c", b[i]);
      else if (i == cross_b) printf("%c", a[j]);
      else printf(".");
    }
    printf("\n");
  }

  return 0;
}
