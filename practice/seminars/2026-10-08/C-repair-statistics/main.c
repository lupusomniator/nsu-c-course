#include <stdio.h>
#include <statistics.h>
#include <statistics.h> /* Повторное включение должно быть безопасно. */

int main(void) {
    printf("%u %.2f\n", stats_count(), stats_average());
    stats_add(2.0);
    stats_add(4.0);
    printf("%u %.2f\n", stats_count(), stats_average());
    stats_reset();
    printf("%u %.2f\n", stats_count(), stats_average());
    return 0;
}
