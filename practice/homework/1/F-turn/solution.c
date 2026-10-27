#include <stdio.h>

int main(void) {
    int n, m, a[100][100], result[100][100];
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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[j][n - 1 - i] = a[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d%c", result[i][j], j + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
