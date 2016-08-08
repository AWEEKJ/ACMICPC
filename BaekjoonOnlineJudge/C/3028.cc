#include <cstdio>
using namespace std;

int main(){
  char shuffle[51];
  int i = 0;
  int cup[4];
  cup[1] = 1;

  scanf("%s", shuffle);

  while(shuffle[i]){
    if(shuffle[i] == 'A'){
      if (cup[1] == 1) {
        cup[1] = 0;
        cup[2] = 1;
      } else if (cup[2] == 1) {
        cup[1] = 1;
        cup[2] = 0;
      }
    }

    else if(shuffle[i] == 'B'){
      if (cup[2] == 1) {
        cup[2] = 0;
        cup[3] = 1;
      } else if (cup[3] == 1) {
        cup[2] = 1;
        cup[3] = 0;
      }
    }

    else if(shuffle[i] == 'C'){
      if (cup[1] == 1) {
        cup[1] = 0;
        cup[3] = 1;
      } else if (cup[3] == 1) {
        cup[1] = 1;
        cup[3] = 0;
      }
    }
    i++;
  }

  for (i = 1; i <= 3; i++){
    if (cup[i] == 1) printf("%d", i);
  }
  return 0;
}
