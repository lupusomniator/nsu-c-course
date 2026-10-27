#include <stdio.h>

int main(void) {
    unsigned int flags = 0u;
    unsigned int mask = 1u << 3;
    flags |= mask;
    printf("enabled=%d\n", (flags & mask) != 0u);
    flags &= ~mask;
    return 0;
}
