#include <iostream>
#include <string>

using namespace std;

bool findKey(string[100], int, char[123][2]);
void decodeAndPrint(string[100], int, char[123][2]);

// ù �ٿ��� ���� ���� 1�� : �׽�Ʈ���̽� ����
// ������ �� ��, ���̽��� �� �ٷ� ����
// �� ���̽��� ��ȣȭ�� ���� ��
// ��ȣȭ�� ������ �ҹ��ڿ� �����̽������� ����, �ִ� 80����
// �Է��ؽ�Ʈ ��ü�� 100�ٷ� ����
int main(void)
{
	int testCase;
	cin >> testCase;
	cin.ignore(2, NULL);	// ���� ���� ���� 2�� ����
	for (int i = 0; i < testCase; i++)	// ���̽����� ����
	{
		string str[100];
		int strIndex = 0;
		char match[123][2] = { {0}, };	// �ε����� ��ȣ��, ���� ���� ��ȣ������ �����Ѵ�.
		// ���� �Է� ������ �޾ƿ�
		do
		{
			getline(cin, str[strIndex++]);
		} while (! str[strIndex - 1].empty());


		// Ű ���� ã�Ƽ� �ص� �õ�. ã���� ��, ������ ��ȣȭ ���з� �����ϰ� ���� ��ȯ.
		if (! findKey(str, strIndex, match))
		{
			cout << "No solution.\n";
			continue;
		}

		// ������ �Ѿ�Դٸ� ��ġ�� ǥ�� �̿��� ��ȣȭ�� ���ÿ� ���.
		decodeAndPrint(str, strIndex, match);
	}
	return 0;
}

// str�� ���� Ű���忡 ��ġ�� �� �ִ����� �˻�. ������ ��Ī ������ ��, ���������� �ȳ����� ����.
bool findKey(string str[100], int strIndex, char match[123][2])
{
	string lock = "the quick brown fox jumps over the lazy dog";
	// �ϳ��� ���� �˻�.
	for (int i = 0; i < strIndex; i++)
	{
		if (str[i].length() != lock.length()) continue;	// ���� ���̰� �ٸ��� �н�.

		for (int j = 0; j < lock.length(); j++)
		{
			if ((lock[j] == ' ') ^ (str[i][j] == ' '))	goto SKIP;// �� ���� �����̸� �������� �׷��� �Ѵ�. �̰� �������� ���ϸ�(���� �ٸ���) �ٷ� ���� �������� �ѱ��.
			if (match[str[i][j]][1] == 1 && match[str[i][j]][0] != lock[j]) goto SKIP;	// ���ε����� �̹� ���ְ�, ������ ��ġ�� ���� ���� ���� ���� �ƴ϶�� �̰͵� �ٷ� �ѱ��.
			if (match[str[i][j]][1] == 0)	// �̷��� ���� �� �ִ�.
			{
				match[str[i][j]][0] = lock[j];
				match[str[i][j]][1] = 1;
			}
		}

		// ������� �Դٸ� �� ������ ���������� ��ġ�� ���̴�.
		return true;
		// �̰� �ƴϰ� ��ŵ���� ���� ����� ��ġ���̺��� ���� �絵���Ѵ�.
	SKIP : 
		for (int j = 0; j < 123; j++)
		{
			match[j][1] = 0;
		}
	}
	return false;
}

// ��ȣȭ�� ���ÿ� ���.
void decodeAndPrint(string str[100], int strIndex, char match[123][2])
{
	for (int i = 0; i < strIndex; i++)
	{
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] == ' ') cout << ' ';
			else
			{
				cout << match[str[i][j]][0];
			}
		}
		cout << endl;
	}
}