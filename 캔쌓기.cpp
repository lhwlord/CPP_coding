#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
	string s;

	while (getline(cin, s))	// ��Ʈ�� �Է¹ޱ�
	{
		stringstream ss1(s);
		string input[1000];
		stack<string> SS;
		int temp = 0;
		while (getline(ss1, input[temp++], ' '));	// ��Ʈ���� ��������� ��Ʈ���迭�� �ֱ�
		for (int i = 0; i < temp; i++)	// ��Ʈ���迭���� ���ͼ� ���ϸ鼭 ����
		{
			if (input[i].compare("*") == 0)
				SS.pop();
			else
				SS.push(input[i]);
		}
		SS.pop();	// �������ִ°� �ļ���ġ

		while (SS.size() != 0)
		{
			cout << SS.top() << ' ';
			SS.pop();
		}
		cout << endl;

	}
	return 0;
}