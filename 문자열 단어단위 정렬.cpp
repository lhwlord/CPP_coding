#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// README
/*
* 개발환경 : 윈도우 10, Microsoft Visual Studio 2019
* 실행방법 : 비주얼스튜디오로 파일 실행 후 컴파일
*/


int main(void)
{
	printf("Input string: ");
	vector<string> arr;
	char temp[101];
	string s;

	// 문장 입력받기(엔터 전까지만)
	while (scanf("%100s", temp))
	{
		arr.push_back(temp);

		if (getchar() == '\n') break;
	}

	// 삽입정렬
	// 삽입구역을 점차 늘려가며 진행.
	// 하나 집어서, 그 개체의 삽입구역을 확인했으면, 거기부터 삽입구역 끝까지 한칸 뒤로 미루며 삽입.(벡터니까 미루지 않고 인서트하면 될듯)
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