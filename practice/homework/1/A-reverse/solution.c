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
    int left, right;
    if (scanf("%d %d", &left, &right) != 2) {
        return 1;
    }
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        ++left;
        --right;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
