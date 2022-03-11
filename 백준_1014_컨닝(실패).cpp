#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<char>> table;
int sight[4][2] = {
	{0, -1},
	{0, 1},
	{1, -1},
	{1, 1}
};

// ���� #1014 : ����
int main(void)
{
	int C_;
	scanf("%d", &C_);
	while (C_--)
	{
		int row, col;
		scanf("%d %d", &row, &col);
		getchar();

		// ��Ʈ��ŷ���� ���� �õ�. �ȵǸ� DP.
		// '.', 'X' �ܿ� ���� �� ���� 'A', ���� ���� ���� 'B', A�� ���� ���� ���� 'C'
		table = vector<vector<char>>(row + 2, vector<char>(col + 2, 'X'));
		
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++) // �Է�
			{
				scanf("%c", &table[i][j]);
			}
			getchar();
		}



		// ��Ʈ��ŷ.
		int count = 0, max = -1;
		int row_go = 1, col_go = 1;

	backtrack:

		// ������� �������� A�� ��´�.
		for (int i = row_go; i <= row; i++)
		{
			for (int j = col_go; j <= col; j++)
			{
				if (table[i][j] == '.')
				{
					table[i][j] = 'A'; count++;
					for (int k = 0; k < 4; k++)
					{
						table[i + sight[k][0]][j + sight[k][1]] = table[i + sight[k][0]][j + sight[k][1]] == '.' ? 'C' : table[i + sight[k][0]][j + sight[k][1]];
					}
				}
			}
			col_go = 1;	// ù �������� ������ǥ�� ���δ�. ����� �ٸ��� �� ����ȣ�� 1���� ���� �Ѵ�.
		}
		if (max < count) max = count;	// �ִ밪 �ֽ�ȭ

		// �������� �������� ù A�� ²��. ��ο� B�� ������ �µ� ²��.
		for (int i = row; i >= 1; i--) for (int j = col; j >= 1; j--)
		{
			if (table[i][j] == 'B') table[i][j] = '.';
			if (table[i][j] == 'A')
			{
				row_go = i; col_go = j;
				table[i][j] = 'B'; count--;
				// 4������ C�� �ٸ� A�� ���� �ִ��� Ȯ�� �� ���Ǻη� ����
				for (int k = 0; k < 4; k++)
				{
					int a = i + sight[k][0], b = j + sight[k][1];
					if (a == 0 || a == row + 1 || b == 0 || b == col + 1) continue;	// ����Ȯ��
					else if(table[a][b] == 'C')	// ���� ���� ���ڰ� C�� ��츸
					{
						for (int l = 0; l < 4; l++)
						{
							if (table[a - sight[l][0]][b - sight[l][1]] == 'A') goto out;
						}
						table[a][b] = '.';
					out:;	// A�� �ϳ��� ������ C���ڴ� ���.
					}
				}
				goto loop_out;	// ù A�� ���������� ·���� ��Ʈ��ŷ �õ�.
			}
		}
	all_out : 
		printf("%d\n", max);
		continue;
	loop_out : 
		goto backtrack;





	}
	return 0;
}