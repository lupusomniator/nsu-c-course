#include <stdio.h>

#define SQUARE_BAD(x) x * x
#define SQUARE_HALF(x) (x) * (x)
#define SQUARE(x) ((x) * (x))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define PRINT_INT(x) do { \
    printf(#x " = "); \
    printf("%d\n", (x)); \
} while (0)

#ifndef DEBUG
#define DEBUG 0
#endif

#if DEBUG
#define TRACE_INT(x) PRINT_INT(x)
#else
#define TRACE_INT(x) ((void)0)
#endif

#define VERSION 3
#define STRINGIZE_RAW(x) #x
#define STRINGIZE(x) STRINGIZE_RAW(x)
#define JOIN_RAW(a, b) a##b
#define JOIN(a, b) JOIN_RAW(a, b)

static inline int MinInt(int left, int right) {
    return left < right ? left : right;
}

int main(void) {
    PRINT_INT(SQUARE_BAD(2 + 3));
    PRINT_INT(100 / SQUARE_HALF(5));
    PRINT_INT(SQUARE(2 + 3));

    int value = 3;
    int result = MIN(value++, 10);
    printf("macro: result=%d value=%d\n", result, value);
    value = 3;
    result = MinInt(value++, 10);
    printf("function: result=%d value=%d\n", result, value);

    puts(STRINGIZE_RAW(VERSION));
    puts(STRINGIZE(VERSION));
    int JOIN(version_, VERSION) = 3;
    PRINT_INT(version_3);
    TRACE_INT(value);
    return 0;
}
