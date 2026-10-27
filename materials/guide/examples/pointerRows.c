#include <stdio.h>

int main(void) {
    int table[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int (*row)[3] = table;
    ++row;
    printf("%d %d\n", (*row)[0], (*row)[2]);
    return 0;
}
