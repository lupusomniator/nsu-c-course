#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

_Static_assert(CHAR_BIT == 8, "This format requires 8-bit bytes");

uint32_t ReadU32LE(const unsigned char* bytes) {
    return (uint32_t)bytes[0]
        | ((uint32_t)bytes[1] << 8)
        | ((uint32_t)bytes[2] << 16)
        | ((uint32_t)bytes[3] << 24);
}

int main(void) {
    // Формат: kind (1 байт), length (4 байта, little-endian).
    const unsigned char bytes[] = {2, 0x78, 0x56, 0x34, 0x12};
    size_t size = sizeof(bytes);
    if (size < 5) {
        fputs("Header is too short\n", stderr);
        return 1;
    }

    unsigned int kind = bytes[0];
    uint32_t length = ReadU32LE(bytes + 1);
    printf("kind=%u length=0x%08" PRIx32 "\n", kind, length);
    return 0;
}
