#include <iostream>

using namespace std;

// 비트중에 좌측부터 짝수번째 비트의 값 중 하나라도 1이 있다면 1을 리턴
int any(int x)
{
	//return !!(~(x & 0x55555555) + 1);
	return (~(((~(x & 0x55555555) + 1) >> 32) + 0x40000000 >> 30))&0x1;
}

// 양수면 1, 0과 음수는 0을 리턴
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