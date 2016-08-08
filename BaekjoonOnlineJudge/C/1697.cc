#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int direction[] = {1, -1, 0}
vector<int> visited;

int main() {
  int N, K;
  scanf("%d%d", &N, &K);

  if (N == K) {
    printf("0\n");
    return 0;
  }
  
  queue<pair<int, int> > q;
  visited.resize(100001);
  q.push(make_pair(N, 0));
  visited[N] = 1;

  while (!q.empty()) {
    next = q.front().first;
    q.pop();

    for (int i = 0; i < 3; i++){
      int tmp;
      tmp = direction[i] + next;
      if (tmp == next) tmp *= 2;
      if (tmp == K)

      if ((tmp < 0 || tmp > 100000) || )
    }

  }





  return 0;
}
