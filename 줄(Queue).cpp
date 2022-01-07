#include <iostream>
#include <string>
#include <vector>
using namespace std;

int human, leftSee, rightSee;	// 가장 큰 키, 좌측 볼 수 있는 사람, 우측 볼 수 있는 사람. 재귀로 쓰이기엔 메모리가 아까우니 전역으로 지정.
int permCount = 0;	// 

// 순열을 만든다. 끝까지 도달했으면 결과 스트링을 이용해 비교한다.
void permutation(string grow, string left)
{
	if (left.length() == 0) // grow가 완성됐다는 뜻.
	{
		// 좌측부터 진행하며 좌측을 볼 수 있는 사람 수 세기
		int leftP = 1;
		int biggest = grow[0];
		for (int i = 0; i < grow.length(); i++)
		{
			if (biggest < grow[i])
			{
				biggest = grow[i];
				leftP++;
				if (grow[i] == human - 1) break;
			}
		}

		// 우측부터 진행하며 우측을 볼 수 있는 사람 수 세기
		int rightP = 1;
		biggest = grow[grow.length() - 1];
		for (int i = grow.length() - 1; i != 0; i--)
		{
			if (biggest < grow[i])
			{
				biggest = grow[i];
				rightP++;
				if (grow[i] == human - 1) break;
			}
		}

		if (leftSee == leftP && rightSee == rightP) permCount++;
	}
	else
	{
		for (int i = 0; i < left.size(); i++)
		{
			// 연산시간 줄이기 : 가장 큰 키를 가진 요소는 적어도 좌측과 우측 시야 안쪽에 들어와야 한다.
			 if (!((left[i] == human - 1) && ((grow.length() < leftSee - 1) || (grow.length() > human - rightSee))))
			{
				string tempS = left;
				permutation(grow + left[i], tempS.erase(i, 1));
			}
		}
	}
}


// 케이스 개수, 케이스 당 사람수, 좌측 볼 수 있는 사람, 우측 볼 수 있는 사람 입력.
// 좌/우를 해당하는 숫자만큼 볼 수 있는 조합을 출력.
/*
솔루션 : 재귀로 순열을 만들고, 센다.
단, 순열인 만큼 복잡도는 팩토리얼로 증가한다. 이는 너무 위험하므로, 중간중간 트릭을 이용해 연산수를 줄이도록 한다.
*/
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int caseNum = 0; caseNum < testCase; caseNum++)
	{
		scanf_s("%d %d %d", &human, &leftSee, &rightSee);
		string leftString = "";
		for (int i = 0; i < human; i++) leftString += (char)(i + '0');
		permutation("", leftString);
		cout << permCount << endl;
		permCount = 0;
	}
	return 0;
}