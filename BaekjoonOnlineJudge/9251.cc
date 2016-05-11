#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char s[1111];
char t[1111];
int memo[1111][1111]; // memo[i][j] : s[i]=t[j]일때 해당 문자로 끝나는 Longest Common Subsequence

int main() {
  scanf("%s", s);
  scanf("%s", t);
  memset(memo, 0, sizeof(memo));

  int s_len = strlen(s);
  int t_len = strlen(t);
  int ans = 0;

  for (int i = 0; i < s_len; i++) {
    for (int j = 0; j < t_len; j++) {
      int idx_i = i+1;
      int idx_j = j+1;
      if (s[i] != t[j]) memo[idx_i][idx_j] = max(memo[idx_i-1][idx_j], memo[idx_i][idx_j-1]);
      else memo[idx_i][idx_j] = memo[idx_i-1][idx_j-1] + 1;
    }
  }
  printf("%d\n", memo[s_len][t_len]);
  return 0;
}
