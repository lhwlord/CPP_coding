#include <iostream>

#define abs(x) (x) < 0 ? -(x) : x

using namespace std;

void main()
{
	cout << "n�� ���� �̷��� ������ ������ ���̰� 1~n-1���� ���� ������ ��츦 �Ǵ��ϴ� ���α׷�" << endl;


	while (1)
	{
		int check[3000] = { 0, }, input[3000], count = 0, gap = 0, finalcheck = 0;

		cin >> count;

		for (int i = 0; i < count; i++)
		{
			cin >> input[i];
		}

		for (int i = 0; i < count - 1; i++)
		{
			gap = input[i] - input[i + 1];
			gap = abs(gap);
			check[gap]++;
		}

		for (int i = 1; i < count; i++)
		{
			if (check[i] != 1) finalcheck = 1;
		}

		if (finalcheck == 0) cout << "�̻����� �����ϴ�!" << endl;
		else cout << "�̻����� �������� �ʴ�!" << endl;

	}


	return;
}