#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// ���� #1149 : RGB�Ÿ�
// DP : ����ġ ���̺��� Ȯ���ϰ�, ������ ���ú��� �Ųٷ� �ö󰡸� ����ġ�� �׾ư���.
int main(void)
{
	int N;
	scanf("%d", &N);
	vector<vector<int>> table(N, vector<int>(3));
	// 1 : ����ġ ���̺� �����
	for(int i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &table[i][0], &table[i][1], &table[i][2]);
	}

	// 2 : N-1�ܰ��� ������ ���ú��� ����ġ �׾ƿø���
	for (int i = N - 2; i != -1; --i)	// �ε����� -1 �ؾ� �ϴ� N-2
	{
		for (int j = 0; j < 3; j++)
		{
			// �� ���� �������� �ĺ� �߸��� ������ ã�� ����ġ ���ϱ�
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