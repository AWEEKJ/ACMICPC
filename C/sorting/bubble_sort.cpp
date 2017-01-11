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

void bubble_sort(int arr[], unsigned int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - (i+1); j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main() {
  int list_size;
  printf("Input the size of list: ");
  scanf("%d", &list_size);

  int list[list_size];
  rand_list(list, list_size);
  bubble_sort(list, list_size);
  //print_list(list, list_size);

  return 0;
}
