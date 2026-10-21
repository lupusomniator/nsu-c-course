#include <stdio.h>
#include <course_limits.h>
#include <course_limits.h>

static int values[CAPACITY];

static int is_capacity(int value) {
    switch (value) {
        case CAPACITY: return 1;
        default: return 0;
    }
}

int main(void) {
    values[0] = CAPACITY - 1;
    printf("%zu %d %d\n", sizeof values / sizeof values[0],
           is_capacity(CAPACITY), is_capacity(values[0]));
    return 0;
}
