#include <stddef.h>
#include <stdio.h>

typedef struct TSample {
    char kind;
    int value;
    char status;
} TSample;

typedef struct TCompactSample {
    int value;
    char kind;
    char status;
} TCompactSample;

#pragma pack(push, 1)
typedef struct TPackedSample {
    char kind;
    int value;
    char status;
} TPackedSample;
#pragma pack(pop)

#pragma pack(push, 2)
typedef struct TPack2Sample {
    char kind;
    int value;
    char status;
} TPack2Sample;
#pragma pack(pop)

// Макрос принимает имя типа, а не вычисляемое выражение.
#define PRINT_LAYOUT(type) do { \
    printf("%s: size=%zu align=%zu; kind=%zu value=%zu status=%zu\n", \
           #type, sizeof(type), _Alignof(type), offsetof(type, kind), \
           offsetof(type, value), offsetof(type, status)); \
} while (0)

int main(void) {
    printf("char: size=%zu align=%zu; int: size=%zu align=%zu\n",
           sizeof(char), _Alignof(char), sizeof(int), _Alignof(int));
    PRINT_LAYOUT(TSample);
    PRINT_LAYOUT(TCompactSample);
    PRINT_LAYOUT(TPackedSample);
    PRINT_LAYOUT(TPack2Sample);
    return 0;
}
