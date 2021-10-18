#include <iostream>
#include <cstdio>

#define abs(x) (x) < 0 ? -(x) : x
#define MAX 3000
#define LIMIT 5000

using namespace std;


int main()
{
	cout << "수열따라 그 차이가 1부터 요소 개수 - 1까지 한번씩 전부 나오는지 확인하는 프로그램. 최대 3000개의 수치 입력 가능" << endl;
	char buf[100];	// 줄바꿈용 임시버퍼

	int countNum;

	while (scanf_s("%d", &countNum) == 1)
	{
		bool check[LIMIT] = { 0, }, isCor = 1;
		int prv, cur, gap = 0;

		if (countNum > MAX)
		{
			cout << "입력 가능 수치 초과." << endl;
			break;
		}

		cin >> prv;

		for (int i = 0; i < countNum - 1; i++)
		{
			cin >> cur;

			gap = abs(cur - prv);

			if ((gap > MAX) || check[gap] || gap == 0)	// 차이가 최대치를 넘거나 이미 있는 값이라면, 또한 0에 들어간다면 더 볼 필요도 없이 윾쾌하지 않다.
			{
				isCor = 0;
				break;
			}

			check[gap]++;
			prv = cur;

		}
		// 왜 하라는지는 아직 모르겠지만 줄바꿈을 하랜다. 안읽은 줄이 있을 수 있댄다.
		gets_s(buf);
		isCor ? cout << "이새끼는 윾쾌하다!" << endl : cout << "이새끼는 윾쾌하지 않다!" << endl;

	}

	return 0;
}