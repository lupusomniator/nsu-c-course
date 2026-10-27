#include <stdio.h>

int main(void) {
    int n, m, a[100][100];
    if (scanf("%d %d", &n, &m) != 2) {
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (scanf("%d", &a[i][j]) != 1) {
                return 1;
            }
        }
    }
    int maximum = a[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > maximum) {
                maximum = a[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d%c", maximum - a[i][j], j + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}
