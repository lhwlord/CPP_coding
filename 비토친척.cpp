#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 비토와 친척들.
// 비토는 모든 친척집과의 거리 총합이 가장 작은 곳에 집을 구하고 싶어한다.
// 입력 : 첫 줄은 테스트케이스 개수, 케이스 당 친척집 수/번지수. 번지수 중복가능
// 친척집 수는 500 이하, 번지수는 30000 이하 양수.
// 출력 : 모든 친척집까지의 거리 총합.

// 솔루션
// 배열에 번지수 넣고, 번지수 가장 차이나는 두 집을 for문으로 돌림
// 그 안의 각 i마다 다른 집과의 거리를 측정하고, 이걸로 최소값 찾기
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int loop = 0; loop < testCase; loop++)
	{
		int houseNum, max = 0, min = 0;
		vector<int> adress;
		cin >> houseNum;
		for (int i = 0; i < houseNum; i++)
		{
			adress.push_back(0);
			cin >> adress[i];
			if (i == 0)
			{
				max = min = adress[0];
			}
			else if (max < adress[i]) max = adress[i];
			else if (min > adress[i]) min = adress[i];
		}

	
		int minDistance = 0;

		for (int i = min; i <= max; i++)
		{
			int distance = 0;
			for (int j = 0; j < adress.size(); j++)
			{
				int temp = i - adress[j] < 0 ? adress[j] - i : i - adress[j];
				distance += temp;	// 이것이 i에 집을 놨을 때의 거리총합
			}
			// 최소 거리총합 구하기
			if (i == min) minDistance = distance;
			else if (minDistance > distance) minDistance = distance;
		}
		cout << minDistance << endl;
	}
	return 0;
}