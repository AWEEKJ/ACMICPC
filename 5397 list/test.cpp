#include <cstdio>
#include <list>

using namespace std;

int main(){
  char input[1000001];
  int num_case;
  scanf("%d", &num_case);

  while(num_case--){
    scanf("%s", input);

    list<char> pw;
    auto current = pw.begin();

    for(int i = 0; input[i]; i++){
      if(input[i] == '<'){
        if(current != pw.begin()){
          current--;
        }
      }

      else if(input[i] == '>'){
        if(current != pw.end()){
          current++;
        }
      }

      else if(input[i] == '-'){
        if(current != pw.begin()){
          current = pw.erase(--current);
        }
      }

      else {
        pw.insert(current, input[i]);
      }
    }

    for(auto pick : pw){
      printf("%c", pick);
    }
		printf("\n");
  }
  return 0;
}
