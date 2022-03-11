#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


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

		
		vector<vector<char>> table(row + 1, vector<char>(col + 1, 'W'));
		int bitmask = 1 << row;// �ళ����ŭ ����ŷ�� ��Ʈ ����
		
		for (int i = 1; i <= row; i++) // �Է�
		{
			for (int j = 1; j <= col; j++) // �Է�
			{
				scanf("%c", &table[i][j]);
			}
			getchar();
		}

		// ��ֹ� ��Ʈ ����
		vector<int> obstacle(col + 1);
		for (int i = 1; i <= col; i++)
		{
			int mask = 0, times = 1;
			for (int j = row; j >= 1; j--)
			{
				if (table[j][i] == 'x') mask += times;
				times *= 2;
			}
			obstacle[i] = mask;
		}

		// dp[i][j] = i-1° ��ġ�� j������ ��, i���� ��ġ�� ��밪
		vector<vector<pair<int, int>>> dp(col + 1, vector<pair<int, int>>(bitmask, pair<int,int>(-1,-1)));	// 0���� �Ⱦ���, 1���� �̸� �����Ѵ�.

		// 1���� �̸� ����. ù ������ ��ֹ��� �ɸ������� Ȯ���� ��
		for (int i = 0; i < bitmask; i++)
		{
			//dp[1][i].first = i;
			//dp[1][i].second = 0;

			int bit_col = i;
			int bit_table = obstacle[1];
			for (int j = 0; j < row; j++)
			{
				if ((bit_col & 1) && (bit_table & 1))
				{
					dp[1][i].first = -1;
					dp[1][i].second = -10000;
					goto out;
				}
				bit_col >>= 1;
				bit_table >>= 1;
			}
			dp[1][i].first = i;
			dp[1][i].second = 0;
		out:;
		}

		// 2������� dp ����
		for (int i = 2; i < col + 1; i++)
		{
		
			for (int j = 0; j < bitmask; j++)
			{
				// 1. ������ �������°� ��ֹ��� �Ȱɸ��� �����ΰ�? (��ֹ����� ��Ʈ����ŷ, ���⿡ �ɸ��� �ٷ� -1�� ����)
				// �� ������ŭ ���鼭, ���κ� Ȯ���ϰ� 2�� ������.
				int bit_col = j;
				int bit_table = obstacle[i - 1];
				bool check = false;
				for (int k = 0; k < row; k++)
				{
					int temp_a = bit_col & 1;	// 2�� ����������
					int temp_b = bit_table & 1;
					if (temp_a & temp_b)
					{
						dp[i][j].first = -1;
						dp[i][j].second = -10000;	// �ʿ��������
						// �Ѱܾ� �Ѵ�.
						check = true;
						break;
					}
					bit_col >>= 1;
					bit_table >>= 1;	// 2 ����
				}
				if (check) continue;

				// 2. �������°� �����ϴٸ�, �װ����� �ִ� ������? (�������¿��� �ɾ��ִ� �ڸ����� ��ĭ�� ���Ʒ��� ������, �߰��� ��ֹ����� �ȵǰ� �ϰ� ������ �� �ֱ�)
				// ��ֹ�(1)�� ������ ��������� 1�� ����, dp�� ������ ����.
				int max_result = 0;
				int start_point = 1;
				bit_col = j;
				for (int k = 0; k < row; k++)
				{
					if (bit_col & 1)	// ����Ʈ�� ù ���� 1, �� �̹� ������
					{	// ���� ��ġ�� �յڷ� 1 �ֱ�
						max_result |= start_point;
						max_result |= start_point >> 1;
						max_result |= start_point << 1;
					}
					start_point <<= 1;
					bit_col >>= 1;
				}
				// ��ֹ� ÷�� ��, MSB Ŭ���� �� ����
				max_result |= obstacle[i];
				max_result &= bitmask - 1;
				max_result = bitmask - 1 - max_result;
				dp[i][j].first = max_result;

				// 3. �ִ� ������ ������ ��밪��? (�������� �ο� + �������¸� �����ϴ� ���� ���� ���� �ִ� ��밪 = ���� ���� ��밪)
				int expect = -1;
				for (int k = 0; k < bitmask; k++)	// ���� j�� ��Ʈ�� ���� ���� ��Ʈ���� ���Ѵ�.
				{ // ���� or���� �ؼ� ���� ���� ��Ʈ�� ���´ٸ�, �Ծ �Ǵ� ���̴�. �ش� ���� ��밪�� expect�� �ִ밻���ϰ�, �������ͼ� max�� j�� 1�� �߰� �� �� ���� ����.
					if ((j | dp[i - 1][k].first) == dp[i - 1][k].first)
					{
						if (dp[i - 1][k].second > expect) expect = dp[i - 1][k].second;
					}
				}
				
				bit_col = j;
				for (int k = 0; k < row; k++)
				{
					expect += bit_col & 1 ? 1 : 0;
					bit_col >>= 1;
				}

				dp[i][j].second = expect;
			
			}

		}

		// 4. ���������� ���� ��, ������ ���� ��밪 + �ο� �ִ� ��ġ�� ����ؼ� �� �ִ밪 ��ȯ.
		int max_final = -1;
		for (int i = 0; i < bitmask; i++)
		{
			int bit_col = dp[col][i].first;
			int sitted = 0;
			for (int j = 0; j < row; j++)
			{
				sitted += bit_col & 1 ? 1 : 0;
				bit_col >>= 1;
			}
			sitted += dp[col][i].second;

			if (max_final < sitted) max_final = sitted;
		}


		// ���
		printf("%d\n", max_final);
	}
	return 0;
}