#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    // ()(((()())(())()))(()) is 0123003404021505
    
    char input[100111];
    scanf("%s", input);

    int num = 1;
    stack<int> s;
    int inputNum[100111];
    int j = 0;
    for (int i = 0; input[i]; i++) {
        if (input[i] == '(') {
            if (input[i+1] == ')') {
                input[j] = 0;
                // printf("%d %d\n", j, inputNum[j]);
                i++;
            } else {
                s.push(num);
                inputNum[j] = num++;
                // printf("%d %d\n", j, inputNum[j]);
            }
        } else if (input[i] == ')') {
            inputNum[j] = s.top();
            // printf("%d %d\n", j, inputNum[j]);
            s.pop();
        }
        j++;
    }

    for (int k = 1; k < num; k++) {
        for (int i = 0; i < j; i++) {
            if (inputNum[i] == k) {
                
            }
        }
    }


    return 0;
}