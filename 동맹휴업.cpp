#include <iostream>

using namespace std;

typedef struct {
	int day;
	int partyNum;
	int* rest;
} cases;

int findRestDays(cases&);

int main(void)
{
	int testCase;
	cin >> testCase;
	cases* cased = new cases[testCase];	// ���̽� �迭 �����Ҵ�
	int casedNum;	// ���̽� �迭�� ������ ����
	for (int i = 0; i < testCase; i++)	// �׽�Ʈ���̽���ŭ �ޱ�
	{
		cin >> cased[i].day;
		cin >> cased[i].partyNum;
		cased[i].rest = new int[cased[i].partyNum];	// �� ���̽��� ���簳���� �����Ҵ�
		for (int j = 0; j < cased[i].partyNum; j++)	// ���� ������ŭ �� ������ �޾����� �ľ�
		{
			cin >> cased[i].rest[j];
		}
	}	// ������� ������ �� �׽�Ʈ ���̽����� ���� �Է¹��� ���̴�.

	for (int i = 0; i < testCase; i++)
	{
		cout << findRestDays(cased[i]) << endl;	// �� ���̽��� �޾��ϼ� �ľ�
	}

	// ������� �����Ҵ� ��ȯ.
	for (int i = 0; i < testCase; i++)
	{
		delete[] cased[i].rest;	// �� ����ü�� �Ҵ�� �����Ҵ� �޸� ��ȯ
	}
	delete[] cased;	// ���̽� �迭 ��ü�� ��ȯ
	return 0;
}

int findRestDays(cases& go)	// ������ ���� ȣ��� �����ϰ� ��� ����.
{
	int count = 0;
	for (int i = 1; i <= go.day; i++)
	{
		bool rest = false;
		for (int j = 0; j < go.partyNum; j++)
		{
			if (i % go.rest[j] == 0)
				rest = true;
		}
		if (i % 7 == 0 || i % 7 == 6)
			rest = false;
		count = rest ? count+1 : count;
	}

	return count;
}