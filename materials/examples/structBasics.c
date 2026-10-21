#include <stdio.h>

typedef struct TPoint {
    int x;
    int y;
} TPoint;

void MoveCopy(TPoint point, int dx) {
    point.x += dx;
    (void)point;
}

void Move(TPoint* point, int dx) {
    point->x += dx;
}

TPoint Shifted(TPoint point, int dx) {
    point.x += dx;
    return point;
}

void PrintPoint(const char* name, const TPoint* point) {
    printf("%s: %d %d\n", name, point->x, point->y);
}

int main(void) {
    TPoint start = {.x = 2, .y = 5};
    TPoint copy = start;
    copy.x = 100;
    MoveCopy(start, 3);
    PrintPoint("after MoveCopy", &start);
    Move(&start, 3);
    PrintPoint("after Move", &start);
    TPoint shifted = Shifted(start, 10);
    PrintPoint("shifted", &shifted);
    PrintPoint("copy", &copy);
    return 0;
}
