#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> p1, p2;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        p1.insert(name);
    }

    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        p2.insert(name);
    }

    vector<string> answer;
    set_intersection(p1.begin(), p1.end(), p2.begin(), p2.end(), back_inserter(answer));

    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}