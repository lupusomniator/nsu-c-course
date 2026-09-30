#include <stdio.h>

int IsPrime(int number) {
    if (number < 2) {
        return 0;
    }
    for (int divisor = 2; divisor * divisor <= number; ++divisor) {
        if (number % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int left, right;
    if (scanf("%d %d", &left, &right) != 2) {
        return 1;
    }

    int primeCount = 0;
    for (int number = left; number <= right; ++number) {
        primeCount += IsPrime(number);
    }

    printf("%d\n", primeCount);
    return 0;
}
