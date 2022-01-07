#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t_case;
	scanf_s("%d", &t_case);
	for (int caseNum = 0; caseNum < t_case; caseNum++)
	{
		int repeat;
		string s;
		cin >> repeat >> s;

		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j < repeat; j++)
				cout << s[i];
		}cout << endl;

	}
}