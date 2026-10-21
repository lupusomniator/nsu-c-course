// Требуется поддержка VLA (GCC / Clang). MSVC этот пример не поддерживает.
#include <stdio.h>

void PrintLast(int n) {
    if (n <= 0 || n > 100) {
        return;
    }
    int values[n];
    for (int i = 0; i < n; ++i) {
        values[i] = i + 1;
    }
    printf("n=%d last=%d\n", n, values[n - 1]);
}

int main(void) {
    PrintLast(3);
    PrintLast(5);
    return 0;
}
