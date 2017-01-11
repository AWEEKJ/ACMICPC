#include <cstdio>
#include <vector>
using namespace std;

int main(){

  vector<char> che;
  vector<unsigned int> prime;
  long long answer = 1;
  long long i, j, k = 0;

  // 2의 61승 - 1 에 해당하는 수를 구함
  for (i = 1; i <= 61; i++){
    answer *= 2;
  }
  answer--;
  printf("%lld\n", answer);
  //2 ^ 61 -> 2305843009213693952
  //2 ^ 31 -> 2147483648

  // 에라토스테네스의 체를 이용하여 2의 31승 -1 까지의 소수를 구함
  che.resize(2147483648);
  prime.resize(105097565); // 0 ~ 105097564

  for (i = 2; i < 2147483648; i++){
    if (che[i] == 0){
      prime[k++] = i;
      for (j = i*i; j < 2147483648; j += i){
        che[j] = 1;
      }
    }
  }

  // 각각으로 나누어 보고 소수인지 판별
  for (i = 0; i < 105097565; i++){
    if (!(answer % prime[i])) {
      printf("%u // It's not a prime number!\n", prime[i]);
      return 0;
    }
  }
  printf("It's a prime number!\n");
  return 0;
}
