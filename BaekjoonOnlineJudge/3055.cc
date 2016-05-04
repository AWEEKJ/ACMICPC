#include <stdio.h>
#include <stdlib.h>
typedef struct pair{int x, y;} qData;
typedef struct LinkedList{
  qData data;
  struct LinkedList *next;
} LinkedList;
typedef struct Queue{
  LinkedList *head;
  LinkedList *tail;
  int count;
} Queue;
Queue* CreateQueue(){
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->head = (LinkedList *)malloc(sizeof(LinkedList));
  q->head->next = 0;
  q->tail = q->head;
  q->count = 0;
  return q;
}
void Enqueue(Queue *q, qData data){
  q->tail->next = (LinkedList *)malloc(sizeof(LinkedList));
  q->tail->data = data;
  q->tail = q->tail->next;
  q->tail->next = 0;
  q->count++;
}
qData Dequeue(Queue *q){
  qData data = q->head->data;
  LinkedList *p=q->head;
  q->head = q->head->next;
  q->count--;
  free(p);
  return data;
}

char map[51][51];
char visit[51][51];
int r, c;

int direction[2][4] = {
  {-1, 1, 0, 0},  // x 좌표
  {0, 0, -1, 1}   // y 좌표
};

// 고슴도치가 갈 수 있는 곳은 두더지 굴이거나, 엣지가 아니거나, 물이 안 차있거나, 방문하지 않았거나, 돌이 아닌 곳
int is_ok_visit(int i, int j) {
  if(map[i][j]=='D') return 1;
  return (i < 0) || (i >= r) || (j < 0) || (j >= c)
              || (map[i][j] != '.') || (visit[i][j]) || (map[i][j] == 'X') ? 0 : 1;
}

// 물이 퍼질 수 있는 곳은 엣지가 아니거나, 아직 물이 안 차있거나, 돌이 아닌 곳
int is_ok_water(int i, int j){
  return (i < 0) || (i >= r) || (j < 0) || (j >= c)
              || (map[i][j] != '.') || (map[i][j] == 'X') ? 0 : 1;
}

// 물이 퍼짐
void water(){
  int i, j;

  // 물이 퍼질 가능성이 있는 곳을 찾아서 물이 퍼진 것으로 표시
  for (i = 0; i < r; i++){
    for (j = 0; j < c; j++){
      if(map[i][j]=='*'){
        if(is_ok_water(i-1, j)) map[i-1][j]=1;
        if(is_ok_water(i+1, j)) map[i+1][j]=1;
        if(is_ok_water(i, j-1)) map[i][j-1]=1;
        if(is_ok_water(i, j+1)) map[i][j+1]=1;
      }
    }
  }
  for (i = 0; i < r; i++){
    for (j = 0; j < c; j++){
      if (map[i][j] == 1){
        map[i][j] = '*';
      }
    }
  }
}

int main(){

  int i, j;
  int dx, dy, sx, sy;

  scanf("%d%d ", &r, &c);
  //printf("r:%d, c:%d\n", r, c);

  for (i = 0; i < r; i++) gets(map[i]);
  for (i = 0; i < r; i++){
    for (j = 0; j < c; j++){
      if(map[i][j] == 'D'){dx = i; dy = j;}
      if(map[i][j] == 'S'){sx = i; sy = j;}
    }
  }

  Queue *q = CreateQueue();
  qData data;

  // 현재 고슴도치가 있는 곳부터 탐색 시작
  data.x = sx;
  data.y = sy;
  Enqueue(q, data); // 고슴도치의 시작 위치를 큐에 넣음
  visit[sx][sy] = 1;  // 고슴도치의 시작 위치를 방문처리

  qData tmp;
  int t; // 걸린 시간
  int count;  // 큐 안의 개수

  for (t = 1; ; t++){
    count = q->count;
    j = 0;

    water();

    for ( ; count--; ){ // 큐에 들어있는 모든 데이터에 대해
      data = Dequeue(q);
      tmp.x = data.x;
      tmp.y = data.y;

      // 각 방향(상, 하, 좌, 우)에 대해 갈 수 있는 곳이면 방문 처리 후 큐에 넣음
      for (i = 0; i < 4; i++){
        if (is_ok_visit(tmp.x + direction[0][i], tmp.y + direction[1][i])){
          data.x = tmp.x + direction[0][i];
          data.y = tmp.y + direction[1][i];
          visit[data.x][data.y] = 1;
          Enqueue(q, data);
          j = 1;

          // 두더지 굴에 도착하면 종료
          if((data.x == dx) && (data.y == dy)) return printf("%d", t), 0;
        }
      }
    }
    // 사방이 막혀있으면 for 문을 그냥 빠져나오므로 j = 0 인 상태
    if (j == 0) break;
  }
  puts("KAKTUS");
  return 0;
}
