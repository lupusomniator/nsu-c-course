#include <stddef.h>
#include <stdio.h>

// count is in bytes. Regions must be writable and either identical or disjoint.
// For typed values, exchange complete objects of the same type.
void swap(void* a, void* b, size_t count) {
    if (count == 0 || a == b) {
        return;
    }
    unsigned char* left = a;
    unsigned char* right = b;
    for (size_t i = 0; i < count; ++i) {
        unsigned char temporary = left[i];
        left[i] = right[i];
        right[i] = temporary;
    }
}

int main(void) {
    int first = 8;
    int second = 3;
    swap(&first, &second, sizeof(first));
    printf("integers: %d %d\n", first, second);

    double x = 1.25;
    double y = 2.5;
    swap(&x, &y, sizeof(x));
    printf("doubles: %.2f %.2f\n", x, y);

    int left[3] = {1, 2, 3};
    int right[3] = {4, 5, 6};
    swap(&left, &right, sizeof(left));
    printf("arrays: %d %d %d | %d %d %d\n",
           left[0], left[1], left[2], right[0], right[1], right[2]);
    return 0;
}
