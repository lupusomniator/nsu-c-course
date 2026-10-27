#include <stdio.h>

int main(void) {
    int sum = 0;
    int next = 1;
    while (next <= 4) {
        sum += next;
        ++next;
    }
    printf("%d\n", sum);
    return 0;
}
