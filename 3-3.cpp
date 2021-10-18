#include <iostream>
#include <string>
#include <sstream>
#include <queue>


using namespace std;

void tablePlus(char, int[], int);
void tableMinus(char, int[], int);

int main(void)
{
	int seat;
	cin >> seat;

	cin.ignore(2, '\n');

	string s;	// 손님 대기열
	getline(cin, s);	// 대기열 입력받기
	string arr[999];	// 대기열 문자단위로 자르기
	int arrNum = 0;
	stringstream ss1(s);
	while (getline(ss1, arr[arrNum++], ' '));	// 기본적인 문자열받아 단어 자르기 구조

	// 처음 입력받은 문자들을 arr에 잘 저장했다.

	queue<char> Q;	// 밥먹는거 저장.
	int count = 0;
	int* table;
	table = new int[seat];	// 탁자 구현 테이블
	for (int i = 0; i < seat; i++) table[i] = '0';	// 초기화.

	for (int i = 0; i < arrNum; i++)
	{
		if (arr[i][0] >= 65 && arr[i][0] <= 90)	// 영문 알파벳 대문자라면
		{
			// 넣어야 한다, 단 꽉 차있다면 빠꾸칠 것.
			if (Q.size() < seat)
			{
				Q.push(arr[i][0]);
				tablePlus(arr[i][0], table, seat);// 테이블에 추가시킬 것. 왼쪽부터 탐색하면서.
			}
		}
		else if (arr[i][0] == '*')	// *이라면 뺄 것.
		{
			tableMinus(Q.front(), table, seat);	// 테이블에서 해당하는 문자 없앨 것.
			Q.pop();
		}
	}

	for (int i = 0; i < seat; i++)
	{
		switch (table[i])
		{
		case '0' : 
			cout << "# ";
			break;
		default : 
			cout << (char)table[i] << " ";
			break;
		}
	}

	return 0;
}

// 테이블에 추가시킨다. 가능여부는 미리 확인했다.
void tablePlus(char ch, int arr[], int seat)
{
	for (int i = 0; i < seat; i++)
	{
		if (arr[i] == '0')
		{
			arr[i] = ch;
			return;
		}
	}
	cout << "넣기오류." << endl;
	return;
}

// 테이블에서 뺀다. 이미 있는놈 빼라고 둔 것.
void tableMinus(char ch, int arr[], int seat)
{
	for (int i = 0; i < seat; i++)
	{
		if (arr[i] == ch)
		{
			arr[i] = '0';
			return;
		}
	}
	cout << "빼기오류." << endl;
	return;
}
