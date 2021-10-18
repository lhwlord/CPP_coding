#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool match(string[], string, int[], bool[], int);

int main(void)
{
	int dicNum;
	string dic[1000];
	string s;	// ��ȣ�� �Է¹ޱ�
	
	cin >> dicNum;
	for (int i = 0; i < dicNum; i++)
	{
		cin >> dic[i];
	}
	cin.clear();	// ���� ����
	while (getline(cin, s))
	{
		int arrNum = 0;	// ��ȣ���迭 ���� ���Կ�
		stringstream ss1(s);	// �ڸ����
		int matchArr[200] = { 0, };
		bool isMatched[200] = { false, };
		string arr[80];	// �Է¹��� ��ȣ���� �ܾ������ �ڸ���

		while (getline(ss1, arr[arrNum++], ' '));	// �� �߶� �ִ´�.

		for (int i = 0; i < arrNum; i++)
		{
			match(dic, arr[i], matchArr, isMatched, dicNum);
		}
		cout << endl;
	}

	return 0;
}

// ������ ��ȣ�ܾ�, ��ġ������ �̿��� ��ġ���� �Ǻ� �� �ű� ��ġ ����.
bool match(string dic[], string word, int matchArr[], bool isMatched[], int dicNum)
{
	
	for (int i = 0; i < dicNum; i++) // �����ܾ�� �ϳ��� ��Ī�ϴ� ��.
	{
		char c;
		if (word.length() == dic[i].length())	// �ܾ���� ������.
		{
			// �ܾ���̰� �����ϹǷ�, ���� ���� ������ ��Ī�� �õ��Ѵ�. �ܾ��� ������. �̷��ٰ� �ϳ��� ��Ī�� �����Ǹ� �� �ѱ��.
			bool Matched = true;
			for (int j = 0; j < word.length() && Matched; j++)
			{
				if (matchArr[word[j]] == 0)	// ���� ���ٸ�..
				{
					if (isMatched[dic[i][j]] == true)	// ��ȣ���� �ܾ�� ��Ī���� ������, ��ǥ�ܾ ��Ī�Ǿ��°�?
						Matched = false;	// �����ܾ�� �̹� ��Ī�Ǿ���. ���� �ܾ��.
					else
					{
						// ��ȣ�� �ܾ ��Ī���� �����鼭, ��ǥ �����ܾ� ���� ��Ī���� �ʾҴ�! ���� ������� ��ȸ�̴�.
						matchArr[word[j]] = dic[i][j];
						isMatched[dic[i][j]] = true;
					}
				}
				else
				{
					if (matchArr[word[j]] == dic[i][j])	// ���� ������ ��Ī�� �ȴٸ�
						;	// �״�� ����.
					else
						Matched = false;	// �ִ� ���� �ٸ��ٸ� ��ġ�� ����. ���� �ܾ��.
				}
			}
			if (Matched)// true�� ���Ҵٴ� ���� �ش� �ܾ �Ϻ��� ��Ī�Ǿ��ٴ� ��. ���⼭ ����, �ܾ� ����ϰ� ��ȯ�Ѵ�.
			{
				cout << dic[i] << ' ';
				return true;
			}
		}
	}
	// ���ο��� �ذ��� �ȵƴٸ� �ܾ��ġ�� ������ ���̹Ƿ�
	for (int i = 0; i < word.length(); i++)
	{
		cout << '*';
	}
	cout << ' ';
	return false;
}
