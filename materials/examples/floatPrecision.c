#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void) {
    printf("radix=%d float digits=%d double digits=%d\n",
           FLT_RADIX, FLT_MANT_DIG, DBL_MANT_DIG);
    printf("epsilon=%.17g\n", DBL_EPSILON);

    double left = 0.1;
    double right = 0.2;
    double sum = left + right;
    printf("sum=%.17g equal=%d\n", sum, sum == 0.3);
    printf("0.1 as hex: %a\n", left);

    double expanded = 0.1f;
    printf("expanded float=%.17g\n", expanded);
    float value = 16777216.0f;
    float next = value + 1.0f;
    printf("float step: %.0f %.0f\n", value, next);

    double large = 1e16;
    double firstStep = large + (-large);
    double first = firstStep + 1.0;
    double secondStep = -large + 1.0;
    double second = large + secondStep;
    printf("order: %.0f %.0f\n", first, second);

    printf("division: %.1f %.1f\n", (double)(1 / 2), 1.0 / 2);
    printf("close=%d\n", fabs(sum - 0.3) <= 0.001);
    double negativeZero = -0.0;
    printf("negative zero: equal=%d sign=%d\n",
           negativeZero == 0.0, signbit(negativeZero) != 0);
    return 0;
}
