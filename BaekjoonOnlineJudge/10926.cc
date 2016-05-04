#include <cstdio>
#include <cstring>

int main() {
  char input[100];
  scanf("%s", input);
  strcat(input, "\?\?!");

  printf("%s\n", input);

  return 0;
}
