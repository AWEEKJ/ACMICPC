#include <stdio.h>

int main(){
  long long n, m;
  long long result;
  scanf("%lld", &n);
  scanf("%lld", &m);

  result = n-m;
  printf("%lld\n", result>0? n-m: m-n);

  return 0;
}
