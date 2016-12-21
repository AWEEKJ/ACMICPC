#include <iostream>
using namespace std;

int main() {

    int m, n;
    char input[550][550];
    
    int answer[5] = {0, 0, 0, 0, 0};

    cin >> m >> n;
    for (int i = 0; i < 5*m+1; i++) {
        for (int j = 0; j < 5*n+1; j++) {
            cin >> input[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char blind[5];
            int count = 0;
            for (int k = 1; k <= 4; k++) {
                blind[k] = input[5*(i-1)+k][5*(j-1)+1];
                if (blind[k] == '*') count++;
            }
            answer[count]++;
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}