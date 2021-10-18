#include <iostream>
#include <cstdio>

#define abs(x) (x) < 0 ? -(x) : x
#define MAX 3000
#define LIMIT 5000

using namespace std;


int main()
{
	cout << "�������� �� ���̰� 1���� ��� ���� - 1���� �ѹ��� ���� �������� Ȯ���ϴ� ���α׷�. �ִ� 3000���� ��ġ �Է� ����" << endl;
	char buf[100];	// �ٹٲ޿� �ӽù���

	int countNum;

	while (scanf_s("%d", &countNum) == 1)
	{
		bool check[LIMIT] = { 0, }, isCor = 1;
		int prv, cur, gap = 0;

		if (countNum > MAX)
		{
			cout << "�Է� ���� ��ġ �ʰ�." << endl;
			break;
		}

		cin >> prv;

		for (int i = 0; i < countNum - 1; i++)
		{
			cin >> cur;

			gap = abs(cur - prv);

			if ((gap > MAX) || check[gap] || gap == 0)	// ���̰� �ִ�ġ�� �Ѱų� �̹� �ִ� ���̶��, ���� 0�� ���ٸ� �� �� �ʿ䵵 ���� �������� �ʴ�.
			{
				isCor = 0;
				break;
			}

			check[gap]++;
			prv = cur;

		}
		// �� �϶������ ���� �𸣰����� �ٹٲ��� �Ϸ���. ������ ���� ���� �� �ִ��.
		gets_s(buf);
		isCor ? cout << "�̻����� �����ϴ�!" << endl : cout << "�̻����� �������� �ʴ�!" << endl;

	}

	return 0;
}