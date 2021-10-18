#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool match(string[], string, int[], bool[], int);

int main(void)
{
	int dicNum;
	string dic[1000];
	string s;	// 암호문 입력받기
	
	cin >> dicNum;
	for (int i = 0; i < dicNum; i++)
	{
		cin >> dic[i];
	}
	cin.clear();	// 버퍼 비우기
	while (getline(cin, s))
	{
		int arrNum = 0;	// 암호문배열 개수 삽입용
		stringstream ss1(s);	// 자르기용
		int matchArr[200] = { 0, };
		bool isMatched[200] = { false, };
		string arr[80];	// 입력받은 암호문을 단어단위로 자르기

		while (getline(ss1, arr[arrNum++], ' '));	// 다 잘라서 넣는다.

		for (int i = 0; i < arrNum; i++)
		{
			match(dic, arr[i], matchArr, isMatched, dicNum);
		}
		cout << endl;
	}

	return 0;
}

// 사전과 암호단어, 매치정보를 이용해 매치여부 판별 및 신규 매치 생성.
bool match(string dic[], string word, int matchArr[], bool isMatched[], int dicNum)
{
	
	for (int i = 0; i < dicNum; i++) // 사전단어와 하나씩 매칭하는 중.
	{
		char c;
		if (word.length() == dic[i].length())	// 단어길이 같은지.
		{
			// 단어길이가 동일하므로, 이제 문자 단위로 매칭을 시도한다. 단어의 끝까지. 이러다가 하나라도 매칭이 좌절되면 걍 넘긴다.
			bool Matched = true;
			for (int j = 0; j < word.length() && Matched; j++)
			{
				if (matchArr[word[j]] == 0)	// 값이 없다면..
				{
					if (isMatched[dic[i][j]] == true)	// 암호문의 단어는 매칭하지 않지만, 목표단어가 매칭되었는가?
						Matched = false;	// 사전단어는 이미 매칭되었다. 다음 단어로.
					else
					{
						// 암호문 단어가 매칭하지 않으면서, 목표 사전단어 또한 매칭되지 않았다! 새로 집어넣을 기회이다.
						matchArr[word[j]] = dic[i][j];
						isMatched[dic[i][j]] = true;
					}
				}
				else
				{
					if (matchArr[word[j]] == dic[i][j])	// 값이 있지만 매칭이 된다면
						;	// 그대로 진행.
					else
						Matched = false;	// 있는 값이 다르다면 매치에 실패. 다음 단어로.
				}
			}
			if (Matched)// true로 남았다는 것은 해당 단어가 완벽히 매칭되었다는 뜻. 여기서 끊고, 단어 출력하고 반환한다.
			{
				cout << dic[i] << ' ';
				return true;
			}
		}
	}
	// 내부에서 해결이 안됐다면 단어매치가 실패한 것이므로
	for (int i = 0; i < word.length(); i++)
	{
		cout << '*';
	}
	cout << ' ';
	return false;
}
