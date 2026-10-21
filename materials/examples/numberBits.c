#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

_Static_assert(CHAR_BIT == 8, "This byte display expects 8-bit bytes");

void PrintBytes(const void* object, size_t size) {
    const unsigned char* bytes = object;
    for (size_t i = 0; i < size; ++i) {
        printf("%02X%s", (unsigned int)bytes[i],
               i + 1 == size ? "\n" : " ");
    }
}

void PrintBits32(uint32_t value) {
    for (int bit = 31; bit >= 0; --bit) {
        putchar(((value >> bit) & UINT32_C(1)) != 0 ? '1' : '0');
    }
    putchar('\n');
}

int main(void) {
    printf("CHAR_BIT=%d sizeof(int)=%zu\n", CHAR_BIT, sizeof(int));
    printf("INT_MIN=%d INT_MAX=%d UINT_MAX=%u\n", INT_MIN, INT_MAX, UINT_MAX);
    uint32_t value = UINT32_C(0x12345678);
    printf("value=0x%08" PRIX32 "\n", value);
    PrintBits32(value);
    PrintBytes(&value, sizeof(value));

    int32_t negative = -3;
    printf("negative=%" PRId32 "\n", negative);
    PrintBytes(&negative, sizeof(negative));

    float fraction = 13.25f;
    printf("float=%.2f bytes: ", fraction);
    PrintBytes(&fraction, sizeof(fraction));

    unsigned int wrapped = UINT_MAX;
    wrapped += 1u;
    printf("wrapped=%u\n", wrapped);
    return 0;
}
