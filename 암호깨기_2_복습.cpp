#include <iostream>
#include <string>

using namespace std;

bool findKey(string[100], int, char[123][2]);
void decodeAndPrint(string[100], int, char[123][2]);

// 첫 줄에는 양의 정수 1개 : 테스트케이스 개수
// 다음은 빈 줄, 케이스도 빈 줄로 구분
// 각 케이스는 암호화된 여러 줄
// 암호화된 내용은 소문자와 스페이스만으로 구성, 최대 80문자
// 입력텍스트 전체는 100줄로 제한
int main(void)
{
	int testCase;
	cin >> testCase;
	cin.ignore(2, NULL);	// 숫자 이후 엔터 2개 무시
	for (int i = 0; i < testCase; i++)	// 케이스마다 진행
	{
		string str[100];
		int strIndex = 0;
		char match[123][2] = { {0}, };	// 인덱스는 암호문, 내부 값을 복호문으로 가정한다.
		// 빈줄 입력 전까지 받아옴
		do
		{
			getline(cin, str[strIndex++]);
		} while (! str[strIndex - 1].empty());


		// 키 문장 찾아서 해독 시도. 찾으면 참, 없으면 복호화 실패로 간주하고 거짓 반환.
		if (! findKey(str, strIndex, match))
		{
			cout << "No solution.\n";
			continue;
		}

		// 무사히 넘어왔다면 매치된 표를 이용해 복호화와 동시에 출력.
		decodeAndPrint(str, strIndex, match);
	}
	return 0;
}

// str을 돌며 키문장에 매치할 수 있는지를 검사. 끝까지 매칭 성공시 참, 마지막까지 안나오면 거짓.
bool findKey(string str[100], int strIndex, char match[123][2])
{
	string lock = "the quick brown fox jumps over the lazy dog";
	// 하나씩 돌며 검사.
	for (int i = 0; i < strIndex; i++)
	{
		if (str[i].length() != lock.length()) continue;	// 문장 길이가 다르면 패스.

		for (int j = 0; j < lock.length(); j++)
		{
			if ((lock[j] == ' ') ^ (str[i][j] == ' '))	goto SKIP;// 한 곳이 공백이면 나머지도 그래야 한다. 이걸 만족하지 못하면(둘이 다르면) 바로 다음 문장으로 넘긴다.
			if (match[str[i][j]][1] == 1 && match[str[i][j]][0] != lock[j]) goto SKIP;	// 평문인덱스가 이미 차있고, 심지어 매치된 값이 지금 나온 값이 아니라면 이것도 바로 넘긴다.
			if (match[str[i][j]][1] == 0)	// 이러면 넣을 수 있다.
			{
				match[str[i][j]][0] = lock[j];
				match[str[i][j]][1] = 1;
			}
		}

		// 여기까지 왔다면 한 문장이 성공적으로 매치된 것이다.
		return true;
		// 이게 아니고 스킵으로 들어가는 경우라면 매치테이블을 비우고 재도전한다.
	SKIP : 
		for (int j = 0; j < 123; j++)
		{
			match[j][1] = 0;
		}
	}
	return false;
}

// 복호화와 동시에 출력.
void decodeAndPrint(string str[100], int strIndex, char match[123][2])
{
	for (int i = 0; i < strIndex; i++)
	{
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] == ' ') cout << ' ';
			else
			{
				cout << match[str[i][j]][0];
			}
		}
		cout << endl;
	}
}