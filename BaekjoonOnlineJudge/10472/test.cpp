#include <cstdio>
#include <queue>
using namespace std;

int click[9] = {
  416, 464, 200, 308, 186, 89, 38, 23, 11,
};

int bfs (int n) {
  queue<int> q;
  int result = 0;
  bool visited[1<<9] = {};
  q.push(0);
  visited[0] = true;
  while (!q.empty()) {
    int qsize = q.size();
    while (qsize--) {
      int now = q.front();
      q.pop();
      //printf("%d, %d\n", qsize, now);
      if(now == n) return result;
      for (int i = 0; i < 9; i++) {
        int next = now ^ click[i];
        if (!visited[next]) {
          q.push(next);
          visited[next] = true;
        }
      }
    }
    result++;
  }
  return result;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char input[10] = {};
        for(int i = 0; i < 3; i++) scanf("%s", input + 3*i);
        int start = 0;
        for(int i = 0; i < 9; i++) start |= ((input[i] == '*') << (8 - i));
        //printf("start = %d\n", start);
        printf("%d\n", bfs(start));
    }
    return 0;
}
