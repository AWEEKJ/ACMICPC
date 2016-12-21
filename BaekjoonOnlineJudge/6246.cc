#include <cstdio>
typedef struct pair {
    int l, i;
} Pair;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    Pair input[10111];
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &input[i].l, &input[i].i);
    }

    int balloon[10111];
    for (int i = 1; i <= n; i++) balloon[i] = 0;

    for (int i = 0; i < q; i++) {
        for (int j = input[i].l; j <= n; j += input[i].i) {
            balloon[j] = 1;
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (balloon[i] == 0) answer += 1;
        // printf("%d", balloon[i]);
    }

    printf("%d", answer);

    return 0;
}