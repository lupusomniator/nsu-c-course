#include <stdio.h>

int x = 10;

static void show(void) {
    int x = 20;
    {
        static int x = 30;
        printf("%d ", x);
        ++x;
    }
    printf("%d\n", x);
}

int main(void) {
    show();
    show();
    printf("%d\n", x);
    return 0;
}
