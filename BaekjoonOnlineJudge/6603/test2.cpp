#include <cstdio>
// recursive method

int k;
int s[15];
int ans[6];

void solve(int idx, int cnt) {
  if (cnt == 6) {
    for (int i = 0; i < 6; i++) printf("%d ", ans[i]);
    printf("\n");
    return;
  }
  if (idx == k) return;

  ans[cnt] = s[idx];
  solve(idx+1, cnt+1);
  solve(idx+1, cnt);
}

int main() {
  while(scanf("%d", &k)) {
    if (k == 0) return 0;
    for (int i = 0; i < k; i++) scanf("%d", &s[i]);
    solve(0, 0);
    printf("\n");
  }
  return 0;
}
