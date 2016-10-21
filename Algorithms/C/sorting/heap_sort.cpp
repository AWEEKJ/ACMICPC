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

void heap_sort(int arr[], unsigned int N) {
    if(N==0) return;

    int t;
    unsigned int n = N, parent = N/2, index, child;
    while (1) {
        if (parent > 0) {
            t = arr[--parent];
        } else {
            n--;
            if (n == 0) {
                return;
            }
            t = arr[n];
            arr[n] = arr[0];
        }
        index = parent;
        child = index * 2 + 1;
        while (child < n) {
            if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
                child++;
            }
            if (arr[child] > t) {
                arr[index] = arr[child];
                index = child;
                child = index * 2 + 1;
            } else {
                break;
            }
        }
        arr[index] = t;
    }
}

int main() {
  int list_size;
  printf("Input the size of list: ");
  scanf("%d", &list_size);

  int list[list_size];
  rand_list(list, list_size);
  heap_sort(list, list_size);

  return 0;
}
