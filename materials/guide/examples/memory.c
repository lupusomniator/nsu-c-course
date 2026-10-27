#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t count = 4;
    int* values = NULL;
    if (count == 0) {
        return 0;
    }
    if (count > SIZE_MAX / sizeof(*values)) {
        printf("Size is too large\n");
        return 1;
    }
    values = malloc(count * sizeof(*values));
    if (values == NULL) {
        printf("Cannot allocate memory\n");
        return 1;
    }
    for (size_t i = 0; i < count; ++i) {
        values[i] = (int)(i * i);
    }
    for (size_t i = 0; i < count; ++i) {
        printf("%d", values[i]);
        if (i + 1 < count) {
            printf(" ");
        }
    }
    printf("\n");
    free(values);
    return 0;
}
