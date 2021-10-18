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
		//cout << findRestDays(cased[i]) << endl;	// 각 케이스의 휴업일수 파악

		findRestAndPrint(cased[i]);
		cout << endl;
	}

	// 여기부턴 동적할당 반환.
	for (int i = 0; i < testCase; i++)
	{
		delete[] cased[i].rest;	// 각 구조체에 할당된 동적할당 메모리 반환
	}
	delete[] cased;	// 케이스 배열 자체도 반환
	return 0;
}

// 이걸 좀 건드려야 한다. 혹은 버리고 다른 함수를 만들자.
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
		count = rest ? count + 1 : count;
	}

	return count;
}

// 규칙에 맞는 날짜를 찾아다가 카운트하고, 배열에 꼬라박은 뒤에 출력하면 될듯.
void findRestAndPrint(cases& go)
{
	int count = 0;	// 쉬는날 총계
	int weekDay[100] = { 0,}; // 쉬는 날짜 저장하는 배열
	int weekDayCount = 0;
	for (int i = 1; i <= go.day; i++)// 날짜를 세면서
	{
		int halfRest = 0;
		for (int j = 0; j < go.partyNum; j++)	// 각 휴업일수에 따라서...
		{
			//해당 날짜가 주말, 수요일이 아닌 경우에 진행할 것
			if ((i % 7 != 1) && (i % 7 != 0) && (i % 7 != 4))
			{
				if (i % go.rest[j] == 0)	 // 휴업일수로 나눴을때 그 날짜가 맞다면
					halfRest++;
			}
		}
		float check = (float)go.partyNum / 2;
		if ((float)halfRest >= check)	// 절반 이상이 휴업에 동의했다면
		{
			count++;
			weekDay[weekDayCount++] = i;	// 날짜배열에도 꼬라박기
		}
	}

	// 날짜를 다 세면서 해당하는 일자도 전부 파악했고, 이제 남은건 출력 뿐이다.
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
			// 나올수가 없다.
			break;
		}
		cout << temp << ": " << weekDay[i] << endl;
	}
	return;
}
