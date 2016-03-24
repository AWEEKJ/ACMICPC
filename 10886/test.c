#include "stdio.h"

int main() {
  int n;
  int opinion;
  int cute = 0;
  int not_cute = 0;

  scanf("%d", &n);

  if ((n % 2 == 1) && (1 <= n) && (n <= 101)){
    for (int i = 0; i < n; i++) {
      scanf("%d", &opinion);
      if (opinion == 1) cute++;
      else if (opinion == 0) not_cute++;
    }
    puts(cute > not_cute ? "Junhee is cute!" : "Junhee is not cute!");
  }
  return 0;
}
