#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>

static int ReadNumber(const char* text, long double* value) {
    char* end;
    *value = strtold(text, &end);
    if (end == text || !isfinite(*value)) {
        return 0;
    }
    while (isspace((unsigned char)*end)) {
        ++end;
    }
    return *end == '\0';
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return 2;
    }
    long double actual, expected;
    if (!ReadNumber(argv[1], &actual) || !ReadNumber(argv[2], &expected)) {
        return 1;
    }
    long double difference = actual - expected;
    if (difference < 0) {
        difference = -difference;
    }
    long double magnitude = expected < 0 ? -expected : expected;
    /* Account for parsing roundoff at the exact decimal tolerance boundary. */
    long double tolerance = 0.0001L + 4 * LDBL_EPSILON * (1 + magnitude);
    return difference <= tolerance ? 0 : 1;
}
