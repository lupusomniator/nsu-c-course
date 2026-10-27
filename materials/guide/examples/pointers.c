#include <stdio.h>

// Both arguments point to existing int objects.
void Swap(int* left, int* right) {
    int temporary = *left;
    *left = *right;
    *right = temporary;
}

int main(void) {
    int first = 8;
    int second = 3;
    Swap(&first, &second);
    printf("%d %d\n", first, second);
    return 0;
}
