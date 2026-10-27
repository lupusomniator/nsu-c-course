#include <stdio.h>

// n is small and nonnegative; the sum must fit in int.
int SumTo(int n) {
    if (n == 0) {
        return 0;
    }
    int rest = SumTo(n - 1);
    return n + rest;
}

int main(void) {
    printf("%d\n", SumTo(3));
    return 0;
}
