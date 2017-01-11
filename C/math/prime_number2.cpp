#include <cstdio>

int main(){
  long long answer = 1;
  long long i;

  for (i = 1; i <= 61; i++){
    answer *= 2;
  }
  answer--;
  printf("%lld\n", answer);

  for (i = 3; i < 2147483648; i += 2){
    if (!(answer % i)) {
      printf("%lld // It's not a prime number!\n", i);
      return 0;
    }
  }
  printf("It's a prime number!\n");
  return 0;
}
