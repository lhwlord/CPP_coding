#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


void hanoi(int n, int a, int b, int c)
{
	if (n != 0)
	{
		hanoi(n - 1, a, c, b);
		printf("%d %d\n", a, c);
		hanoi(n - 1, b, a, c);
	}
}

// 백준 #11729 : 하노이탑 이동순서
// printf 써야 실행시간이 줄어드는 대표적인 문제. 슬슬 printf 쓸 것
int main(void)
{
	int N;
	cin >> N;
	int x = 1;

	for (int i = 0; i< N; i++)
		x *= 2;

	cout << --x << endl;

	hanoi(N, 1, 2, 3);
	return 0;
}