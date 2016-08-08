#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char s[4111];
char t[4111];
int memo[4111][4111]; // memo[i][j] : s[i]=t[j]일때 해당 문자로 끝나는 공통 substring 의 최장 길이

int main() {
  scanf("%s", s);
  scanf("%s", t);
  memset(memo, 0, sizeof(memo));

  int s_len = strlen(s);
  int t_len = strlen(t);
  int ans = 0;

  for (int i = 0; i < s_len; i++) {
    for (int j = 0; j < t_len; j++) {
      if (s[i] != t[j]) memo[i][j] = 0;
      else {
        if (i == 0 || j == 0) memo[i][j] = 1;
        else memo[i][j] = memo[i-1][j-1] + 1;

        if (memo[i][j] > ans) ans = memo[i][j];
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
