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
	// ������ ����� ���� ���
	vector<bool> table(10, true);	// 1~9���� �����
	for (int i = 0; i < 9; i++)
	{
		table[arr[i][col]] = false;
		table[arr[row][i]] = false;
		table[arr[(row / 3 * 3) + (i / 3)][(col / 3 * 3) + (i % 3)]] = false;
	}

	// ���� 0�� ã��(������ row_�� 9���� ����)
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

// ���� #2580 : ������(�ϼ���)
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
	// ���⿡ �Ȱɷȴٴ� ���� ���ʺ��� �ϼ��Ǿ��ٴ� ���̴�.
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