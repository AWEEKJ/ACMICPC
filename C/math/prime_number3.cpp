#include <cstdio>
// #include <iomanip>
// using namespace std;

bool isPrime(unsigned long long n){

  for (unsigned long long i = 2; i * i < n; i++){
    if (n % i == 0) return false;
  }
  return true;
}

unsigned long long power(unsigned long long n){
  unsigned long long result = 1;
  for (int i = 0; i < n; i++){
    result *= 2;
  }
  return result;
}

int main(){

  for (unsigned long long n = 2; n <= 61; n++){
      if (isPrime(n)){
        unsigned long long i = power(n) - 1;
        if (isPrime(i)){
          printf("%llu  %llu\n", n, i);
        }
      }
    }

  return 0;
}
