#include <iostream>
#include <string>

using namespace std;

char matchTable[8];	// 매치테이블. 바깥에서도 접근 가능하게 전역변수화.
bool matched = false;	// 하나라도 매치되었다면 true.
string target;	// 목적 스트링.

// 주어진 크기만큼, 가능한 이진배열을 전부 만든다.
// 전부 만들어졌으면 각각에 대해 검사하는 코드 추가.
void makeBinaryAndCheck(int num, string s)
{
	if (!matched)	// 이미 매치됐으면 이거 할 필요 없다.
	{
		if (num == 0)	// 끝까지 가서 사례 하나를 만들었으므로, 이에 대해 테이블 적용결과를 체크.
		{
			string result = "";
			for (int i = 0; i < s.length(); i++)
			{
				char left, right;
				int temp;
				// 양끝단인 경우 따로 처리.
				if (i == 0)
				{
					left = s[s.length() - 1];
					right = s[1];
				}
				else if (i == s.length() - 1)
				{
					left = s[i - 1];
					right = s[0];
				}
				else
				{
					left = s[i - 1];
					right = s[i + 1];
				}
				temp = (left - '0') * 4 + (s[i] - '0') * 2 + (right - '0');
				result += matchTable[temp];
			}
			if (target == result)	// 둘이 같다면
			{
				matched = true;
			}
		}
		else
		{
			makeBinaryAndCheck(num - 1, s + '0');
			makeBinaryAndCheck(num - 1, s + '1');
		}
	}
}

// 이진테이블(10진수로 먼저 주어짐), 셀 개수, 원하는 상태 입력. 종료구문 없음
// 어느 초기상태이더라도 이진테이블의 규칙에 의해 원하는 상태가 나오는지 계산.
/*
솔루션 : 일단 이진벡터 만들어다가 가능한 모든 상태를 실험하고, 하나라도 가능하다고 뜨는 경우 REACHABLE. 다 돌았는데 안뜨면 GARDEN OF EDEN.
*/
int main(void)
{
	// gets, scanf_s가 더 빠르다고 하니 그걸 써서 구현하도록 하자.
	int bin, num;
	char c[33];
	char temp;

	
	// 3가지 값들 계속 입력받기
	while (scanf_s("%d %d %s", &bin, &num, c, 33) != EOF)	// 한줄단위 입력이다. 여러 변수 입력받는 입장에선 이게 더 편할수도 있다. 한줄을 parsing하는 것보다 더 낫다.
		// ***** scanf_s 안에 문자열 등의 크기를 규격 외로 이상하게 설정하지 말 것!!
	{
		// bin을 새 배열에 이진수 코드로 집어넣는다.
		for (int i = 7; i != -1; i--)
		{
			matchTable[i] = bin % 2 + '0';
			bin >>= 1;
		}
		c[32] = '\0';	// 이거 없으면 컴파일러가 불안하다고 경고보낸다.
		target = c;

		// 재귀로 하나씩 뽑기. 검사는 재귀 안에서 시행
		makeBinaryAndCheck(num, "");

		if (matched) cout << "가능함!\n";
		else cout << "에덴동산마냥 못봄!\n";
		matched = false;
	}
	return 0;
}