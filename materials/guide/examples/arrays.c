#include <stdio.h>

int main(void) {
    int values[4] = {3, 7, 2, 6};
    size_t count = sizeof(values) / sizeof(values[0]);
    int sum = 0;
    for (size_t i = 0; i < count; ++i) {
        sum += values[i];
    }
    printf("sum=%d, count=%zu\n", sum, count);
    return 0;
}
