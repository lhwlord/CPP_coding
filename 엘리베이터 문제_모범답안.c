#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define NFLOORS     110 	// �ǹ� ����
#define MAX_RIDERS  50  	// ���������� �ִ� ž�� �ο�

int stops[MAX_RIDERS];  	// ��� �°��� ������ �� ��
int nriders;            	// ž�°� ��
int nstops;             	// ���� �� �ִ� ȸ��

int m[NFLOORS + 1][MAX_RIDERS];	// ���� ���α׷��� ��� ���̺�
int p[NFLOORS + 1][MAX_RIDERS];	// ���� ���α׷��� �θ� ���̺�

int min(int a, int b)
{
    if (a > b) return b;
    else return a;
}
int floors_walked(int previous, int current)
{
    int nsteps = 0; // �� �̵� �Ÿ�
    int i;          // ī����
    for (i = 0; i < nriders; i++)
        if ((stops[i] > previous) && (stops[i] <= current))
            nsteps += min(stops[i] - previous, current - stops[i]);
    return(nsteps);
}

int optimize_floors()
{
    int i, j, k;        // ī����
    int cost;           // ��� ����� ����
    int laststop;       // ���������� ���� ��ġ
    for (i = 0; i <= NFLOORS; i++) {
        m[i][0] = floors_walked(0, INT_MAX);
        p[i][0] = -1;
    }
    for (j = 1; j <= nstops; j++)
        for (i = 0; i <= NFLOORS; i++) {
            m[i][j] = INT_MAX;
            for (k = 0; k <= i; k++) {
                cost = m[k][j - 1] - floors_walked(k, INT_MAX) +
                    floors_walked(k, i) + floors_walked(i, INT_MAX);
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    p[i][j] = k;
                }
            }
        }

    laststop = 0;
    for (i = 1; i <= NFLOORS; i++)
        if (m[i][nstops] < m[laststop][nstops])
            laststop = i;

    return(laststop);
}
reconstruct_path(int lastfloor, int stops_to_go)
{
    if (stops_to_go > 1)
        reconstruct_path(p[lastfloor][stops_to_go], stops_to_go - 1);
    printf("%d\n", lastfloor);
}

input()
{
    int i;
    scanf("%d %d", &nriders, &nstops);
    for (i = 0; i < nriders; i++)
        scanf("%d", &stops[i]); // ���� ������ ���ĵǾ� �Էµȴٰ� ����
}

int main()
{
    int result;
    input();
    result = optimize_floors();
    reconstruct_path(result, nstops);
    return 0;
}
