#include <cstdio>

int main() {
  long long a, b, c, d;
  long long sum = 0;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

  long long i = 1;
  while(1){
    if (b / i) {
      i *= 10;
    }
    else {
      break;
    }
  }
  sum += a * i + b;

  i = 1;
  while(1){
    if (d / i) {
      i *= 10;
    }
    else {
      break;
    }
  }
  sum += c * i + d;
  printf("%lld\n", sum);
  return 0;
}
