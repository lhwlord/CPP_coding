#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �����Լ�.
void swapWithPointer(string* a, string* b)
{
	string temp = *a;
	*a = *b;
	*b = temp;
}

// ������ ����. �ۿ��� ����ص� �ȴ�.
void bubbleSortWithPointer(string* arr, int* size)
{
	for (int i = 0; i < *size - 1; ++i)	// j�� �� ������ �ϳ��� �پ���
	{
		for (int j = 0; j < *size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swapWithPointer((arr + j), (arr + j + 1));
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

	// ���� �Է¹ޱ�(���� ��������)
	while (scanf("%100s", temp))
	{
		s[i++] = temp;
		if (getchar() == '\n') break;
	}

	// ��������(������)
	bubbleSortWithPointer(s, &i);

	printf("convert string with pointer-typed parameter: ");

	for (int j = 0; j < i; j++)
	{
		printf("%s ", s[j].c_str());
	}

	return 0;
}