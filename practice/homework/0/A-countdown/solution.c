#include <stdio.h>

int main(void) {
    int remaining;
    if (scanf("%d", &remaining) != 1) {
        return 1;
    }

    int years = remaining / 31536000;
    remaining %= 31536000;
    int days = remaining / 86400;
    remaining %= 86400;
    int hours = remaining / 3600;
    remaining %= 3600;
    int minutes = remaining / 60;
    int seconds = remaining % 60;

    printf("%d %d %d %d %d\n", years, days, hours, minutes, seconds);
    return 0;
}
