#include <cstdio>
int e, s, m;
int ans[3];
int cnt = 1;

void solve () {
  //printf("%d %d %d\n", ans[0], ans[1], ans[2]);
  while (1) {
    if (ans[0] == e && ans[1] == s && ans[2] == m) break;
    ans[0]++;
    ans[1]++;
    ans[2]++;
    if (ans[0] == 16) ans[0] = 1;
    if (ans[1] == 29) ans[1] = 1;
    if (ans[2] == 20) ans[2] = 1;
    cnt++;
    solve ();
  }
  //printf("%d\n", cnt);
}
int main() {
  scanf("%d%d%d", &e, &s, &m);
  ans[0] = ans[1] = ans[2] = 1;
  solve();
  printf("%d\n", cnt);
  return 0;
}
