/*
��ȣ�� ��Ī���̺��� �� ������ �Ѵ�.

������ ����� �߿��� the quick brown ���ñ�� ��ȣȭ�� ���尰���� ���� ã�ƴٰ� ��Ī���̺� �÷����� �ͱ��� �����ؾ� �Ѵ�.

����� �ִ�. �ϴ� ���� �� ���帶�� ������ ������� ��ġ�� �õ��Ѵ�. ���� ��ġ���� �ʴ´ٸ� ���а�, ��Ī�Ǵ� ������ �ִٸ� �װ� ���ٰ� �����ϸ� �ȴ�. �׸��� �װ� �̿��ؼ� �ش� ���̽��� �ٸ� ����鵵 ���� ��ȣȭ��Ű�� ��.


vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq
*/

#include <iostream>
#include <string>

using namespace std;


bool match(string, int[123][2]);
void map_print(string[], int, int[123][2]);

// �׽�Ʈ ���̽� ������ �Է¹޴´�. ���̽� ������ �� ��� �Է� ���̿��� ����.(ó�� ���� ���ص� ��)
// �� �׽�Ʈ ���̽����� ���� ���� ���ڿ��� �Էµ� �� �ִ�. �׽�Ʈ ���̽� ���� ������ ����.
// �� �׽�Ʈ ���̽��� ���� ���� ���ڿ� �� �� ���� ������ the quick brown fox jumps over the lazy dog���, ���ĺ� 26�ڰ� ���� ���� �����̴�. �� Ű ������ �̿��ؼ� �ش� �׽�Ʈ ���̽��� ��ȣȭ�� ��.
// ���� �� ������ ���ٴ��� �ϴ� ������ ��ȣȭ�� �����ߴٸ�, No solution. �̶�� ������ ����� ��.
int main(void)
{
	int testCase;
	cin >> testCase;
	cin.get();
	cin.get();
	for (int test = 0; test < testCase; test++)
	{
		int arr[123][2] = {{0,},};	// �ε����� ��ġ�Ǵ� 1����, �׸��� ��ġ�ƴ��� Ȯ���ϴ� �迭
		string str[100];
		int count = 0;
		
		// �����Է� �ϳ��� ���� �ʴ� �� ������ ��� �о���̱�
		
		while (true)
		{
			char c;
			cin.get(c);
			if (c != '\n')
			{
				getline(cin, str[count]);
				//cin >> str[count];
				str[count++].insert(0, 1, c);
			}
			else break;
		}

		/*
		// �迭�� �� ���� Ȯ��
		for (int i = 0; i < count; i++)
		{
			cout << str[i] << endl;
		}*/


		bool isMatched = false;
		// �� ���帶�� ��������� ��ġ �õ�.
		for (int i = 0; i < count; i++)
		{
			if (match(str[i], arr)) isMatched = true;
		}
		if (!isMatched)
		{
			cout << "No solution.\n";
		}
		else
		{
			map_print(str, count, arr);
		}
	}

	return 0;
}

// ������� ���ؼ� ������ �Ǵ��� Ȯ��.
bool match(string s, int arr[123][2])
{
	string quick = "the quick brown fox jumps over the lazy dog";
	if (s.length() != quick.length()) return false;	// ���̰� �ٸ��� ���� ��ȯ


	for (int i = 0; i < s.length(); i++)
	{
		// ���� ��ġ�� �ٸ��ٸ� ���� ��ȯ
		if ((s[i] == ' ' && quick[i] != ' ') || (s[i] != ' ' && quick[i] == ' ')) return false;

		// �ش� ���ڰ� ���� ��ġ���� �ʾҴٸ� ��ġ�ϰ� �� ���� �õ�. ���߿� ������ ���ٳ��� ���� ���� �ʱ�ȭ�ϰ� ���� ��ȯ
		if (arr[s[i]][1] == 0 || arr[s[i]][0] == quick[i])
		{
			arr[s[i]][0] = quick[i];
			arr[s[i]][1] = 1;
		}
		else
		{
			for (int j = 0; j < 123; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					arr[j][k] = 0;
				}
			}
			return false;
		}
	}
	// for���� ���� ���Ҵٴ� ���� ���������� ��Ī�ߴٴ� ���̹Ƿ� �� ��ȯ.
	return true;
}

// ���� �Ϸ�. �̰ɷ� ���� �ٲ�ٰ� ����ϸ� �ȴ�.
void map_print(string str[], int count, int arr[123][2])
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] == ' ') cout << ' ';
			else cout << (char)arr[str[i][j]][0];
		}
		cout << endl;
	}
}
