#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main() {
  queue<int> q;
  int n;
  char f[6];
  int x;

  scanf("%d", &n);

  for (int i = 0; i < n; i++){
    scanf("%s", f);

    if(!strcmp(f,"push")) {
      scanf("%d", &x);
      q.push(x);
    }

    else if(!strcmp(f,"pop")) {
      if (q.empty()) printf("-1\n");
      else {
        printf("%d\n", q.front());
        q.pop();
      }
    }

    else if(!strcmp(f, "front")) {
      printf("%d\n", q.empty()?-1:q.front());
    }

    else if(!strcmp(f, "back")) {
      printf("%d\n", q.empty()?-1:q.back());
    }

    else if(!strcmp(f, "size")) {
      printf("%d\n", (int)q.size());
    }

    else if(!strcmp(f, "empty")) {
      printf("%d\n", q.empty());
    }
  }
  return 0;
}
