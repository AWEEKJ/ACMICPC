#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int start, end;
  int tmp = 1;
  int sum = 0;

  vector<int> number;
  number.resize(1234, 0);

  scanf("%d%d", &start, &end);

  for (int i = 1; tmp <= 1000; i++) {
    int j = i;
    while (j > 0){
      number[tmp] = i;
      //printf("%d %d\n", tmp, number[tmp]);
      tmp++;
      j--;
    }
  }

  if (start == end) {
    printf("%d\n", number[start]);
  }
  else {
    for (int i = start; i <= end; i++){
      sum += number[i];
    }
    printf("%d\n", sum);
  }
  return 0;
}
