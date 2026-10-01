#include <stdio.h>

int main(void) {
    float x, k, b;
    if (scanf("%f %f %f", &x, &k, &b) != 3) {
        return 1;
    }

    float temperature = x * k + b;
    printf("%.2f\n", temperature);
    return 0;
}
