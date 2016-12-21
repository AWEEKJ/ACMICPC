#include <cstdio>
#include <algorithm>
using namespace std;

int binary_search(int arr[], int start, int end, int target) {
  int mid = (start + end) / 2;

  if (start > end) {
    return 0;
  }

  if (arr[mid] == target){
    return 1;
  } else if (arr[mid] > target) {
    return binary_search(arr, start, mid - 1, target);
  } else {
    return binary_search(arr, mid + 1, end, target);
  }
}

int main() {
  int n, m;

  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);

  scanf("%d", &m);
  int b[m];
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  for(int i = 0; i < m; i++) {
    printf("%d\n", binary_search(a, 0, n - 1, b[i]));
  }


  return 0;
}
