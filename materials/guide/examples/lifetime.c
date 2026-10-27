#include <stdio.h>

void CountCalls(void) {
    int current = 0;
    static int total = 0;
    ++current;
    ++total;
    printf("current=%d total=%d\n", current, total);
}

int main(void) {
    CountCalls();
    CountCalls();
    CountCalls();
    return 0;
}
