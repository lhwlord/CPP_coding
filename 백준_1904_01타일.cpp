#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// ���� #1904 : 01Ÿ��
// 00�� ���� �������� ���ϱ�. ���� DP �ʿ�
// 100�������� ���� DP�� �޸� �ʰ��� ���. ���丮�� DP�� ��ȸ. (�����̴�.)
// ??? �Ǻ���ġ ������ ���´� ????
int main(void)
{
	int N;
	cin >> N;

	/*
	int result = 0;
	vector<int> arr(N + 1, 1);
	for (int i = 1; i <= N; i++)
	{
		arr[i] = arr[i - 1] * i % 15746;
		if (arr[i] == 0) arr[i] = 15746;
	}
	for (int i = 0; 2 * i <= N; i++)
	{
		result += arr[N - i] / ((arr[i]) * (arr[N - i - i])) % 15746;
		result %= 15746;
	}
	cout << result;
	*/

	int a = 1, b = 1, c;
	if (N == 1) cout << 1;
	else
	{
		for (int i = 2; i <= N; i++)
		{
			c = (a + b) % 15746;
			a = b; b = c;
		}
		cout << c;
	}

	return 0;
}