#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 한 문장에서 다른 문장으로 가기 위한 최소비용을 계산한다.
// 특정 문자를 다른 문자로 바꾸는 스왑, 혹은 추가/삭제의 3가지 연산이 가능하다.
int main(void)
{
	string a, b, route;
	char c[50] = {'\0',};	// 스트링 받기용 임시객체

	scanf("%[^\n]49s", c);	// 정규표현식에 따라, 개행문자 이전까지 최대 49개 읽어서 c에 저장.
	a = c;

	getchar();	// 엔터 비우기

	scanf("%[^\n]49s", c);	// 동일
	b = c;

	cout << a << ' ' << b << endl;

	// 각 문장의 길이만큼 놓기
	vector<vector<int>> table(a.length() + 1, vector<int>(b.length() + 1));

	// 첫 행과 첫 열은 각각 해당하는 값으로 초기화
	for (int i = 0; i < table.size(); i++)
	{
		table[i][0] = i;
	}
	for (int i = 0; i < table[0].size(); i++)
	{
		table[0][i] = i;
	}

	// for문 돌면서 진행.
	for (int i = 1; i < table.size(); i++) for (int j = 1; j < table[i].size(); j++)
	{
		// 각 값은, 좌측/상단/좌상의 값을 비교해서 넣는다. 이 때, 좌측과 상단에선 1 추가하고, 좌상은 i와 j가 같은지에 따라 결정한다.(i == j인 경우에만 좌상 대입 시도. 얘는 가중치 없음)
		int from_left = table[i][j - 1] + 1;
		int from_up = table[i - 1][j] + 1;
		if (a[i - 1] == b[j - 1])	// 스트링 인덱스는 i, j번째보다 1 적다.
		{
			table[i][j] = min(min(from_left, from_up), table[i - 1][j - 1]);
		}	
		else  // 만약 서로 다르다면, 수정하는 값과의 대소비교로 들어간다.
		{
			table[i][j] = min(min(from_left, from_up), table[i - 1][j - 1] + 1);
		}
	}

	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}

	cout << table[table.size() - 1][table[0].size() - 1] << endl;


	// 이제 a 문자열을 어떻게 수정해야 b 문자열이 되는지 알아보자.
	// 좌상에서 가져왔으면 매치거나 스위치, 위에서 가져왔으면 딜리트, 왼쪽에서 가져왔으면 인서트이다. 행에 있는 a 문자열의 수정방안을 보는 것이기 때문.
	// 추가 : 이 결과는 여러 가능성 있는 결과 중 한가지만을 보여준다. 따라서 만약 이게 실습문제로 나와서 특정 출력만을 요구하게 된다면, 그땐 저 밑에 탐색순서를 적절히 바꿔야 할 것이다.
	int row = table.size() - 1, col = table[0].size() - 1;
	while (row != 0 || col != 0)
	{
		// 둘 중 하나가 먼저 0이 되면 나머지는 그대로 넣기.
		if (row == 0) // col을 돌며 삽입만 계속한다.
		{
			while (col--) route += 'I';
			col = 0;
		}
		else if (col == 0)	// row를 돌며 삭제만 계속한다.
		{
			while (row--) route += 'D';
			row = 0;
		}
		else
		{
			// 왼쪽, 위쪽, 좌상 중에 되는 곳으로 간다. 어차피 여기서 되는 갈래가 많이 나온다는건 결과가 여러개라는 뜻이니 하나만 보면 된다.

			if (table[row - 1][col - 1] == table[row][col] && a[row - 1] == b[col - 1])
			{
			route += 'M';
			row--; col--;
			}
			else if (table[row - 1][col - 1] + 1 == table[row][col])
			{
			route += 'S';
			row--; col--;
			}
			else if (table[row - 1][col] + 1 == table[row][col])
			{
				route += 'D';
				row--;
			}
			else if (table[row][col - 1] + 1 == table[row][col])
			{
				route += 'I';
				col--;
			}
			// 이 4가지의 경우가 아니면 존재할 수 없다.
			else
			{
				cout << "무언가 잘못됐다.\n";
				row = 0; col = 0;
			}
		}
	}

	// route를 뒤집어서 원래대로 놓는다.
	reverse(route.begin(), route.end());

	cout << route << endl;
	return 0;
}