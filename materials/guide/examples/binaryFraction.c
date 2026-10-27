#include <stdio.h>

// 0 <= numerator < denominator, denominator > 0.
// Doubling any remainder must fit in unsigned int.
void PrintBinaryFraction(unsigned int numerator, unsigned int denominator,
                         unsigned int digits) {
    printf("%u/%u: 0.", numerator, denominator);
    for (unsigned int i = 0; i < digits && numerator != 0u; ++i) {
        numerator *= 2u;
        printf("%u", numerator / denominator);
        numerator %= denominator;
    }
    if (numerator == 0u) {
        printf(" (exact)\n");
    } else {
        printf("... (remainder=%u/%u)\n", numerator, denominator);
    }
}

int main(void) {
    PrintBinaryFraction(5u, 8u, 16u);
    PrintBinaryFraction(1u, 10u, 16u);
    return 0;
}
