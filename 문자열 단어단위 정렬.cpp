#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// README
/*
* ����ȯ�� : ������ 10, Microsoft Visual Studio 2019
* ������ : ���־�Ʃ����� ���� ���� �� ������
*/


int main(void)
{
	printf("Input string: ");
	vector<string> arr;
	char temp[101];
	string s;

	// ���� �Է¹ޱ�(���� ��������)
	while (scanf("%100s", temp))
	{
		arr.push_back(temp);

		if (getchar() == '\n') break;
	}

	// ��������
	// ���Ա����� ���� �÷����� ����.
	// �ϳ� ���, �� ��ü�� ���Ա����� Ȯ��������, �ű���� ���Ա��� ������ ��ĭ �ڷ� �̷�� ����.(���ʹϱ� �̷��� �ʰ� �μ�Ʈ�ϸ� �ɵ�)
	for (int i = 0; i < arr.size(); ++i)
	{
		string temp_string = arr[i];
		arr.erase(arr.begin() + i);

		int j;

		for (j = 0; j < i; ++j)
		{
			if (temp_string < arr[j]) break;
		}
		arr.insert(arr.begin() + j, temp_string);
	}

	for (auto i : arr)
		printf("%s ", i.c_str());

	return 0;
}