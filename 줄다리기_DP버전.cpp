#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 줄다리기 문제를 DP로 해결한다.
// 근데 기존꺼에 비해 시간복잡도가 더 안좋다. 되긴 하지만, 여튼.
int main(void)
{
	int T;
	scanf("%d", &T);
	cin.get();
	while (T--)
	{
		int num, total = 0;
		scanf("%d", &num);
		
//		// 랜덤구문. 삭제할 것
//		srand(time(NULL));
//		num = 100;

		vector<int> weight(num);
		
		for (int i = 0; i < num; i++)
		{
			scanf("%d", &weight[i]);
			total += weight[i];
		}
		

//		// 랜덤구문. 삭제할 것
/*		for (int i = 0; i < num; i++)
		{
			weight[i] = rand() % 450;
			cout << weight[i] << ' ';
			total += weight[i];
		}cout << endl;
*/

		

		// 무게 총합만큼의 벡터 생성. 나중에 n만큼 돌면서 이 벡터를 수정할 것이다.
		vector<vector<int>> arr(total + 1, vector<int>(0));

		// 결과 무게를 저장하는 벡터. num / 2 크기만큼 찼으면 여기에 넣고, 이것만 비교하면 된다.
		vector<int> ans;

		// 벡터 돌면서 적당한 값 넣기
		for (int i = 0; i < num; i++)	// 각 원소 당
		{
			for (int j = 0; j < total + 1; j++)	// arr을 돌면서
			{
				for (int k = 0; k < arr[j].size(); j++)	// 내부 j가 가진 원소개수만큼(없으면 자동스킵)
				{
					// 개수가 충분하지 않은 경우에 계속해서 올려치기 시도.
					if (arr[j][k] + 1 < num / 2)
					{
						arr[j + weight[i]].push_back(arr[j][k] + 1);
					}
					else if (arr[j][k] + 1 == num / 2)	// 원하는 만큼 채웠으면 안넣고 바로 빠꾸
						ans.push_back(j + weight[i]);
					else // 이건 나오면 안된다.
						cout << "에러.\n";
				}
			}
			// 이와는 별개로 자기 자신도 배열에 추가
			if (num / 2 == 1)
			{
				ans.push_back(weight[i]);
			}
			else arr[weight[i]].push_back(1);
		}

		// 결과벡터 돌면서 가장 작은 차이나는 값 찾기
		int smaller = 0;
		for (int temp : ans)
		{
			int temp2 = total - temp;
			if (abs(temp2 - temp) < total - smaller - smaller)
			{
				temp2 = temp2 < temp ? temp2 : temp;
				smaller = temp2;
			}
		}
		printf("%d %d\n\n", smaller, total - smaller);
		cin.get();
	}
	return 0;
}