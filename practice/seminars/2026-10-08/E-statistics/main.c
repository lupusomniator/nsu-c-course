#include <stdio.h>
#include <statistics.h>
#include <statistics.h>

int main(void) {
    char command;
    while (scanf(" %c", &command) == 1) {
        if (command == 'a') {
            double value;
            if (scanf("%lf", &value) != 1) { return 1; }
            stats_add(value);
        } else if (command == 'r') {
            stats_reset();
        } else if (command == 'p') {
            printf("%u %.2f\n", stats_count(), stats_average());
        } else {
            return 1;
        }
    }
    return 0;
}
