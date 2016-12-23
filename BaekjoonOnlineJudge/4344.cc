#include <iostream>
#include <vector>
using namespace std;

int main() {
    int c;
    cin >> c;
    while (c--) {
        float n;
        vector<float> score;
        float sum = 0;
        float ave;

        cin >> n;
        
        for (float i = 0; i < n; i++) {
            float tmp;
            cin >> tmp;
            score.push_back(tmp);
            sum += tmp;
        }
        ave = sum / n;

        float num = 0;
        for (float i = 0; i < n; i++) {
            if (score[i] > ave) num++;
        }

        float ans = num / n * 100;
        cout.precision(3);
        cout << fixed << ans << "%" << endl;
    }
    return 0;
}