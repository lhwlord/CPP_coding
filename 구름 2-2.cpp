#include <iostream>
#include <string>
#include <string.h>

using namespace std;

typedef struct
{
	char c;
	int num;
} tier;

int main();

void mytier(tier*, char*);
void initTier(tier*);
void tierCmp(tier*, tier*);

// A~Z까지 있는 카드뭉치. 즉 26*4개 카드뭉치. 이중에서 톰과 제리가 각각 5장씩 뽑는다.
// 포카드 : 같은거 4장, 트리플 : 같은거 3장, 페어 : 같은거 2장.
// 같은게 많을수록 높고, 같은 등급이면 뽑은카드 숫자가 후순위(Z에 가까울수록) 높다.
// 자신이 가진 5장 중 높은 등급으로 겨루며, 간혹 서로 같은 페어라면 무승부이다.
// 톰과 제리 순서대로 두 사람의 패가 주어질때 누가 승자인지 출력할 것. 무승부면 드로.
int main()

{
	//두 쌍의 배열을 입력받을 것.
	string line;

	//입력받아 분리하는 단계까지 여기에 작성
	while (getline(cin, line))
	{
		tier aT, bT;
		initTier(&aT);
		initTier(&bT);
		char* a, *b;
		a = strtok_s((char*)line.c_str(), " ", &b);

		//자신의 최대 등급을 찾아서 설정하는 함수
		mytier(&aT, a);
		mytier(&bT, b);

		//비교해서 누가 우세한지 출력하는 함수. 내부에서 출력까지 된다.
		tierCmp(&aT, &bT);
	}

	return 0;
}

void mytier(tier* T, char* a)
{
	int arr[100] = { 0, };//알파벳 대문자는 아스키로 65~90
	int maxCombo = 0;
	for (int i = 0; i < 5; i++)
	{
		arr[a[i]]++;
	}
	//최대매치 찾기. 상승탐색하면서 2 이상이고 지정 최대수치 이상이면 그걸로 갈아끼우기. 만약 2를 넘는 매치가 없다면 초기값인 0이 그대로 있을 것이다.
	for (int i = 65; i < 91; i++)
	{
		if ((arr[i] >= maxCombo) && arr[i] >= 2)
		{
			T->c = (char)i;
			T->num = arr[i];
		}
	}
	return;
}

void initTier(tier* T)
{
	T->c = 0;
	T->num = 0;
}

// 두 등급을 비교한다.
// 먼저 콤보수를 비교하고, 같으면 캐릭터를 비교한다. 이거까지 같으면 드로우.
void tierCmp(tier* a, tier* b)
{
	int result = 0;

	if (a->num > b->num)
		result = 1;
	else if (a->num < b->num)
		result = 2;
	else	// 둘이 같은 경우
	{
		if (a->c > b->c)
			result = 1;
		else if (a->c < b->c)
			result = 2;
		// 마지막까지 전부 같으면 드로우.
	}

	switch (result)
	{
	case 0 : 
		cout << "Draw" << endl;
		break;
	case 1 : 
		cout << "Tom" << endl;
		break;
	case 2 : 
		cout << "Jerry" << endl;
		break;
	default : 
		cout << "이건 나올수가 없음" << endl;
		break;
	}

	return;
}
