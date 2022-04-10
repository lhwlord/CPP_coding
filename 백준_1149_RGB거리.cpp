#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 백준 #1149 : RGB거리
// DP : 가중치 테이블을 확보하고, 마지막 선택부터 거꾸로 올라가며 가중치를 쌓아간다.
int main(void)
{
	int N;
	scanf("%d", &N);
	vector<vector<int>> table(N, vector<int>(3));
	// 1 : 가중치 테이블 만들기
	for(int i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &table[i][0], &table[i][1], &table[i][2]);
	}

	// 2 : N-1단계의 마지막 선택부터 가중치 쌓아올리기
	for (int i = N - 2; i != -1; --i)	// 인덱스는 -1 해야 하니 N-2
	{
		for (int j = 0; j < 3; j++)
		{
			// 각 셀별 다음선택 후보 추리고 최적값 찾아 가중치 더하기
			int k1 = (j + 1) % 3, k2 = (j + 2) % 3;
			table[i][j] += table[i + 1][k1] < table[i + 1][k2] ? table[i + 1][k1] : table[i + 1][k2];
		}
	}

	int smaller = 2147483647;
	for (int i = 0; i < 3; i++)
	{
		if (smaller > table[0][i]) smaller = table[0][i];
	}

	printf("%d", smaller);

	return 0;
}