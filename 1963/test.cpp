#include <cstdio>
#include <queue>
#include <vector>
#include <utility> //pair 사용
using namespace std;

#define MAX 10000
vector<bool> is_prime;
vector<bool> visited;

void erathos(){
  is_prime.resize(MAX + 1, true);

  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i < MAX + 1; i++) {
    for (int j = i + i; j < MAX + 1; j += i) {
      if (is_prime[i]) is_prime[j] = false;
    }
  }
}

int bfs(int F, int T) {

  visited.resize(MAX+1, true);

  queue<pair<int, int> > q;
  q.push(make_pair(F, 0));
  visited[F] = true;

  if (F == T) return 0;

  int n, t;

  while(!q.empty()){
    n = q.front().first;
    t = q.front().second;
    q.pop();

    int carry = 1;

    for (int i = 0; i < 4; i++) {
      int next;
      next = n - n / carry % 10 * carry;
      for (int j = 0; j < 10; j++){
        if(is_prime[next] && !visited[next]) {
          q.push(make_pair(next, t+1));
          visited[next] = true;

          if (next == T) return t+1;
        }
        next += carry;
      }
      carry *= 10;
    }
  }
  return -1;
}

int main() {
  int N;
  int F;
  int T;

  scanf("%d", &N);

  while(N--) {
    scanf("%d%d", &F, &T);
    if (bfs(F, T) == -1) printf("Impossible\n");
    printf("%d\n", bfs(F, T));
  }
  return 0;
}
