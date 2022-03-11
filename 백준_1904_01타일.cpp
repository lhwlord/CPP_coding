#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 백준 #1904 : 01타일
// 00에 대한 조합으로 구하기. 조합 DP 필요
// 100만까지의 조합 DP는 메모리 초과가 뜬다. 팩토리얼 DP로 선회. (오답이다.)
// ??? 피보나치 수열이 나온다 ????
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