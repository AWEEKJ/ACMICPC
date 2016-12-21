#include <cstdio>

typedef struct pair {int p, k;} numPair;

int l, n;
numPair numVector[1011];
int cake[1011];

int main() {
    
    scanf("%d%d", &l, &n);
    
    for (int i = 1; i <= n; i++) {
        numPair nPair;
        scanf("%d%d", &nPair.p, &nPair.k);
        numVector[i] = nPair;
    }

    for (int i = 0; i <= l; i++) cake[i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = numVector[i].p; j <= numVector[i].k; j++) {
            if (cake[j] == 0) cake[j] = i;
        }
    }

    // answer 1
    int cakeNum = 0;
    int answer = 1;

    for (int i = 1; i <= n; i++) {
        int tmp = numVector[i].k - numVector[i].p;
        if (tmp > cakeNum) {
            cakeNum = tmp;
            answer = i;
        }
    }
    printf("%d\n", answer);
    
    // answer 2
    cakeNum = 0;
    answer = 1;

    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= l; j++) {
            if (cake[j] == i) tmp++;
        }
        if (tmp > cakeNum) {
            cakeNum = tmp;
            answer = i;
        }
    }
    printf("%d", answer);

    return 0;
}

