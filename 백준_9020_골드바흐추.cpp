#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 백준 #9020 : 골드바흐의 추측
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		scanf("%d", &N);
		// N의 절반까지만 배수 체로 거른다.

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


		// 절반을 가르고 그중 가장 큰 소수부터 내려가면서 파티션 확인 후 출력
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