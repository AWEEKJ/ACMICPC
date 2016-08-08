#include <cstdio>

int n, s;
int set[25];
bool visited[25];
int ans = 0;

void dfs(int idx, int sum) {
  if (sum == s && idx != 0) {
    ans += 1;
  }
  for (int i = idx + 1; i <= n; i++) {
    if(!visited[i]) {
      visited[i] = true;
      dfs(i, sum + set[i]);
      visited[i] = false;
    }
  }
}

int main() {
  scanf("%d%d", &n, &s);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &set[i]);
  }
  dfs(0, 0);
  printf("%d\n", ans);
  return 0;
}
