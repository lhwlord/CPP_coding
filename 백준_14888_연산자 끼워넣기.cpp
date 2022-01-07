#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> numArr;

int min_ = 2147483647, max_ = -2147483648;

// string으로 받는게 문제인가본지, 처리속도가 좀 느린 편이다. 개선한다면 벡터로 바꿔볼수도?
void track(string s, string build)
{
	if (s.empty())
	{
		// 숫자에 하나씩 조합해서 값을 min과 max에 갱신
		int result = numArr[0];
		for (int i = 0; i < build.length(); i++)
		{
			switch (build[i])
			{
			case '+':
				result += numArr[i + 1];
				break;
			case '-' : 
				result -= numArr[i + 1];
				break;
			case '*':
				result *= numArr[i + 1];
				break;
			case '/':
				result /= numArr[i + 1];
				break;
			default: exit(0); break;
			}
		}
		if (min_ > result) min_ = result;
		if (max_ < result) max_ = result;
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		s.erase(s.begin() + i);
		build += c;
		track(s, build);
		s.insert(s.begin() + i, c);
		build.pop_back();
	}
}

// 백준 #14888 : 연산자 끼워넣기
int main(void)
{
	int N;
	cin >> N;
	numArr = vector<int>(N);
	int plus, minus, mul, div;
	for (int i = 0; i < N; i++)
		scanf("%d", &numArr[i]);
	scanf("%d %d %d %d", &plus, &minus, &mul, &div);
	string s = "";
	while (plus--) s += '+';
	while (minus--) s += '-';
	while (mul--) s += '*';
	while (div--) s += '/';

	track(s, "");

	cout << max_ << endl << min_;

	return 0;
}