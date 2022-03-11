#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 백준 #2525 : 오븐 시계
int main(void)
{
	int h, m, flow;
	scanf("%d %d %d", &h, &m, &flow);

	m += flow;

	h += m / 60;

	m %= 60;

	h %= 24;

	printf("%d %d", h, m);

	return 0;
}