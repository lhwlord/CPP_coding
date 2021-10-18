#include <iostream>
#include <string>
#include <sstream>
#include <queue>


using namespace std;

void tablePlus(char, int[], int);
void tableMinus(char, int[], int);

int main(void)
{
	int seat;
	cin >> seat;

	cin.ignore(2, '\n');

	string s;	// �մ� ��⿭
	getline(cin, s);	// ��⿭ �Է¹ޱ�
	string arr[999];	// ��⿭ ���ڴ����� �ڸ���
	int arrNum = 0;
	stringstream ss1(s);
	while (getline(ss1, arr[arrNum++], ' '));	// �⺻���� ���ڿ��޾� �ܾ� �ڸ��� ����

	// ó�� �Է¹��� ���ڵ��� arr�� �� �����ߴ�.

	queue<char> Q;	// ��Դ°� ����.
	int count = 0;
	int* table;
	table = new int[seat];	// Ź�� ���� ���̺�
	for (int i = 0; i < seat; i++) table[i] = '0';	// �ʱ�ȭ.

	for (int i = 0; i < arrNum; i++)
	{
		if (arr[i][0] >= 65 && arr[i][0] <= 90)	// ���� ���ĺ� �빮�ڶ��
		{
			// �־�� �Ѵ�, �� �� ���ִٸ� ����ĥ ��.
			if (Q.size() < seat)
			{
				Q.push(arr[i][0]);
				tablePlus(arr[i][0], table, seat);// ���̺� �߰���ų ��. ���ʺ��� Ž���ϸ鼭.
			}
		}
		else if (arr[i][0] == '*')	// *�̶�� �� ��.
		{
			tableMinus(Q.front(), table, seat);	// ���̺��� �ش��ϴ� ���� ���� ��.
			Q.pop();
		}
	}

	for (int i = 0; i < seat; i++)
	{
		switch (table[i])
		{
		case '0' : 
			cout << "# ";
			break;
		default : 
			cout << (char)table[i] << " ";
			break;
		}
	}

	return 0;
}

// ���̺� �߰���Ų��. ���ɿ��δ� �̸� Ȯ���ߴ�.
void tablePlus(char ch, int arr[], int seat)
{
	for (int i = 0; i < seat; i++)
	{
		if (arr[i] == '0')
		{
			arr[i] = ch;
			return;
		}
	}
	cout << "�ֱ����." << endl;
	return;
}

// ���̺��� ����. �̹� �ִ³� ����� �� ��.
void tableMinus(char ch, int arr[], int seat)
{
	for (int i = 0; i < seat; i++)
	{
		if (arr[i] == ch)
		{
			arr[i] = '0';
			return;
		}
	}
	cout << "�������." << endl;
	return;
}
