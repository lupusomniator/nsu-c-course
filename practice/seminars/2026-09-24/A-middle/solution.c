#include <stdio.h>

int main(void) {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1;
    }

    int middle;
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        middle = b;
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        middle = a;
    } else {
        middle = c;
    }

    printf("%d\n", middle);
    return 0;
}
