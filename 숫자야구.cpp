#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

// README
/*
* 개발환경 : 윈도우 10, Microsoft Visual Studio 2019
* 실행방법 : 비주얼스튜디오로 파일 실행 후 컴파일
*/


// 3자리 랜덤숫자 반환. 단 각 자리 숫자는 겹치면 안됨
int generateNumber()
{
	while (1)
	{
		int temp = rand() % 987; // 988부터는 애초에 겹친다
		int fir, sec, thr;
		fir = temp / 100;
		sec = (temp % 100) / 10;
		thr = temp % 10;
		if (fir == sec || sec == thr || thr == fir) continue;
		if (fir == 0 || sec == 0 || thr == 0) continue;	// 좋아보이는 방식은 아닌것 같지만, 코드 보기는 쉽다.
		return temp;
	}
}

// 사용자 입력과 정답을 받아서, 불값으로 반환. 스트라이크/볼 정보 출력까지
bool testAnswer(int myNum, int answer)
{
	int strike = 0, ball = 0;

	// 쓰기 편하게 집어넣기
	string a = to_string(myNum), b = to_string(answer);

	// 같은 위치에 있는지부터 검사
	for (int i = 0; i < 3; i++)
	{
		if (a[i] == b[i])
		{
			strike++;
			a[i] = 10; b[i] = 10;	// 분해했기 때문에 나올 수 없는 수를 넣는다.
		}
	}

	// 이제 겹치는게 있는지 검사
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

// 사용자가 정답 맞출때까지 입력받고 testAnswer 함수 호출
int main(void)
{
	srand(time(NULL));

	int answerNum = generateNumber();

	// printf("임시 : %d\n", answerNum);

	int myNum;
	do
	{
		printf("Input your guess: ");

		scanf("%d", &myNum);	// 단, 사용자가 항상 3자리수를 넣는다고 가정한다.

	} while (!testAnswer(myNum, answerNum));

	printf("You Successed!");

}
