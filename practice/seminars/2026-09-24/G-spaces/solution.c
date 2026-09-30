#include <stdio.h>

int main(void) {
    char line[1002];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 1;
    }

    int hasOutput = 0;
    int pendingSpace = 0;
    for (int i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '\r'; ++i) {
        if (line[i] == ' ') {
            if (hasOutput) {
                pendingSpace = 1;
            }
        } else {
            if (pendingSpace) {
                putchar(' ');
            }
            putchar(line[i]);
            hasOutput = 1;
            pendingSpace = 0;
        }
    }

    putchar('\n');
    return 0;
}
