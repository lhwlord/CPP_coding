#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> floor_global;

// 엘베가 a층, b층에서 각각 멈출 때, 승객이 걷는 최소거리.(a와 b 사이에 있어야 한다.)
// 0층도 고려한다.
int walk(int a, int b)
{
	int sum = 0;
	//floor_global을 돌며, 1층, a층, b층으로부터의 절대값 최소를 반환.
	for (int i = 0; i < floor_global.size(); i++)
	{
		// 해당 범위 안에 들어가는 경우에만, 최소값을 대입한다.
		if (floor_global[i] > a && floor_global[i] <= b)
			sum += min(floor_global[i] - a, b - floor_global[i]);
	}
	return sum;
}

// 엘리베이터 최적화 문제.
// 전기요금을 절약하기 위해, 엘베 멈추는 회수를 최소화해야 한다.
// 가령, 13/14/15층에 내릴 사람이 각각 있다면, 14층에 한번 멈추면 바로 윗층과 아랫층으로 걸어갈 수 있으므로 한번만 멈추면 된다.
int main(void)
{
	// 몇명이 타고, 몇번 멈출 지 정하기
	int man, stop;
	scanf("%d %d", &man, &stop);

	// 몇명이 어디서 멈출지 넣기(오름차순 정렬되어있다 가정)
	vector<int> floor(man);
	for (int i = 0; i < man; i++) scanf("%d", &floor[i]);

	floor_global = floor;
	

	// DP테이블을 만든다 : 최대 몇층, 몇번. 1층에서 멈추는 경우도 넣는다.
	vector<vector<int>> table(floor[floor.size() - 1] + 1, vector<int>(stop + 1));

	// 추가로, 경로 추적을 위한 테이블도 만든다.
	vector<vector<int>> route = table;

	// 초기화 : 첫 열은 walk(0,inf)으로 지정한다. 행도 비슷하게 지정해둔다.
	for (int i = 0; i < table.size(); i++)
	{
		table[i][0] = walk(0, INT_MAX);
	}
	for (int i = 0; i < table[0].size(); i++)
	{
		table[0][i] = walk(0, INT_MAX);
	}

	// DP풀이 시작 : 멈추는 횟수를 1번 줄인 시점에서, 0~지금 층수까지 돌리면서 가중치를 구하고, 그 최소를 넣는다.
	for (int i = 1; i < table.size(); i++)
	{
		for (int j = 1; j < table[i].size(); j++)
		{
			int temp_min = 2147483647;
			for (int k = 0; k <= i; k++)	// 층수를 낮춰가며 검색.
			{
				int temp_min_candi = table[k][j-1] - walk(k, INT_MAX) + walk(k, i) + walk(i, INT_MAX);
				if (temp_min_candi > 0 && temp_min > temp_min_candi)
				{
					temp_min = temp_min_candi;
					route[i][j] = k;	// 최소로 진행하는 경우의 층 수를 저장한다.(부모)
				}
			}
			table[i][j] = temp_min;
		}
	}

	// 테이블 출력.
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
			cout << table[i][j] << ' ';
		cout << endl;
	}

	// 최종결과 출력 : 이건 최적해인데, 사람이 최소로 움직이는 값이다.
	cout << "최소로 움직이는 거리 : " << table[table.size() - 1][table[0].size() - 1] << endl;

	// 이제, 이 테이블의 가장 밑단으로부터 역추적을 시도한다. 실제로 어느 층에서 내려야 하는지 본다. 먼저, 해당하는 만큼 멈췄을 때 가장 가중치가 적은 쪽의 층 수를 확인한다.
	int min_floor = 0;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i][stop] < table[min_floor][stop]) // i번째 레벨까지의 가중치가 더 적다면
			min_floor = i;	// 가장 적은 가중치인 그 레벨에서 멈춰야 한다.
	}

	// 이제 역추적에 들어간다. 이전에 멈춘 곳은 stop에서 1 빠진 만큼 진행했을 때 멈춘 곳이므로, 이걸 route를 통해서 추적하면 된다.
	vector<int> track;
	int tempStop = stop;
	while (tempStop)
	{
		track.push_back(min_floor);
		min_floor = route[min_floor][tempStop--];
	}
	
	// 이제 출력하면 된다.
	reverse(track.begin(), track.end());
	for (auto i : track) cout << i << endl;


	return 0;
}