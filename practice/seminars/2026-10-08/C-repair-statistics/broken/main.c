#include <stdio.h>
#include "statistics.h"
int main(void) {
    stats_add(2.0);
    stats_add(4.0);
    printf("%u %.2f\n", count, sum / count);
    count = 100; /* Клиент может испортить состояние! */
    return 0;
}
