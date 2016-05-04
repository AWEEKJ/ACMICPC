#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<pair<int, int> > s;
  for (int i = 0; i < n; i++) {
    pair<int, int> tmp;
    scanf("%d%d", &tmp.first, &tmp.second);
    s.push_back(tmp);
  }
  sort(s.begin(), s.end());

  int memo[n]; // memo[i]: i번째 원소까지의 LIS
  for (int i = 0; i < n; i++) {
    memo[i] = 1;
    for (int j = i-1; j >= 0; j--) {
      if (s[j].second < s[i].second) {
        memo[i] = max(memo[j]+1, memo[i]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, memo[i]);
  }
  printf("%d\n", n-ans);

  return 0;
}
