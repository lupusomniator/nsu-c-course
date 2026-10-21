#include <stdio.h>

int SumTo(int n) {
    printf("enter: n=%d\n", n);
    if (n == 0) {
        puts("return: 0");
        return 0;
    }
    int rest = SumTo(n - 1);
    int result = n + rest;
    printf("return: n=%d result=%d\n", n, result);
    return result;
}

void CountCalls(void) {
    int current = 0;
    static int total = 0;
    ++current;
    ++total;
    printf("current=%d total=%d\n", current, total);
}

int main(void) {
    int result = SumTo(3);
    printf("sum=%d\n", result);
    CountCalls();
    CountCalls();
    CountCalls();

    int value = 10;
    {
        int value = 20;
        ++value;
        printf("inner=%d\n", value);
    }
    printf("outer=%d\n", value);
    return 0;
}
