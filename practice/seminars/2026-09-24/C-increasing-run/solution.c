#include <stdio.h>

int main(void) {
    int count, previous;
    if (scanf("%d %d", &count, &previous) != 2) {
        return 1;
    }

    int currentLength = 1;
    int maxLength = 1;
    for (int i = 1; i < count; ++i) {
        int current;
        if (scanf("%d", &current) != 1) {
            return 1;
        }
        if (current > previous) {
            ++currentLength;
        } else {
            currentLength = 1;
        }
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
        previous = current;
    }

    printf("%d\n", maxLength);
    return 0;
}
