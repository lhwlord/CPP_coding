#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;


// ���� #1013 : Contact
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

		// ������ ��Ģ�� �������� ������ �ٷ� NO ������ ������.
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
			else // �Է� ���� �� ������ 1�̶�� �����Ѵ�.
			{
				if (i >= len - 3) goto out;
				else
				{
					if (c[i + 1] == '1' || c[i + 2] == '1') goto out;
					i += 3;
					while (i < len - 2 && c[i] == '0') i++;
					if (i == len - 2) // 00, 01, 10, 11 ���̴�.
					{
						if (c[i + 1] == '0') goto out;
						else break;
					}
					if (c[i] != '1') goto out;
					while (i != len - 1 && c[i] == '1') i++;
					if (i == len - 1) break;
					else // 1001 ��Ʈ �ٷ� �ڿ� �ٽ� 1001�� �� ���� �ִ�.
						// 01��Ʈ��� �״�� �����ϰ�, �ƴ϶�� 1�� �츰 �� �������� �Ǵ��ϵ���.
					{

						if (c[i + 1] == '1') i--; // for�� ���� i�� �ø��� ����
						else // �̹� ���ܴ�, ���� 1001�� �� 1�� �ϳ����� ����̴�.
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