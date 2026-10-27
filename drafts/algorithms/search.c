#include <stdio.h>

int Contains(const int* values, size_t count, int target) {
    for (size_t i = 0; i < count; ++i) {
        if (values[i] == target) {
            return 1;
        }
    }
    return 0;
}

// values contains count elements in nondecreasing order.
int ContainsSorted(const int* values, size_t count, int target) {
    size_t left = 0;
    size_t right = count;
    while (left < right) {
        size_t middle = left + (right - left) / 2;
        if (values[middle] == target) {
            return 1;
        }
        if (values[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return 0;
}

int main(void) {
    int values[] = {1, 3, 5, 7, 9};
    size_t count = sizeof(values) / sizeof(values[0]);
    printf("linear: %d\n", Contains(values, count, 7));
    printf("binary: %d\n", ContainsSorted(values, count, 7));
    printf("missing: %d\n", ContainsSorted(values, count, 2));
    return 0;
}
