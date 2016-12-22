#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int memo[5011];
    int tmp[13] = {-1, -1, -1, 1, -1, 1, 2, -1, 2, 3, 2, 3, 4};
    for (int i = 0; i <= 12; i++) {
        memo[i] = tmp[i];
    }

    for (int i = 13; i <= 5000; i++) {
        memo[i] = memo[i-3] < memo[i-5] ? memo[i-3] + 1 : memo[i-5] + 1;
    }

    cout << memo[n];

    return 0;
}
