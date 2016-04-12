#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a;
vector<int> b;
vector<int> tmp;

int binary_search(int x) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] > x) high = mid -1;
    else if (a[mid] < x) low = mid + 1;
    else return 1;
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  scanf("%d", &m);
  b.resize(m);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);

  sort(a.begin(), a.end());
  //merge_sort(0, n - 1);

  for (int i = 0; i < m; i++) {
    printf("%d ", binary_search(b[i]));
  }
  return 0;
}
