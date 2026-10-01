#include <stdio.h>

int main(void) {
    int left, right;
    if (scanf("%d %d", &left, &right) != 2) {
        return 1;
    }

    for (int code = left; code <= right; ++code) {
        if (code == 32) {
            printf("%d SPACE\n", code);
        } else if (code < 32 || code == 127) {
            printf("%d CONTROL\n", code);
        } else {
            char symbol = (char)code;
            printf("%d %c\n", code, symbol);
        }
    }
    return 0;
}
