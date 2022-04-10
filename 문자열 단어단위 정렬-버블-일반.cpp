#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 일반 버블정렬. 반환형이 없으므로 여기서 바로 출력하기
void bubbleSort(string arr[100], int size)
{
	for (int i = 0; i < size-1; ++i)	// j가 설 공간은 하나씩 줄어든다
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				string temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("convert string with basic parameter: ");
	for (int i = 0; i < size; ++i)
	{
		printf("%s ", arr[i].c_str());
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

	// 버블정렬 
	bubbleSort(s, i);

	return 0;
}