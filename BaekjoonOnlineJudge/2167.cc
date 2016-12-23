#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    int arr[311][311];

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    
    cin >> k;

    while(k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        int answer = 0;
        for (int p = i; p <= x; p++) {
            for (int q = j; q <= y; q++) {
                answer += arr[p][q];
            }
        }
        cout << answer << endl;
    }

    return 0;
}