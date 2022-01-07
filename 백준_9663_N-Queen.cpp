#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, cnt = 0;

void backtrack(vector<int> arr, int n)
{
	if (n == N)
	{
		cnt++; return;
	}
	
	for (int i = 0; i < N; i++)
	{
		bool check = true;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == i || arr[j] == i - (n - j) || arr[j] == i + (n - j))
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			vector<int> arr_2 = arr;
			arr_2[n] = i;
			backtrack(arr_2, n + 1);
		}
	}
}

// 백준 #9663 : N-Queen
int main(void)
{
	cin >> N;

	vector<int> arr(N, -1);	// 각 줄의 몇번째 인덱스에 퀸이 있는가?

	backtrack(arr, 0);

	cout << cnt;
	return 0;
}