#include <iostream>
#include<malloc.h>
using namespace std;

int getCycle(int);

int  main(void)
{
	int a, b;
	cout << "�� ���� �Է¹޾� �� ���� ������ 3n+1 �� �ִ� ����Ŭ ���� ã�� ���α׷�" << endl;
	cout << "¦���� ��� ����, Ȧ���� ��� 3n+1�� �ؼ� 1�� �� �������� ����ܰ踦 ����." << endl;

	while (cin >> a >> b)
	{
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		int count = 1;

		int* arr = (int*)malloc(sizeof(int) * (b - a));

		


		for (int i = a; i <= b; i++)
		{
			int temp = getCycle(i);
			if (count < temp) count = temp;
		}



		cout << a << " " << b << " " << count << endl;
	}
	
}

int getCycle(int i)
{
	int count = 1;
	while (1)
	{
		if (i == 1) break;
		else
		{
			if (i % 2 == 0) i /= 2;
			else i = i * 3 + 1;

			count++;
		}
	}
	return count;
}