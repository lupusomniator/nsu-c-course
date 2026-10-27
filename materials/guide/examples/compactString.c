#include <stdio.h>

int main(void) {
    char line[] = "  C is  fun ";
    size_t write = 0;
    for (size_t read = 0; line[read] != '\0'; ++read) {
        if (line[read] != ' ') {
            line[write] = line[read];
            ++write;
        }
    }
    line[write] = '\0';
    printf("[%s]\n", line);
    return 0;
}
