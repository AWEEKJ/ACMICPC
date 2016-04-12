#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    char k[61];
    scanf("%s", k);
    int len = strlen(k);
    if (k[len-1] % 2 == 0) printf("even\n");
    if (k[len-1] % 2 == 1) printf("odd\n");
  }
  return 0;
}
