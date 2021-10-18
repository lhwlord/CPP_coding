#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

typedef struct {
	char set[2];
	int combo;
}pattern;

void store(pattern*, string, int*);
void searchStore(pattern*, char, char, int*);
bool isAlpha(char);
void initPattern(pattern*);
void bigTrace(pattern*, int*);
void sortAndPrint(pattern*, int);
bool bigger(pattern, pattern);
// 알파벳 두글자로 이뤄진 패턴 찾기.
// 가장 많이 등장하는 패턴 순서대로 표기한다.
// 최대 패턴이 동일하다면 아스키 순서대로 정렬해서 출력한다.
// 2회 이상 등장하는 패턴이 하나도 없으면 Not present 출력.
int main()
{
	string line;

	//엔터 전까지 입력받아 처리
	while (getline(cin, line))
	{
		pattern patArr[MAX / 2];
		int count = 1;
		//초기화.
		for (int i = 0; i < MAX / 2; i++)
		{
			initPattern(&patArr[i]);
		}

		//2개씩 끊어서 패턴배열에 저장.
		//단 넣을때마다 비교하면서 같으면 콤보를 올릴 것.
		//또한, 끊었는데 공백이 포함되었다면 빠꾸칠 것.
		store(patArr, line, &count);

		//패턴배열에 중복포함하여 전부 넣었다.
		//2개 이상인 패턴을 찾아 출력하되, 빈도가 같으면 아스키 순서대로 정렬해야 한다.
		//방법이 있다 : 독보적으로 1개인 빈도는 바로 출력하고, 2개 이상의 빈도들은 따로 배열을 만들어 정렬 후에 내보낸다.

		//잘 돌아간다. 이제 빈도에 따라, 큰 빈도부터 따로 배열에 저장하고, 정렬 후 출력하도록 하자.
		bigTrace(patArr, &count); //큰 수 찾아서 순서대로 정렬/출력함수 실행하는거
	}
	return 0;
}

void store(pattern* arr, string line, int* count)
{
	for (int i = 1; i < line.length(); i++)
	{
		if (!isAlpha(line[i]) || (!isAlpha(line[i - 1]))) continue;

		//현재 값과 이전 값을 통으로 묶어 패턴배열에 있나 확인하고 넣기
		searchStore(arr, line[i - 1], line[i], count);
	}
	return;
}

void searchStore(pattern* arr, char a, char b, int* count)
{
	for (int i = 0; i < *count; i++)
	{
		if ((arr[i].set[0] == a) && (arr[i].set[1] == b))
		{
			arr[i].combo++;
			return;
		}
	}
	//for루프를 리턴 없이 빠져나왔다는 것은 새로운 조합이라는 것이므로 카운트 인덱스에 저장 후 늘린다.
	arr[*count].set[0] = a;
	arr[*count].set[1] = b;
	arr[*count].combo++;
	(*count)++;
	return;
}

bool isAlpha(char a)
{
	if (((a >= 65) && (a <= 90)) || ((a >= 97) && (a <= 122))) return true;

	return false;
}

void initPattern(pattern* P)
{
	P->combo = 0;
}

//큰 빈도만 저장하고, 그렇게 저장된 배열을 정렬해서 출력하는 프로그램.
void bigTrace(pattern* P, int* count)
{
	pattern temp[MAX / 2];
	int tempCount = 0;
	int big = 0;

	//가장 큰놈 찾기
	for (int i = 0; i < *count; i++)
	{
		if (big < P[i].combo) big = P[i].combo;
	}


	//돌면서 큰거랑 수가 일치하면 임시배열에 집어넣기
	for (int i = 0; i < *count; i++)
	{
		if (big == P[i].combo)
		{
			temp[tempCount++] = P[i]; //주소 옮기는게 아니라 복사임
		}
	}

	if (big < 2)
	{
		cout << "Not present" << endl;
		return;
	}
	sortAndPrint(temp, tempCount);
}

//이 안에는 같은 빈도의 패턴들만 있다.
//없으면 출력마저 건너뛰며 리턴하고, 하나뿐이라면 정렬을 건너뛰고, 2개 이상이면 앞부터 비교해가며 정렬하자.
//정렬이 완료되면 순차적으로 프린트하면 된다!
void sortAndPrint(pattern* temp, int count)
{
	if (count == 0) return;
	if (count == 1);
	else
	{
		//정렬.
		for (int i = 0; i < count - 1; i++)
		{
			if (bigger(temp[i], temp[i + 1]))
			{
				pattern tmp = temp[i];
				temp[i] = temp[i + 1];
				temp[i + 1] = tmp;
				i = 0;
			}
		}
	}

	//출력.
	for (int i = count - 1; i >= 0; i--)
	{
		cout << temp[i].set[0] << temp[i].set[1] << ' ';
	}
	cout << endl;

}

//두 패턴 중 누가 더 큰지를 판단함.
//구조상 같은 패턴은 나올 수 없음.
bool bigger(pattern a, pattern b)
{
	//첫문자부터 검색
	if (a.set[0] < b.set[0]) return true;
	else if (a.set[0] > b.set[0]) return false;
	else
	{
		return a.set[1] < b.set[1] ? true : false;
	}
}