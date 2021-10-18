/*
줄 수가 달라지더라도 그 줄에 문자만 들어있다면 프레젠테이션 에러로 들어가야 한다. 물론 이 처리는 전체 문자열을 받아 처리하는 과정에서 알아서 진행되도록 해야 할 것.

-문자열들을 전체 다 입력받는다.
-지정된 만큼 돌면서 하나하나 대입했을 때 전부 맞다면 정답.
-그게 아니라면 출력오류인지 오답인지를 판정해야 한다.(문자던 숫자던 간에 뭐가 잘못돼서 나왔기 때문)
-문자열들에서 숫자만을 따로 빼다가 다른 배열에 1의 단위로 집어넣는다. 여기에는 isdigit()을 쓰는 편이 나아보인다.
-그걸 비교해서, 같으면 출력오류, 다르면 오답.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 선입력값이 0이 아니면 정답을 입력받고, 이후 후입력값을 통해 제출답을 입력받는다.
// 완벽히 일치하면 해당 케이스 통과. Run #() : Accepted
// 문자열에서 숫자 조합은 일치하나(순서와 개수가 일치하면 그 사이에 문자가 끼어도 무상관) 문자가 하나 이상 불일치하면 Run #() : Presentation Error
// 위의 두 판정에 해당하지 않으면 Run #() : Wrong Answer
int main(void)
{
	int input, output;
	int count = 1;	// Run에 들어갈 시도넘버링
	while (true)
	{
		string inS[100];
		string outS[100];
		cin >> input;
		cin.get();
		if (input == 0) break;
		// 문자열 전체 다 입력받기
		for (int i = 0; i < input; i++)
		{
			getline(cin, inS[i]);
		}
		cin >> output;
		cin.get();
		for (int i = 0; i < output; i++)
		{
			getline(cin, outS[i]);
		}

		// 같은지(정답인지) 부터 확인
		bool isSame = true;
		if (input == output)
		{
			for (int i = 0; i < input; i++)
			{
				if (inS[i] != outS[i]) isSame = false;
			}
		}
		else
			isSame = false;
		if (isSame)
		{
			cout << "Run #" << count++ << ": Accepted\n";
			continue;
		}

		//같지 않아서 여기까지 왔다. 이제 출력오류인지, 오답인지를 확인해야 한다.
		vector<int> inDigit;
		vector<int> outDigit;
		int inDCount = 0, outDCount = 0;
		for (int i = 0; i < input; i++)
		{
			for (int j = 0; j < inS[i].length(); j++)
				if (isdigit(inS[i][j])) inDigit.push_back(inS[i][j]);
		}
		for (int i = 0; i < output; i++)
		{
			for (int j = 0; j < outS[i].length(); j++)
				if (isdigit(outS[i][j])) outDigit.push_back(outS[i][j]);
		}

		// 숫자만 잘 추출해서 벡터에 집어넣었다. 이걸 차례로 비교하는 일만 남았다.
		bool isErr = true;
		if (inDigit.size() != outDigit.size()) isErr = false;
		else
		{
			for (int i = 0; i < inDigit.size(); i++)
			{
				if (inDigit[i] != outDigit[i]) isErr = false;
			}
		}

		// 이제 isErr의 상태에 따라 출력을 달리하면 된다.
		if (isErr)
			cout << "Run #" << count++ << ": Presention Error\n";
		else
			cout << "Run #" << count++ << ": Wrong Answer\n";
	}
	return 0;
}