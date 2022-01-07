#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ��ǥ ����ü.
typedef struct
{
	int rowPos;
	int colPos;
}pos;

// �ܹ��� TSP ����.
// ����� �Է��ϰ�, �»󿡼� ������ ���Ϸ� ������ �ִ� ����ġ ��θ� ����Ѵ�.
// �� ��, �� ���� �Ʒ� ���� ���� ����� ������ ����Ѵ�.

// ���߿� ������ �� : DP ������� �߸��ƴ�. ������ ������ �ٿ������� �Ѵ�.
int main(void)
{
	// while�� ����
	int row, col;
	while (scanf("%d %d", &row, &col))
	{
		vector<vector<int>> table(row, vector<int>(col));
		for (int i = 0; i < row; i++) for (int j = 0; j < col; j++)
			scanf("%d", &table[i][j]);

		// DP���̺��� ����� : a��ǥ���� b��ǥ�� ���� �ִܰŸ�.
		// �̷л� ������ ��츦 üũ�ϱ� ����, �ʱⰪ�� ���� INT_MAX��.
		vector<vector<int>> DP(row * col, vector<int>(row * col, INT_MAX));

		// ��������� ���� �迭�� �����. a��ǥ���� b��ǥ�� �� ��, b �ٷ� ���� �ܰ谡 b�� ���忡�� ��������� �����.
		vector<vector<int>> route(row * col, vector<int>(row * col));

		// DP�� �Է°����� �ʱ�ȭ.
		for (int i = 0; i < DP.size(); i++) for (int j = 0; j < DP[0].size(); j++)
		{
			// i��ǥ�� j��ǥ�� ���̰� �� 1ĭ�� ��쿡�� ����. ���� i�� ���� �� �۾ƾ� �Ѵ�.
			int i_col = i % col, j_col = j % col;
			if (i_col + 1 == j_col)
			{
				// �̹��� i�� j�� �� ���̰� 1 ���Ͽ��� �Ѵ�.(���� ���� 1 ���ϰų� �ִ��� ���)
				int i_row = i / col, j_row = j / col;
				if (abs(i_row - j_row) <= 1 || abs(i_row - j_row) == row - 1)
				{
					// �� ��쿡�� ���� ���δ�.
					DP[i][j] = table[i_row][i_col] + table[j_row][j_col];

					// ����� ���, ����踦 �̿��� ���Ѵ�.
					int gap = j_row - i_row;
					if (gap == col - 1) route[i][j] = -1;
					else if (gap == -col + 1) route[i][j] = 1;
					else route[i][j] = gap;
				}
			}
		}

		// a�� b�� ������ ���� �ø��鼭 �����Ѵ�.
		for (int c = 2; c < col; c++)	// ������ ��
		{
			for (int i = 0; i < DP.size(); i++) for (int j = 0; j < DP[0].size(); j++)
			{	// ���� ���� ��ŭ, ���ο��� ��ȿ�˻縦 �ؾ� �Ѵ�.
				
				// i�� �� + c�� j�� ���� ��쿡�� ����.
				int i_col = i % col, j_col = j % col;
				if (i_col + c == j_col)
				{
					// DP(a, b) = min(DP(a, c) + DP(c, b)). �� c�� b�� �ٷ� ���� ������.
					int j_row = j / col;
					int c_col = j_col - 1;
					int temp[3] = {-1, 0, 1};	// c�� �ప�� �� ���̴�.
					for (int temp_i = 0; temp_i < 3; temp_i++)
					{
						temp[temp_i] = (j_row  + temp[temp_i] + row) % row;
					}
					// �� �ప���� �ĺ����� ����ġ�� ����. INT_MAX Ŭ����.
					for (int temp_i = 0; temp_i < 3; temp_i++)
					{
						int temp_pos = temp[temp_i] * row + c_col;
						if (DP[i][temp_pos] == INT_MAX)
						{
							temp[temp_i] = INT_MAX;
							continue;
						}
						else
						{
							temp[temp_i] = DP[i][temp_pos] + DP[temp_pos][j] + table[j_row][j_col];
						}
					}

					// temp �迭���� ���� ����ġ���� ����. ���⼭ �ּ� ���� �ȴ�.
					int minIndex = 0;
					for (int k = 0; k < 3; k++)
					{
						if (temp[minIndex] > temp[k]) minIndex = k;
					}
					DP[i][j] = temp[minIndex];

					// ��ε� �����Ѵ�.
					switch (minIndex)
					{
					case 0: route[i][j] = 1;
						break;
					case 1: route[i][j] = 0;
						break;
					case 2: route[i][j] = -1;
						break;
					default:break;
					}
				}
			}
		}

		// DP ä��Ⱑ ������. ���ۿ����� ������ �����ϴ� �ּҰ��� ã�� �� ����ġ�� �����´�.
		int minNum = INT_MAX, min_a = 0, min_b = 0;
		for (int i = 0; i < row; i++) for(int j = 0; j < row; j++)
		{
			if (DP[i * row + 0][j * row + col - 1] < minNum)
			{
				minNum = DP[i * row + 0][j * row + col - 1];
				min_a = i * row + 0; 
				min_b = j * row + col - 1;
			}
		}
		/*
		// ��ε� ������ �� �ֵ��� �Ѵ�.
		vector<int> pass;
		pass.push_back(min_b / col);
		for (int i = 0; i < col - 1; i++)
		{
			int temp = route[min_a][min_b];	// ���� ���� �ϴ°�
			int temp_row = ((min_b / col) - temp + row) % row, temp_col = min_b % col - 1;	// �ӽ���ǥ
			min_b = temp_row * row + temp_col;
			pass.push_back(temp_row);
		}

		for (int i = pass.size() - 1; i != -1; i--)
		{
			cout << pass[i] + 1 << ' ';
		}
		*/
		cout << endl << minNum << endl;


	}
	return 0;
}