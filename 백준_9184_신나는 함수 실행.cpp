#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 이 함수의 실행시간을 줄일 수 있도록 DP로 만들기
int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (a < b && b < c) return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}


// 백준 #9184 : 신나는 함수 실행
int main(void)
{
	vector<vector<vector<int>>> arr(21, vector<vector<int>>(21, vector<int>(21)));
	for (int i = 0; i < 21; i++) for (int j = 0; j < 21; j++) for (int k = 0; k < 21; k++)
	{
		if (i == 0 || j == 0 || k == 0) arr[i][j][k] = 1;
		else if (i < j && j < k) arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
		else arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
	}
	int input[3];
	int a, b, c;
	while (true)
	{
		scanf("%d %d %d", &input[0], &input[1], &input[2]);
		a = input[0]; b = input[1]; c = input[2];
		if (input[0] == -1 && input[1] == -1 && input[2] == -1) break;
		for (int i = 0; i < 3; i++)
		{
			if (input[i] <= 0)
			{
				for (int j = 0; j < 3; j++) input[j] = 0; goto loop;
			}
		}
		for(int i = 0; i < 3; i++)
		{
			if (input[i] > 20)
			{
				for (int j = 0; j < 3; j++) input[j] = 20; goto loop;
			}
		}

	loop:
		printf("w(%d, %d, %d) = %d\n", a, b, c, arr[input[0]][input[1]][input[2]]);
		
	
	}
	return 0;
}