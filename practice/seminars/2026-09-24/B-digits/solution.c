#include <stdio.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }

    int digitCount = 0;
    int digitSum = 0;
    int maxDigit = 0;
    do {
        int digit = number % 10;
        ++digitCount;
        digitSum += digit;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        number /= 10;
    } while (number > 0);

    printf("%d %d %d\n", digitCount, digitSum, maxDigit);
    return 0;
}
