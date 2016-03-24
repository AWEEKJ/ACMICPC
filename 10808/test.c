#include <stdio.h>
#include <string.h>

char alpabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main() {
  char s[101];
  int count = 0;
  scanf("%s", s);

  for (int j = 0; j < 26; j++){
    for (int i = 0; i < strlen(s); i++){
      if (s[i] == alpabet[j]) count++;
    }
    printf("%d ", count);
    count = 0;
  }

  return 0;
}
