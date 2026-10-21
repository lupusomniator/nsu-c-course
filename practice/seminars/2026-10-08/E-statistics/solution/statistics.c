#include "statistics.h"

static unsigned count;
static double sum;

void stats_add(double value) {
    sum += value;
    ++count;
}

unsigned stats_count(void) { return count; }

double stats_average(void) {
    return count == 0 ? 0.0 : sum / count;
}

void stats_reset(void) {
    count = 0;
    sum = 0.0;
}
