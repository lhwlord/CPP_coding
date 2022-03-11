#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 백준 #18108 : 1998년생인 내가 태국에서는 2541년생?!
int main(void)
{
	int y;
	scanf("%d", &y);
	printf("%d", y - 543);
	return 0;
}