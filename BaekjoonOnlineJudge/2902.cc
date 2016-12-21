#include <cstdio>
#include <cstring>

int main() {
  char input[101];
  scanf("%s", input);

  printf("%c", input[0]);
  for (int i = 0; i <= strlen(input); i++){
    if (input[i] == 45) {
      printf("%c", input[i+1]);
    }
  }
  printf("\n");
  return 0;
}
