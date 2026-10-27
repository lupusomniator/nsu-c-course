#include <stdio.h>

int main(void) {
    FILE* file = fopen("course-note.txt", "w");
    if (file == NULL) {
        printf("Cannot open output\n");
        return 1;
    }
    if (fputs("Hello, file!\n", file) == EOF) {
        fclose(file);
        return 1;
    }
    if (fclose(file) != 0) {
        return 1;
    }
    file = fopen("course-note.txt", "r");
    if (file == NULL) {
        printf("Cannot open input\n");
        return 1;
    }
    int character = 0;
    while ((character = fgetc(file)) != EOF) {
        if (putchar(character) == EOF) {
            fclose(file);
            return 1;
        }
    }
    if (ferror(file)) {
        fclose(file);
        return 1;
    }
    if (fclose(file) != 0) {
        return 1;
    }
    return 0;
}
