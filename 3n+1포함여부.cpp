#include <iostream>

using namespace std;

// �� ���� 3n+1 ������ �� ���� ���ԵǴ��� ���θ� �Ǵ��ϴ� ���α׷�

void main(void)
{
	int a, b;
	

	while (cin >> a >> b)
	{
		int isCorrect = 0;
		int curNum = a;
		if (a == b)
		{
			cout << "Y" << endl;
			isCorrect = 1;
			break;
		}
		while (curNum != 1)
		{
			if (curNum % 2 == 0) curNum /= 2;
			else curNum = curNum * 3 + 1;

			if (curNum == b)
			{
				cout << "Y" << endl;
				isCorrect = 1;
				break;
			}
		}
		if(isCorrect == 0) cout << "N" << endl;
	}

	return;
}