#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define NFLOORS     110 	// 건물 층수
#define MAX_RIDERS  50  	// 엘리베이터 최대 탑승 인원

int stops[MAX_RIDERS];  	// 모든 승객이 내리는 층 수
int nriders;            	// 탑승객 수
int nstops;             	// 멈출 수 있는 회수

int m[NFLOORS + 1][MAX_RIDERS];	// 동적 프로그래밍 비용 테이블
int p[NFLOORS + 1][MAX_RIDERS];	// 동적 프로그래밍 부모 테이블

int min(int a, int b)
{
    if (a > b) return b;
    else return a;
}
int floors_walked(int previous, int current)
{
    int nsteps = 0; // 총 이동 거리
    int i;          // 카운터
    for (i = 0; i < nriders; i++)
        if ((stops[i] > previous) && (stops[i] <= current))
            nsteps += min(stops[i] - previous, current - stops[i]);
    return(nsteps);
}

int optimize_floors()
{
    int i, j, k;        // 카운터
    int cost;           // 비용 저장용 변수
    int laststop;       // 마지막으로 멈춘 위치
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
        scanf("%d", &stops[i]); // 낮은 층부터 정렬되어 입력된다고 가정
}

int main()
{
    int result;
    input();
    result = optimize_floors();
    reconstruct_path(result, nstops);
    return 0;
}
