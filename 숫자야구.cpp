#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

// README
/*
* ����ȯ�� : ������ 10, Microsoft Visual Studio 2019
* ������ : ���־�Ʃ����� ���� ���� �� ������
*/


// 3�ڸ� �������� ��ȯ. �� �� �ڸ� ���ڴ� ��ġ�� �ȵ�
int generateNumber()
{
	while (1)
	{
		int temp = rand() % 987; // 988���ʹ� ���ʿ� ��ģ��
		int fir, sec, thr;
		fir = temp / 100;
		sec = (temp % 100) / 10;
		thr = temp % 10;
		if (fir == sec || sec == thr || thr == fir) continue;
		if (fir == 0 || sec == 0 || thr == 0) continue;	// ���ƺ��̴� ����� �ƴѰ� ������, �ڵ� ����� ����.
		return temp;
	}
}

// ����� �Է°� ������ �޾Ƽ�, �Ұ����� ��ȯ. ��Ʈ����ũ/�� ���� ��±���
bool testAnswer(int myNum, int answer)
{
	int strike = 0, ball = 0;

	// ���� ���ϰ� ����ֱ�
	string a = to_string(myNum), b = to_string(answer);

	// ���� ��ġ�� �ִ������� �˻�
	for (int i = 0; i < 3; i++)
	{
		if (a[i] == b[i])
		{
			strike++;
			a[i] = 10; b[i] = 10;	// �����߱� ������ ���� �� ���� ���� �ִ´�.
		}
	}

	// ���� ��ġ�°� �ִ��� �˻�
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i] == b[j] && a[i] != 10) ball++;
		}
	}

	printf("%d strikes, %d balls\n", strike, ball);

	return strike == 3 ? true : false;
}

// ����ڰ� ���� ���⶧���� �Է¹ް� testAnswer �Լ� ȣ��
int main(void)
{
	srand(time(NULL));

	int answerNum = generateNumber();

	// printf("�ӽ� : %d\n", answerNum);

	int myNum;
	do
	{
		printf("Input your guess: ");

		scanf("%d", &myNum);	// ��, ����ڰ� �׻� 3�ڸ����� �ִ´ٰ� �����Ѵ�.

	} while (!testAnswer(myNum, answerNum));

	printf("You Successed!");

}
