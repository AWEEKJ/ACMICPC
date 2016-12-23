#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r;
        char s[25];

        cin >> r >> s;

        for (int i = 0; s[i]; i++) {
            for (int j = 0; j < r; j++) {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}