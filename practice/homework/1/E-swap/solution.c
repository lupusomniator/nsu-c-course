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
    int r1, r2, c1, c2;
    if (scanf("%d %d %d %d", &r1, &r2, &c1, &c2) != 4) {
        return 1;
    }
    for (int j = 0; j < m; ++j) {
        int temp = a[r1][j];
        a[r1][j] = a[r2][j];
        a[r2][j] = temp;
    }
    for (int i = 0; i < n; ++i) {
        int temp = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = temp;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d%c", a[i][j], j + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}
