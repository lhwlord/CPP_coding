#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;


// 백준 #1013 : Contact
int main(void)
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		char c[201];
		scanf("%200s", c);
		c[200] = '\0';
		int len = strlen(c);

		// 이하의 규칙을 만족하지 않으면 바로 NO 쪽으로 보낸다.
		for (int i = 0; i < len; i++)
		{
			if (c[i] == '0')
			{
				if (i == len - 1 || c[i + 1] == '0') goto out;
				else
				{
					i++; continue;
				}
			}
			else // 입력 형태 상 무조건 1이라고 가정한다.
			{
				if (i >= len - 3) goto out;
				else
				{
					if (c[i + 1] == '1' || c[i + 2] == '1') goto out;
					i += 3;
					while (i < len - 2 && c[i] == '0') i++;
					if (i == len - 2) // 00, 01, 10, 11 뿐이다.
					{
						if (c[i + 1] == '0') goto out;
						else break;
					}
					if (c[i] != '1') goto out;
					while (i != len - 1 && c[i] == '1') i++;
					if (i == len - 1) break;
					else // 1001 루트 바로 뒤에 다시 1001이 올 수도 있다.
						// 01루트라면 그대로 진행하고, 아니라면 1을 살린 후 다음번에 판단하도록.
					{

						if (c[i + 1] == '1') i--; // for문 또한 i를 늘리기 때문
						else // 이번 예외는, 앞의 1001에 끝 1이 하나뿐인 경우이다.
						{
							if (c[i - 2] == '0') i--;
							else i -= 2;
						}
					}
				}
			}
		}

		printf("YES\n");
		continue;

	out:
		printf("NO\n");

	}
	return 0;
}