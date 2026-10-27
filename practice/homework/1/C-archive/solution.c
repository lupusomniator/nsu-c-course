#include <stdio.h>

int main(void) {
    int n, a[1000];
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    int q;
    if (scanf("%d", &q) != 1) {
        return 1;
    }
    for (int i = 0; i < q; ++i) {
        int index;
        if (scanf("%d", &index) != 1) {
            return 1;
        }
        printf("%d\n", a[index]);
    }
    return 0;
}
