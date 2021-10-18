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
	cases* cased = new cases[testCase];	// 케이스 배열 동적할당
	int casedNum;	// 케이스 배열이 어디까지 갈지
	for (int i = 0; i < testCase; i++)	// 테스트케이스만큼 받기
	{
		cin >> cased[i].day;
		cin >> cased[i].partyNum;
		cased[i].rest = new int[cased[i].partyNum];	// 각 케이스의 정당개수도 동적할당
		for (int j = 0; j < cased[i].partyNum; j++)	// 정당 개수만큼 각 정당의 휴업지수 파악
		{
			cin >> cased[i].rest[j];
		}
	}	// 여기까지 했으면 각 테스트 케이스마다 전부 입력받은 것이다.

	for (int i = 0; i < testCase; i++)
	{
		cout << findRestDays(cased[i]) << endl;	// 각 케이스의 휴업일수 파악
	}

	// 여기부턴 동적할당 반환.
	for (int i = 0; i < testCase; i++)
	{
		delete[] cased[i].rest;	// 각 구조체에 할당된 동적할당 메모리 반환
	}
	delete[] cased;	// 케이스 배열 자체도 반환
	return 0;
}

int findRestDays(cases& go)	// 참조에 의한 호출로 간편하게 사용 가능.
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