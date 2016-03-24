#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  int r, b;
  int l, w;
  int tmp_b, tmp_c;

  scanf("%d%d", &r, &b);

  tmp_b = (-1) * ((r + 4) / 2);
  tmp_c = r + b;

  if ((tmp_b * tmp_b - 4 * tmp_c) >= 0){
    l = ((-1 * tmp_b) + sqrt(tmp_b * tmp_b - 4 * tmp_c)) / 2;
    w = ((-1 * tmp_b) - sqrt(tmp_b * tmp_b - 4 * tmp_c)) / 2;
  }

  printf("%d %d", l, w);
  return 0;
}
