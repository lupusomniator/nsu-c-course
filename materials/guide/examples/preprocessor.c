#include <stdio.h>

#define BUFFER_SIZE 4

int main(void) {
    char buffer[BUFFER_SIZE] = {0};
    printf("%zu\n", sizeof(buffer));
    return 0;
}
