#include <iostream>
#include <string>

using namespace std;

// 키보드에서 양손을 오른쪽으로 이동시켜 타이핑했다 가정하고 문제를 푼다.
// 특성상 가장 왼쪽의 Q, A, Z, `와 비문자들은 칠 수 없다.
// 문자열이 입력됐을 때 이를 왼쪽으로 한 칸 이동시킨 출력을 표시.
int main(void)
{
	string line;

	string table = " `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	// 1 14 27 38번째 인덱스는 입력으로 주어지면 안되는 값이다. 예외처리 할 것
	
	while (getline(cin, line))
	{
		string result = "";
		int index;
		for (int i = 0; i < line.length(); i++)
		{
			index = table.find(line[i]);
			if (index == -1 || index == 1 || index == 14 || index == 27 || index == 38)
			{
				cout << "유효하지 않은 값이 들어갔습니다 : " << i << ", " << line[i] << endl;
				break;
			}
			else	// 일치하는 문자를 발견했고, 나오면 안되는 문자도 아니라면 대입
			{
				if (line[i] == ' ') result += table[index];
				else result += table[index - 1];
			}
		}
		cout << result << endl;
	}

	return 0;
}