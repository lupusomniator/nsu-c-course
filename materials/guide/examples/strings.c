#include <stdio.h>

int main(void) {
    char word[] = "cat";
    size_t length = 0;
    while (word[length] != '\0') {
        ++length;
    }
    printf("%s: %zu\n", word, length);
    word[0] = 'C';
    printf("%s\n", word);
    return 0;
}
