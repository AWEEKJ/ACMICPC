#include <iostream>
#include <cstring>
#include <deque>
using namespace std;


void print_deque(deque<int> dq) {
    cout << "size is " << dq.size() << endl;
    cout << "empty is " << dq.empty() << endl;
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    cout << endl;
}

int main() {
    deque<int> dq;
    int n;
    char f[15];
    int x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> f;

        if (!strcmp(f, "push_front")) {
            cin >> x;
            dq.push_front(x);
        }
        else if (!strcmp(f, "push_back")) {
            cin >> x;
            dq.push_back(x);
        }
        else if (!strcmp(f, "pop_front")) {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if (!strcmp(f, "pop_back")) {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if (!strcmp(f, "size")) {
            cout << (dq.empty()? 0 : dq.size()) << endl;
        }
        else if (!strcmp(f, "empty")) {
            cout << dq.empty() << endl;
        }
        else if (!strcmp(f, "front")) {
            cout << (dq.empty()? -1 : dq.front()) << endl;
        }
        else if (!strcmp(f, "back")) {
            cout << (dq.empty()? -1 : dq.back()) << endl;
        }
    }
    
    return 0;
}
