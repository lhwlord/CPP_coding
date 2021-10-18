#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 비토와 친척들.
// 비토는 모든 친척집과의 거리 총합이 가장 작은 곳에 집을 구하고 싶어한다.
// 입력 : 첫 줄은 테스트케이스 개수, 케이스 당 친척집 수/번지수. 번지수 중복가능
// 친척집 수는 500 이하, 번지수는 30000 이하 양수.
// 출력 : 모든 친척집까지의 거리 총합.

// 솔루션
// 애초에 입력받아다가 이걸 정렬하면 끝나는 문제였다. 중간값에 있으면 되기 때문.
// 중간값을 찾는다.
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int loop = 0; loop < testCase; loop++)
	{
		int houseNum;
		vector<int> adress;
		cin >> houseNum;
		for (int i = 0; i < houseNum; i++)
		{
			adress.push_back(0);
			cin >> adress[i];
		}

		 sort(&adress[0], &adress[adress.size() - 1] + 1);
		// sort(adress.begin(), adress.end());


		 int myHouse = adress[adress.size() / 2];

		 int result = 0;

		 for (int i = 0; i < adress.size(); i++)
			 result += myHouse - adress[i] > 0 ? myHouse - adress[i] : adress[i] - myHouse;

		 cout << result << endl;

	}
	return 0;
}