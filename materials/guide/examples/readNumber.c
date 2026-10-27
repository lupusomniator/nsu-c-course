#include <stdio.h>

int main(void) {
    int value = 0;
    if (scanf("%d", &value) != 1) {
        printf("Expected an integer\n");
        return 1;
    }
    if (value < 0 || value > 100) {
        printf("Expected a value from 0 to 100\n");
        return 1;
    }
    printf("Next: %d\n", value + 1);
    return 0;
}
