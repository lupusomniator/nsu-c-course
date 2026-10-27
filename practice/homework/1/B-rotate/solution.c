#include <stdio.h>

int main(void) {
    int n, k, a[1000], result[1000];
    if (scanf("%d %d", &n, &k) != 2) {
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        result[(i + k) % n] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        printf("%d%c", result[i], i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
