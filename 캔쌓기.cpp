#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
	string s;

	while (getline(cin, s))	// 스트링 입력받기
	{
		stringstream ss1(s);
		string input[1000];
		stack<string> SS;
		int temp = 0;
		while (getline(ss1, input[temp++], ' '));	// 스트림에 공백단위로 스트링배열로 넣기
		for (int i = 0; i < temp; i++)	// 스트링배열에서 빼와서 비교하면서 연산
		{
			if (input[i].compare("*") == 0)
				SS.pop();
			else
				SS.push(input[i]);
		}
		SS.pop();	// 공백들어있는거 후속조치

		while (SS.size() != 0)
		{
			cout << SS.top() << ' ';
			SS.pop();
		}
		cout << endl;

	}
	return 0;
}