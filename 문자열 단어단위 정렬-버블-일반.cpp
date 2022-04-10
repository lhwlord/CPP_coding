#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �Ϲ� ��������. ��ȯ���� �����Ƿ� ���⼭ �ٷ� ����ϱ�
void bubbleSort(string arr[100], int size)
{
	for (int i = 0; i < size-1; ++i)	// j�� �� ������ �ϳ��� �پ���
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

	// ���� �Է¹ޱ�(���� ��������)
	while (scanf("%100s", temp))
	{
		s[i++] = temp;
		if (getchar() == '\n') break;
	}

	// �������� 
	bubbleSort(s, i);

	return 0;
}