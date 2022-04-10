#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <conio.h>
using namespace std;

// 엔터 전까지 단어를 입력받는다. 공백을 포함하고, 단어를 파싱한다.
// 단, C스러운 처리와 C++스러운 처리 둘은 스타일이 완전히 다르다. C스러운 것은 char배열에 대고 토큰으로 빼오는 것이고, C++스러운 것은 애초부터 string으로 스트림에 받아다가 공백기준으로 나누는 것이다.
// 새로운 시도를 해본다 : 입력시간을 줄이기 위해 C의 방식으로 char배열로 받되, 이걸 토큰 없이 string에 넣는 작업.
int main()
{
	char c[101];	// 단어 최대길이는 제한된 것으로 간주한다. 이것마저 제한 없으면 C++ 스타일로 가야 한다.

	char temp;
	while (scanf("%s", c))
	{
		cout << c;
		char tc = getchar();
		if (tc == '\n' || tc == EOF) break;
	}


}