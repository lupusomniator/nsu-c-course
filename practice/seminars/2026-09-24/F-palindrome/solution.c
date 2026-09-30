#include <stdio.h>
#include <string.h>

int main(void) {
    char word[1001];
    if (scanf("%1000s", word) != 1) {
        return 1;
    }

    int length = (int)strlen(word);
    for (int i = 0; i < length / 2; ++i) {
        if (word[i] != word[length - 1 - i]) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    return 0;
}
