#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> list;
vector<int> target;
int list_size;
int target_size = 10;

void print_list() {
  for (int i = 0; i < list_size; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

// generate random number between 0 to 10000
void rand_list() {
    srand((unsigned int)time(NULL));
    list.resize(list_size, 0);
    for (int i = 0; i < list_size; i++) {
        list[i] = (int)(((double)rand() / ((double)RAND_MAX+1)*10000));
    }

    target.resize(list_size, 0);
    for (int i = 0; i < target_size; i++) {
        target[i] = (int)(((double)rand() / ((double)RAND_MAX+1)*10000));
    }
}

int binary_search(int x) {
  int low = 0;
  int high = list_size - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (list[mid] > x) high = mid -1;
    else if (list[mid] < x) low = mid + 1;
    else return mid;
  }
  return 0;
}


int main() {
  int num;

  printf("Input the number.");
  scanf("%d", &list_size);
  rand_list();
  //print_list();
  for (int i = 0; i < target_size; i++) {
    binary_search(target[i]);
  }
  //print_list();

  return 0;
}
