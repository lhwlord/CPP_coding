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

// ���� #11729 : �ϳ���ž �̵�����
// printf ��� ����ð��� �پ��� ��ǥ���� ����. ���� printf �� ��
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