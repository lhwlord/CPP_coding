#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 계산 편하게 하기용 절대값.
int abs(int a)
{
	return a < 0 ? -a : a;
}

// 케이스 개수, 이후 빈줄, 각 케이스 사이도 빈줄.
// 케이스당 사람수, 사람수만큼의 체중들.
// 양팀의 차이를 1명 이하로 두면서 무게합이 최소로 되는 경우의 양팀 무게 합계를 출력
/*
-사람수가 짝수면 사람수가 같도록, 홀수면 1명 차이나도록 조합 구성
-양팀의 큰 무게들부터 비교해나가면서 현재보다 좋은 결과가 나오는 경우만 교환
-누군가의 몸무게가 몸무게 합보다 작게 나가는 문제 때문에 결과가 틀어지면... 알고리즘을 갈아엎자.
-알고리즘 자체는 점화식이 아니므로 시간이 더 걸릴수도 있다.
-사실 약간 야매로 한 감이 없지않아 있다. 나중에 허점이 보이면 수정할 수 있도록.
*/
int main(void)
{
	//srand(time(NULL));	// 랜덤값-1. 추후 제거할 것


	int testCase;
	cin >> testCase;
	cin.get();	// 엔터넘기기
	while(testCase--)
	{
		int human;
		scanf("%d", &human);
		//int* weight = new int[human];
		vector<int> weight(human);
		for (int hNum = 0; hNum < human; hNum++)
		{
			//scanf_s("%d", weight+hNum); // 이거나 밑의 것 둘 중 하나 사용.
			scanf("%d", &weight[hNum]);	// 배열은 포인터 형식이지만, 그 안의 인덱스를 지칭하는 경우 값을 참조하기 때문에 주소연산자를 붙여야 한다.

			//weight[hNum] = rand() % 450 + 1;	// 랜덤값-2. 추후 제거할 것(윗줄 명령어 활성화)
		}


		int gap = 0;	// 나중에 처리할 갭을 미리 호출시켜 계산

		// 팀원 1차적으로 구성하기
		//int * teamA = new int[human - (human / 2)];
		//int * teamB = new int[human / 2];
		vector<int> teamA(human - (human / 2));
		vector<int> teamB(human / 2);
		int aIndex = 0, bIndex = 0;
		for (int i = 0; i < human; i++)
		{
			if (i % 2 == 0)
			{
				teamA[aIndex++] = weight[i];
				gap += weight[i];
			}
			else
			{
				teamB[bIndex++] = weight[i];
				gap -= weight[i];
			}
		}


		/*
		// 랜덤값-3. 추후 제거할 것
		int temp_a = 0, temp_b = 0;
		cout << "A팀 출력.\n";
		for (int i = 0; i < _msize(teamA) / sizeof(int); i++)
		{
			cout << i + 1 << "번 무게 : " << teamA[i] << endl;
			temp_a += teamA[i];
		}
		cout << endl << "B팀 출력.\n";
		for (int i = 0; i < _msize(teamB) / sizeof(int); i++)
		{
			cout << i + 1 << "번 무게 : " << teamB[i] << endl;
			temp_b += teamB[i];
		}
		cout << temp_a << ' ' << temp_b << endl;
		*/


		// 지옥의 n^2 루프. 교환이 이득인 경우에만 돌리고, 그러고 나서 처음으로 돌리기.
		for (int i = 0; i < teamA.size(); i++)
		{
			for (int j = 0; j < teamB.size(); j++)
			{
				
				if (abs(gap) > abs(gap - 2 * (teamA[i] - teamB[j])))
				{
					gap = gap - 2 * (teamA[i] - teamB[j]);
					int temp = teamA[i];
					teamA[i] = teamB[j];
					teamB[j] = temp;
					i = 0;
					j = 0;
				}
			}
		}


		/*
		// 랜덤값-4. 추후 제거할 것
		cout << "\n\n\n배분결과.\n\nA팀 출력.\n";
		for (int i = 0; i < _msize(teamA) / sizeof(int); i++)
		{
			cout << i + 1 << "번 무게 : " << teamA[i] << endl;
		}
		cout << endl << "B팀 출력.\n";
		for (int i = 0; i < _msize(teamB) / sizeof(int); i++)
		{
			cout << i + 1 << "번 무게 : " << teamB[i] << endl;
		}
		*/
		

		// 루프를 탈출했다 == 양팀의 무게분배가 적당히 이뤄졌다, 고로 양팀 무게 합 구해서 출력
		int aSum = 0, bSum = 0;
		for (int i = 0; i < teamA.size(); i++)
		{
			cout << teamA[i] << ' ';
			aSum += teamA[i];
		}
		cout << endl;
		for (int i = 0; i < teamB.size(); i++)
		{
			cout << teamB[i] << ' ';
			bSum += teamB[i];
		}
		cout << endl;

		

		if(aSum < bSum) cout << aSum << ' ' << bSum << endl << endl;
		else cout << bSum << ' ' << aSum << endl << endl;


		cin.get();	//엔터넘기기
	}
	return 0;
}