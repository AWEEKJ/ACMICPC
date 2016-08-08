#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int MAX = 1000000007;

int main() {
  int n; scanf("%d", &n);
  int m; scanf("%d", &m);

  int a[m]; for (int i = 0; i < m; i++) scanf("%d", &a[i]);

  vector<int> memo;

  for (int i = 0; i < m; i++) {
    memo.push_back(a[i]);
    sort(memo.begin(), memo.end());
    memo.erase(unique(memo.begin(), memo.end()), memo.end());
  }
  
  for (int t = 1; t < n; t++) {
    int mSize = memo.size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < mSize; j++) {
        int tmp = a[i] * memo[j] % MAX;
        memo.push_back(tmp);
      }
    }
    sort(memo.begin(), memo.end());
    memo.erase(unique(memo.begin(), memo.end()), memo.end());
  }
  int size = memo.size();
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += memo[i] % MAX;
  }
  printf("%d\n", sum);

  return 0;
}
