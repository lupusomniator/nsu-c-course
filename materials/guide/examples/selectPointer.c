#include <stdio.h>

// output points to an int* object; left and right point to live int objects.
void SelectLarger(int** output, int* left, int* right) {
    if (*left >= *right) {
        *output = left;
    } else {
        *output = right;
    }
}

int main(void) {
    int first = 4;
    int second = 9;
    int* selected = &first;
    SelectLarger(&selected, &first, &second);
    printf("selected=%d first=%d second=%d\n", *selected, first, second);
    return 0;
}
