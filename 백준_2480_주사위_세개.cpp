#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// ���� #2480 : �ֻ��� ����
int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c)
		printf("%d", 10000 + (1000 * a));
	else if (a == b || b == c)
		printf("%d", 1000 + (100 * b));
	else if (c == a)	// ��ġ�� ������ ������ ���� ����
	{
		printf("%d", 1000 + (100 * a));
	}
	else
	{
		a = a < b ? b : a;
		a = a < c ? c : a;
		printf("%d", 100 * a);
	}
	return 0;
}