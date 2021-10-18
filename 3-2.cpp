#include <iostream>

using namespace std;

typedef struct {
	int day;
	int partyNum;
	int* rest;
} cases;

int main(void);

int findRestDays(cases&);
void findRestAndPrint(cases&);

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
		//cout << findRestDays(cased[i]) << endl;	// �� ���̽��� �޾��ϼ� �ľ�

		findRestAndPrint(cased[i]);
		cout << endl;
	}

	// ������� �����Ҵ� ��ȯ.
	for (int i = 0; i < testCase; i++)
	{
		delete[] cased[i].rest;	// �� ����ü�� �Ҵ�� �����Ҵ� �޸� ��ȯ
	}
	delete[] cased;	// ���̽� �迭 ��ü�� ��ȯ
	return 0;
}

// �̰� �� �ǵ���� �Ѵ�. Ȥ�� ������ �ٸ� �Լ��� ������.
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
		count = rest ? count + 1 : count;
	}

	return count;
}

// ��Ģ�� �´� ��¥�� ã�ƴٰ� ī��Ʈ�ϰ�, �迭�� ������� �ڿ� ����ϸ� �ɵ�.
void findRestAndPrint(cases& go)
{
	int count = 0;	// ���³� �Ѱ�
	int weekDay[100] = { 0,}; // ���� ��¥ �����ϴ� �迭
	int weekDayCount = 0;
	for (int i = 1; i <= go.day; i++)// ��¥�� ���鼭
	{
		int halfRest = 0;
		for (int j = 0; j < go.partyNum; j++)	// �� �޾��ϼ��� ����...
		{
			//�ش� ��¥�� �ָ�, �������� �ƴ� ��쿡 ������ ��
			if ((i % 7 != 1) && (i % 7 != 0) && (i % 7 != 4))
			{
				if (i % go.rest[j] == 0)	 // �޾��ϼ��� �������� �� ��¥�� �´ٸ�
					halfRest++;
			}
		}
		float check = (float)go.partyNum / 2;
		if ((float)halfRest >= check)	// ���� �̻��� �޾��� �����ߴٸ�
		{
			count++;
			weekDay[weekDayCount++] = i;	// ��¥�迭���� ����ڱ�
		}
	}

	// ��¥�� �� ���鼭 �ش��ϴ� ���ڵ� ���� �ľ��߰�, ���� ������ ��� ���̴�.
	cout << "Lost: " << count << endl;
	for (int i = 0; i < count; i++)
	{
		string temp;
		switch (weekDay[i] % 7)
		{
		case 2 : 
			temp = "Mon";
			break;
		case 3 : 
			temp = "Tue";
			break;
		case 5 : 
			temp = "Thu";
			break;
		case 6 : 
			temp = "Fri";
			break;
		default : 
			// ���ü��� ����.
			break;
		}
		cout << temp << ": " << weekDay[i] << endl;
	}
	return;
}
