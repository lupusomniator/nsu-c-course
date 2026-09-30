#include <stdio.h>

int main(void) {
    char line[1002];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 1;
    }

    int wordCount = 0;
    int insideWord = 0;
    for (int i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '\r'; ++i) {
        if (line[i] == ' ') {
            insideWord = 0;
        } else {
            if (!insideWord) {
                ++wordCount;
            }
            insideWord = 1;
        }
    }

    printf("%d\n", wordCount);
    return 0;
}
