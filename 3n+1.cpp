#include <iostream>
#include<malloc.h>
using namespace std;

int getCycle(int);

int  main(void)
{
	int a, b;
	cout << "두 수를 입력받아 그 범위 내에서 3n+1 의 최대 사이클 수를 찾는 프로그램" << endl;
	cout << "짝수인 경우 절반, 홀수인 경우 3n+1을 해서 1이 될 때까지의 진행단계를 센다." << endl;

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