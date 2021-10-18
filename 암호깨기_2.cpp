/*
암호문 매칭테이블을 또 만들어야 한다.

심지어 문장들 중에서 the quick brown 뭐시기로 암호화된 문장같은걸 직접 찾아다가 매칭테이블에 올려놓는 것까지 구현해야 한다.

방법이 있다. 일단 먼저 각 문장마다 퀵브라운 문장과의 매치를 시도한다. 전부 매치되지 않는다면 실패고, 매칭되는 문장이 있다면 그거 갖다가 매핑하면 된다. 그리고 그걸 이용해서 해당 케이스의 다른 문장들도 전부 복호화시키면 끝.


vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq
*/

#include <iostream>
#include <string>

using namespace std;


bool match(string, int[123][2]);
void map_print(string[], int, int[123][2]);

// 테스트 케이스 개수를 입력받는다. 케이스 개수와 각 요소 입력 사이에는 엔터.(처리 딱히 안해도 됨)
// 각 테스트 케이스마다 여러 줄의 문자열이 입력될 수 있다. 테스트 케이스 간의 구분은 엔터.
// 각 테스트 케이스에 들어가는 여러 문자열 중 한 줄은 무조건 the quick brown fox jumps over the lazy dog라는, 알파벳 26자가 전부 들어가는 구문이다. 이 키 구문을 이용해서 해당 테스트 케이스를 복호화할 것.
// 만약 저 구문이 없다던가 하는 이유로 복호화에 실패했다면, No solution. 이라는 문구를 출력할 것.
int main(void)
{
	int testCase;
	cin >> testCase;
	cin.get();
	cin.get();
	for (int test = 0; test < testCase; test++)
	{
		int arr[123][2] = {{0,},};	// 인덱스와 매치되는 1번행, 그리고 매치됐는지 확인하는 배열
		string str[100];
		int count = 0;
		
		// 엔터입력 하나만 있지 않는 한 문장을 계속 읽어들이기
		
		while (true)
		{
			char c;
			cin.get(c);
			if (c != '\n')
			{
				getline(cin, str[count]);
				//cin >> str[count];
				str[count++].insert(0, 1, c);
			}
			else break;
		}

		/*
		// 배열에 잘 들어갔나 확인
		for (int i = 0; i < count; i++)
		{
			cout << str[i] << endl;
		}*/


		bool isMatched = false;
		// 각 문장마다 퀵브라운과의 매치 시도.
		for (int i = 0; i < count; i++)
		{
			if (match(str[i], arr)) isMatched = true;
		}
		if (!isMatched)
		{
			cout << "No solution.\n";
		}
		else
		{
			map_print(str, count, arr);
		}
	}

	return 0;
}

// 퀵브라운과 비교해서 맵핑이 되는지 확인.
bool match(string s, int arr[123][2])
{
	string quick = "the quick brown fox jumps over the lazy dog";
	if (s.length() != quick.length()) return false;	// 길이가 다르면 거짓 반환


	for (int i = 0; i < s.length(); i++)
	{
		// 공백 위치가 다르다면 거짓 반환
		if ((s[i] == ' ' && quick[i] != ' ') || (s[i] != ' ' && quick[i] == ' ')) return false;

		// 해당 문자가 아직 매치되지 않았다면 매치하고 맵 수정 시도. 도중에 맵핑이 빠꾸나면 맵을 전부 초기화하고 거짓 반환
		if (arr[s[i]][1] == 0 || arr[s[i]][0] == quick[i])
		{
			arr[s[i]][0] = quick[i];
			arr[s[i]][1] = 1;
		}
		else
		{
			for (int j = 0; j < 123; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					arr[j][k] = 0;
				}
			}
			return false;
		}
	}
	// for문을 전부 돌았다는 것은 성공적으로 매칭했다는 것이므로 참 반환.
	return true;
}

// 매핑 완료. 이걸로 전부 바꿔다가 출력하면 된다.
void map_print(string str[], int count, int arr[123][2])
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] == ' ') cout << ' ';
			else cout << (char)arr[str[i][j]][0];
		}
		cout << endl;
	}
}
