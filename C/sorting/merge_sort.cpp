#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_list(int arr[], unsigned int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// generate random number between 0 to 10000
void rand_list(int arr[], unsigned int N) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = (int)(((double)rand() / ((double)RAND_MAX+1)*10000));
    }
}

void merge(int arr[], int N, int start, int end) {
  int tmp[N];
  int mid = (start + end) / 2;
  int i = start;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
    else tmp[k++] = arr[j++];
  }

  while (i <= mid) tmp[k++] = arr[i++];
  while (j <= end) tmp[k++] = arr[j++];

  for (i = start, j = 0; i <= end; i++, j++)
    arr[i] = tmp[j];

}

void merge_sort(int arr[], int N, int start, int end) {
  int mid;
  if (start < end) {
    mid = (start + end) / 2;
    merge_sort(arr, N, start, mid);
    merge_sort(arr, N, mid + 1, end);
    merge(arr, N, start, end);
  }
}

int main() {
  int list_size;
  printf("Input the size of list: ");
  scanf("%d", &list_size);

  int list[list_size];
  rand_list(list, list_size);
  merge_sort(list, list_size, 0, list_size - 1);
  //print_list(list, list_size);

  return 0;
}
