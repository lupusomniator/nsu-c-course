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

int main(void) {
    printf("char: size=%zu align=%zu; int: size=%zu align=%zu\n",
           sizeof(char), _Alignof(char), sizeof(int), _Alignof(int));
    printf("TSample: size=%zu align=%zu; kind=%zu value=%zu status=%zu\n",
           sizeof(TSample), _Alignof(TSample), offsetof(TSample, kind),
           offsetof(TSample, value), offsetof(TSample, status));
    printf("TCompactSample: size=%zu align=%zu; kind=%zu value=%zu status=%zu\n",
           sizeof(TCompactSample), _Alignof(TCompactSample), offsetof(TCompactSample, kind),
           offsetof(TCompactSample, value), offsetof(TCompactSample, status));
    printf("TPackedSample: size=%zu align=%zu; kind=%zu value=%zu status=%zu\n",
           sizeof(TPackedSample), _Alignof(TPackedSample), offsetof(TPackedSample, kind),
           offsetof(TPackedSample, value), offsetof(TPackedSample, status));
    printf("TPack2Sample: size=%zu align=%zu; kind=%zu value=%zu status=%zu\n",
           sizeof(TPack2Sample), _Alignof(TPack2Sample), offsetof(TPack2Sample, kind),
           offsetof(TPack2Sample, value), offsetof(TPack2Sample, status));
    return 0;
}
