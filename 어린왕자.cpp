#include <iostream>
#include <vector>

using namespace std;

// x,y로 받은 해당 위치가 성계의 경계 안에 포함되는가?
// 거리를 제대로 계산해도 되지만, 좌표거리 구하는 공식 상 제곱 상태로 비교해도 된다.
// 리마인드 : 성계배열 0번 : x, 1번 : y, 2번 : 반지름
bool checkInside(vector<int> star, int x, int y)
{
	int starRadius = star[2] * star[2];
	int distance = (abs(star[0] - x) * abs(star[0] - x)) + (abs(star[1] - y) * abs(star[1] - y));

	return starRadius > distance;	// 문제 조건 상 겹치는 경우는 나오지 않는다.
}


// 출발지부터 목적지까지 가는 경로 중 성계 경계를 최소로 지나는 경로의 경계 통과 수 구하기
/*
* 솔루션 : 시작과 끝에 대해 각각 성계 중앙과의 거리와 성계 반지름의 거리 계산, 해당 점이 성계 경계 안에 있으면 카운트 1 증가.
* 단, 한 성계 안에 시작/끝점 모두 있으면 카운트 안함.
*/
int main(void)
{
	int caseNum;
	cin >> caseNum;
	for (int case_i = 0; case_i < caseNum; case_i++)
	{
		int start_x, start_y, end_x, end_y, starNum;
		cin >> start_x >> start_y >> end_x >> end_y;
		cin >> starNum;
		vector<vector<int>> starArr;	// 성계 정보 저장
		
		// 각 성계 위치와 반지름 넣기
		for (int star_i = 0; star_i < starNum; star_i++)
		{
			int temp_x, temp_y, temp_radius;
			cin >> temp_x >> temp_y >> temp_radius;
			vector<int> tempArr;
			tempArr.push_back(temp_x);
			tempArr.push_back(temp_y);
			tempArr.push_back(temp_radius);
			starArr.push_back(tempArr);
		}

		// 성계 단위로, 시작/끝점이 안에 있나 확인하고 상황에 맞게 카운트 증가
		int count = 0;
		for (int i = 0; i < starNum; i++)
		{
			if (checkInside(starArr[i], start_x, start_y) != checkInside(starArr[i], end_x, end_y))
				count++;
		}
		cout << count << endl;
	}
	return 0;
}