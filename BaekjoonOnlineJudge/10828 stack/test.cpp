#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int main(){
  stack<int> s;
  int n;
  char f[6];
  int x;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", f);

    if(!strcmp(f, "push")) {
      scanf("%d", &x);
      s.push(x);
    }

    else if(!strcmp(f, "pop")) {
      if (s.empty()) printf("-1\n");
      else {
        printf("%d\n", s.top());
        s.pop();
      }
    }

    else if(!strcmp(f, "size")) {
      printf("%d\n", (int)s.size());
    }

    else if(!strcmp(f, "empty")) {
      printf("%d\n", s.empty());
    }

    else if(!strcmp(f, "top")) {
      printf("%d\n", s.empty()?-1:s.top());
    }
  }

  return 0;
}
