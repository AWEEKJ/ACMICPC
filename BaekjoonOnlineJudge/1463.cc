#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  
  //  memo[n] : n을 1로 만드는데 필요한 최소 연산
  int memo[n+1];
  memo[1] = 0;
  memo[2] = memo[3] = 1;

  for (int i = 4; i <= n; i++) {
    if (i % 3 == 0) memo[i] = memo[i/3] + 1;
    else if (i % 2 == 0) memo[i] = min(memo[i/2], memo[i-1]) + 1;
    else memo[i] = memo[i-1] + 1;
    //printf("%d %d\n", i, memo[i]);
  }
  printf("%d\n", memo[n]);
  return 0;
}
