#define _CRT_SECURE_NO_WARNINGS
// prob. 84: Unidirectional TSP
#include <stdio.h>
static int n, m, result;
static int inpArr[11][101];
static int sol[101], tracking[11][101], c[11][101];
int input(void)
{
    int i, j;
    n = 0;
    if (scanf("%d %d", &n, &m) == EOF)
        return 0;
    for (i = 0; i < n; i++) {
        sol[i] = 0;
        for (j = 0; j < m; j++) {
            inpArr[i][j] = 0;
            tracking[i][j] = 0;
            c[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &inpArr[i][j]);
    return 1;
}
void dynamic(void)
{
    int i, j;
    int a1, a2, a3;

    for (i = 0; i < n; i++)
        c[i][m - 1] = inpArr[i][m - 1];

    for (j = m - 2; j >= 0; j--)
        for (i = 0; i < n; i++) {
            if (i == 0) {
                a1 = 0;
                a2 = 1;
                if (n == 1) a2 = 0;
                a3 = n - 1;
            }
            else if (i == n - 1) {
                a1 = 0;
                a2 = n - 2;
                if (n == 1) a2 = 0;
                a3 = n - 1;
            }

            else {
                a1 = i - 1;
                a2 = i;
                a3 = i + 1;
            }

            c[i][j] = c[a1][j + 1];
            tracking[i][j] = a1;

            if (c[i][j] > c[a2][j + 1]) {
                c[i][j] = c[a2][j + 1];
                tracking[i][j] = a2;
            }

            if (c[i][j] > c[a3][j + 1]) {
                c[i][j] = c[a3][j + 1];
                tracking[i][j] = a3;
            }

            c[i][j] = c[i][j] + inpArr[i][j];
        }
}
void tracking_procedure(void)
{
    int i, min, mi;

    min = c[0][0];
    mi = 0;

    for (i = 1; i < n; i++) {
        if (min > c[i][0]) {
            min = c[i][0];
            mi = i;
        }
    }

    result = min;
    for (i = 0; i < m; i++) {
        sol[i] = mi;
        mi = tracking[mi][i];
    }
}
void output(void)
{
    int i;

    for (i = 0; i < m - 1; i++) {
        printf("%d ", sol[i] + 1);
    }

    printf("%d", sol[m - 1] + 1);
    printf("\n");
    printf("%d\n", result);
}

void main()
{
    while (input()) {
        dynamic();
        tracking_procedure();
        output();
    }
}
