#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// ���� #7568 : ��ġ
int main(void)
{
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(2));
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	// ������� �ڽź��� ��ġ ū ��� ���� ���ؼ� ���.
	for (int i = 0; i < N; i++)
	{
		int count = 1;
		for (int j = 0; j < N; j++)
		{
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
			{
				count++;
			}
		}
		printf("%d", count);
		if (i != N - 1) printf(" ");
	}

	return 0;
}