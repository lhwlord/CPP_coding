#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// ���� #18108 : 1998����� ���� �±������� 2541���?!
int main(void)
{
	int y;
	scanf("%d", &y);
	printf("%d", y - 543);
	return 0;
}