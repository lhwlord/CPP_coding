#include <iostream>
#include <string>

using namespace std;

// Ű���忡�� ����� ���������� �̵����� Ÿ�����ߴ� �����ϰ� ������ Ǭ��.
// Ư���� ���� ������ Q, A, Z, `�� ���ڵ��� ĥ �� ����.
// ���ڿ��� �Էµ��� �� �̸� �������� �� ĭ �̵���Ų ����� ǥ��.
int main(void)
{
	string line;

	string table = " `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	// 1 14 27 38��° �ε����� �Է����� �־����� �ȵǴ� ���̴�. ����ó�� �� ��
	
	while (getline(cin, line))
	{
		string result = "";
		int index;
		for (int i = 0; i < line.length(); i++)
		{
			index = table.find(line[i]);
			if (index == -1 || index == 1 || index == 14 || index == 27 || index == 38)
			{
				cout << "��ȿ���� ���� ���� �����ϴ� : " << i << ", " << line[i] << endl;
				break;
			}
			else	// ��ġ�ϴ� ���ڸ� �߰��߰�, ������ �ȵǴ� ���ڵ� �ƴ϶�� ����
			{
				if (line[i] == ' ') result += table[index];
				else result += table[index - 1];
			}
		}
		cout << result << endl;
	}

	return 0;
}