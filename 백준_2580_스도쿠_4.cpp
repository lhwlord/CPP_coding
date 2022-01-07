#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> arr(9, vector<int>(9));

void track(int row, int col)
{

	if (row == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	// 가능한 경우의 수를 계산
	vector<bool> table(10, true);	// 1~9까지 사용함
	for (int i = 0; i < 9; i++)
	{
		table[arr[i][col]] = false;
		table[arr[row][i]] = false;
		table[arr[(row / 3 * 3) + (i / 3)][(col / 3 * 3) + (i % 3)]] = false;
	}

	// 다음 0번 찾기(없으면 row_가 9에서 끝남)
	int row_ = row, col_ = col + 1;
	if (col_ == 9) { row_++; col_ = 0; }
	for (; row_ < 9; row_++)
	{
		if (col_ == 9) col_ = 0;
		for (; col_ < 9; col_++)
		{
			if (!arr[row_][col_]) goto out;
		}
	}
out:
	for (int i = 1; i <= 9; i++)
	{
		if (table[i])
		{
			arr[row][col] = i;
			track(row_, col_);
			arr[row][col] = 0;
		}
	}

}

// 백준 #2580 : 스도쿠(완성본)
int main(void)
{
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++)
		scanf("%d", &arr[i][j]);

	int row = 0, col = 0;

	for (; row < 9; row++)
	{
		for (; col < 9; col++)
		{
			if (arr[row][col] == 0) goto out;
		}
	}
	// 여기에 안걸렸다는 것은 애초부터 완성되었다는 것이다.
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	out:
	track(row, col);
	return 0;
}