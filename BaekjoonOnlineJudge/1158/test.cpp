/*
  Runtime error
*/
#include <cstdio>
#include <list>
using namespace std;

int result[5001];
int cnt = 0;
list<int> l;
auto itor = l.begin();

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) l.push_back(i);

  while (!l.empty()){
    for (int i = 0; i < m; i++) {
      itor++;
      if (itor == l.end()){
        itor = l.begin();
      }
    }
    result[cnt++] = *itor;
    l.erase(itor);
  }
  printf("<");
  for (int i = 0; i < n - 1; i++) {
    printf("%d, ", result[i]);
  }
  printf("%d", result[n-1]);
  printf(">\n");
/*
  for (itor = l.begin(); itor != l.end(); itor++){
    printf("%d", *itor);
  }
*/
  return 0;
}
