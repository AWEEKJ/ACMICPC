#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int memo_2d[130];
  int memo_3d[130];
  int ans[333333];

  memo_2d[0] = 0;
  for (int i = 1; i <= 121; i++) {
    memo_2d[i] = i + memo_2d[i-1];
  }

  memo_3d[0] = 0;
  for (int i = 1; i <= 121; i++) {
    memo_3d[i] = memo_2d[i] + memo_3d[i-1];
  }
  memset(ans, -1, sizeof(ans));

  ans[0] = 0;
  for (int i = 1; i <= 120; i++) {
    ans[memo_3d[i]] = 1;
    for (int j = memo_3d[i]; j < memo_3d[i+1]; j++) {
      ans[j] = ans[j-memo_3d[i]] + 1 < ans[j-1] + 1 ? ans[j-memo_3d[i]] + 1: ans[j-1] + 1;
    }
  }
  printf("%d\n", ans[n]);
  return 0;
}
