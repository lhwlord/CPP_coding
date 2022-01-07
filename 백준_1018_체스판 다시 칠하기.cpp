#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// ���� #1018 : ü���� �ٽ� ĥ�ϱ�
int main(void)
{
	int M, N;
	//scanf("%d %d\n", &M, &N);
	cin >> M >> N;
	while (getchar() != '\n');
	vector<vector<char>> table(M, vector<char>(N));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &table[i][j]);
		}
		getchar();
	}

	// 8*8����ŭ ���Ʈ����.

	vector<char> sample_W(N, 'W');
	vector<char> sample_B(N, 'B');
	for (int i = 1; i < 8; i += 2)
	{
		sample_W[i] = 'B';
		sample_B[i] = 'W';
	}

	int result = 2147483647;

	for (int i = 0; i <= M - 8; i++)
	{
		for (int j = 0; j <= N - 8; j++)
		{
			//ó���� W�� ���, B�� ��� �� �ٿ� ���� ������.
			int count_W = 0, count_B = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (k % 2)
					{
						if (table[i + k][j + l] != sample_B[l]) count_W++;
						if (table[i + k][j + l] != sample_W[l]) count_B++;
					}
					else
					{
						if (table[i + k][j + l] != sample_W[l]) count_W++;
						if (table[i + k][j + l] != sample_B[l]) count_B++;
					}
				}
			}
			result = min(min(count_W, count_B), result);
		}
	}
	cout << result;
	return 0;
}