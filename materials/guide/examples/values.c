#include <stdio.h>

int main(void) {
    int price = 30;
    int count = 3;
    int total = price * count;
    printf("%d\n", total);
    count = 2;
    total = price * count;
    printf("%d\n", total);
    total = total + price;
    printf("%d %d\n", count, total);
    return 0;
}
