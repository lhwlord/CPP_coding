#include <iostream>

using namespace std;

// ��Ʈ�߿� �������� ¦����° ��Ʈ�� �� �� �ϳ��� 1�� �ִٸ� 1�� ����
int any(int x)
{
	//return !!(~(x & 0x55555555) + 1);
	return (~(((~(x & 0x55555555) + 1) >> 32) + 0x40000000 >> 30))&0x1;
}

// ����� 1, 0�� ������ 0�� ����
int isPositive(int x)
{
	return ((~x + 1) >> 16>>16)&1;
}

int main(void)
{

	int a = any(0xA);
	int b = any(0xE);
	cout << a << ' ' << b << endl;

	cout << isPositive(6) << ' ' << isPositive(0) << ' ' << isPositive(-6) << endl;

	return 0;
}