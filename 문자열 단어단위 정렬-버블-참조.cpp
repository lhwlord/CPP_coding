#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 스왑함수.
void swapWithReference(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

// 참조 정렬. 밖에서 출력해도 된다.
void bubbleSortWithReference(string (& arr)[100], int& size)
{
	for (int i = 0; i < size - 1; ++i)	// j가 설 공간은 하나씩 줄어든다
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swapWithReference(arr[j], arr[j + 1]);
			}
		}
	}
}


int main(void)
{
	printf("Input string: ");
	char temp[101];
	int i = 0;
	string s[100];

	// 문장 입력받기(엔터 전까지만)
	while (scanf("%100s", temp))
	{
		s[i++] = temp;
		if (getchar() == '\n') break;
	}

	// 버블정렬(참조)
	bubbleSortWithReference(s, i);

	printf("convert string with Reference-typed parameter: ");

	for (int j = 0; j < i; j++)
	{
		printf("%s ", s[j].c_str());
	}

	return 0;
}