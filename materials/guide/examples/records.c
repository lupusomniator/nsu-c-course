#include <stdio.h>

struct TPoint {
    int x;
    int y;
};

int main(void) {
    struct TPoint start = {2, 5};
    struct TPoint copy = start;
    copy.x = 12;
    printf("start: %d %d\n", start.x, start.y);
    printf("copy: %d %d\n", copy.x, copy.y);
    return 0;
}
