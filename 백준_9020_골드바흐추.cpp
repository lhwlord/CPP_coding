#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// ���� #9020 : �������� ����
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		scanf("%d", &N);
		// N�� ���ݱ����� ��� ü�� �Ÿ���.

		vector<bool> prime(N + 1, true);
		prime[0] = false;
		prime[1] = false;

		for (int i = 2; i < N / 2 + 1; i++)
		{
			if (!prime[i]) continue;
			for (int j = i * 2; j <= N; j += i)
			{
				prime[j] = false;
			}
		}


		// ������ ������ ���� ���� ū �Ҽ����� �������鼭 ��Ƽ�� Ȯ�� �� ���
		int left = N / 2;
	loop:
		for (; !prime[left]; left--);
		if (prime[N - left]) printf("%d %d\n", left, N - left);
		else
		{
			left--;
			goto loop;
		}

	}


	return 0;
}