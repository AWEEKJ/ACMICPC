/*
  에라토스테네스의 채를 이용한 소수 구하기
*/
#include <stdio.h>

int main(){
  int testcase;
  char che[1000001];
  int prime[78102];
  long long i, j, k = 0;

  for (i = 2; i <= 1000000; i++){
    if (che[i] == 0){
      prime[k++] = i;
      for (j = i*i; j <= 1000000; j += i)che[j] = 1;
    }
  }
  for(;scanf("%d",&testcase),testcase;){
    for(i = 0; i <= (testcase/2); i++){
      if (che[testcase - prime[i]] == 0) {
        printf("%d = %d + %d\n",testcase, prime[i], testcase - prime[i]);
        break;
      }
    }
  }
  return 0;
}
