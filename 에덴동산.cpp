#include <iostream>
#include <string>

using namespace std;

char matchTable[8];	// ��ġ���̺�. �ٱ������� ���� �����ϰ� ��������ȭ.
bool matched = false;	// �ϳ��� ��ġ�Ǿ��ٸ� true.
string target;	// ���� ��Ʈ��.

// �־��� ũ�⸸ŭ, ������ �����迭�� ���� �����.
// ���� ����������� ������ ���� �˻��ϴ� �ڵ� �߰�.
void makeBinaryAndCheck(int num, string s)
{
	if (!matched)	// �̹� ��ġ������ �̰� �� �ʿ� ����.
	{
		if (num == 0)	// ������ ���� ��� �ϳ��� ��������Ƿ�, �̿� ���� ���̺� �������� üũ.
		{
			string result = "";
			for (int i = 0; i < s.length(); i++)
			{
				char left, right;
				int temp;
				// �糡���� ��� ���� ó��.
				if (i == 0)
				{
					left = s[s.length() - 1];
					right = s[1];
				}
				else if (i == s.length() - 1)
				{
					left = s[i - 1];
					right = s[0];
				}
				else
				{
					left = s[i - 1];
					right = s[i + 1];
				}
				temp = (left - '0') * 4 + (s[i] - '0') * 2 + (right - '0');
				result += matchTable[temp];
			}
			if (target == result)	// ���� ���ٸ�
			{
				matched = true;
			}
		}
		else
		{
			makeBinaryAndCheck(num - 1, s + '0');
			makeBinaryAndCheck(num - 1, s + '1');
		}
	}
}

// �������̺�(10������ ���� �־���), �� ����, ���ϴ� ���� �Է�. ���ᱸ�� ����
// ��� �ʱ�����̴��� �������̺��� ��Ģ�� ���� ���ϴ� ���°� �������� ���.
/*
�ַ�� : �ϴ� �������� �����ٰ� ������ ��� ���¸� �����ϰ�, �ϳ��� �����ϴٰ� �ߴ� ��� REACHABLE. �� ���Ҵµ� �ȶ߸� GARDEN OF EDEN.
*/
int main(void)
{
	// gets, scanf_s�� �� �����ٰ� �ϴ� �װ� �Ἥ �����ϵ��� ����.
	int bin, num;
	char c[33];
	char temp;

	
	// 3���� ���� ��� �Է¹ޱ�
	while (scanf_s("%d %d %s", &bin, &num, c, 33) != EOF)	// ���ٴ��� �Է��̴�. ���� ���� �Է¹޴� ���忡�� �̰� �� ���Ҽ��� �ִ�. ������ parsing�ϴ� �ͺ��� �� ����.
		// ***** scanf_s �ȿ� ���ڿ� ���� ũ�⸦ �԰� �ܷ� �̻��ϰ� �������� �� ��!!
	{
		// bin�� �� �迭�� ������ �ڵ�� ����ִ´�.
		for (int i = 7; i != -1; i--)
		{
			matchTable[i] = bin % 2 + '0';
			bin >>= 1;
		}
		c[32] = '\0';	// �̰� ������ �����Ϸ��� �Ҿ��ϴٰ� �������.
		target = c;

		// ��ͷ� �ϳ��� �̱�. �˻�� ��� �ȿ��� ����
		makeBinaryAndCheck(num, "");

		if (matched) cout << "������!\n";
		else cout << "�������긶�� ����!\n";
		matched = false;
	}
	return 0;
}