#include <stdio.h>

// value + 1 must be representable as int.
int AddOne(int value) {
    return value + 1;
}

int main(void) {
    int original = 10;
    int result = AddOne(original);
    printf("%d %d\n", original, result);
    return 0;
}
