#include <iostream>
using namespace std;

int main() {
    char s[111];
    int answer[26];

    cin >> s;

    for (int i = 0; i < 26; i++) answer[i] = -1;

    for (int i = 0; s[i]; i++) {
        int tmp = (int) s[i] - 97;
        if (answer[tmp] == -1) answer[tmp] = i;
    }
    
    for (int i = 0; i < 26; i++) cout << answer[i] << " ";

    return 0;
}