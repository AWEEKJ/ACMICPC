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

void quick_sort(int arr[], int start, int end) {
  int left, right, pivot, tmp;
  if (start >= end) return;
  else if (start < end) {
    pivot = start;
    left = start;
    right = end;

    while(left < right) {
      while (arr[left] <= arr[pivot] && left < end) left++;
      while (arr[right] > arr[pivot] && start < right) right--;
      if (left < right) {
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
      }
    }
    tmp = arr[pivot];
    arr[pivot] = arr[right];
    arr[right] = tmp;
    quick_sort(arr, start, right - 1);
    quick_sort(arr, right + 1, end);
  }
}

int main() {
  int list_size;
  printf("Input the size of list: ");
  scanf("%d", &list_size);

  int list[list_size];
  rand_list(list, list_size);
  quick_sort(list, 0, list_size);
  //print_list(list, list_size);

  return 0;
}
