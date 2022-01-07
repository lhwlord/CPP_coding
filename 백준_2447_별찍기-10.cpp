#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<char>> arr;
int mask[8][2] = { {0,0},{0,1},{0,2},{1,0},{1,2},{2,0},{2,1},{2,2} };

// 단계와 시작포인트 지정
void fill(int level, int r, int c)
{
	if (level == 3)
	{
		for (int i = 0; i < 8; i++)
		{
			arr[r + mask[i][0]][c + mask[i][1]] = '*';
		}
		return;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			fill(level / 3, r + level / 3 * mask[i][0], c + level / 3 * mask[i][1]);
		}
	}
	return;
}

// 백준 #2447 : 별찍기-10
int main(void)
{
	int N;
	cin >> N;

	// n*n 벡터 만들고, 그 내부 모습을 재귀적으로 정의한다.
	arr = vector<vector<char>>(N, vector<char>(N, ' '));
	fill(N, 0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c", arr[i][j]);
		}
		cout << endl;
	}

	
	return 0;
}