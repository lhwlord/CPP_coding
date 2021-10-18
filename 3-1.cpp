#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	while (getline(cin, s))
	{
		char arr[300] = { NULL, };
		char result[100] = { NULL, };
		int cardNum = 0, cur = 0;

		s.copy(arr, s.length());

		for (int i = 0; i < s.length(); i++)
		{
			if (arr[i] >= 65 && arr[i] <= 90) // 영문 대문자라면
			{
				result[cur++] = arr[i];
				cardNum++;
				if (cardNum > 10)
				{
					cur--;
					cardNum--;
				}
			}
			if (arr[i] == '*')	// 별이라면
			{
				if (cur > 0)
				{
					cur--;
					cardNum--;
				}
			}
		}

		for (int i = 0; i < cardNum; i++)
		{
			cout << result[i];
		}
		cout << endl;
	}



	return 0;
}