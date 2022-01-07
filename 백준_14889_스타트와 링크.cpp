#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int N;
int mini = 2147483647;

// 팀 점수 계산
int calculate(vector<int>& team)
{
	int result = 0;
	// for문 돌리면서 만든다.
	for (int i = 0; i < team.size(); i++)
	{
		for (int j = 0; j < team.size(); j++)
		{
			if (i != j) result += arr[team[i]][team[j]];
		}
	}

	return result;
}

vector<int> teamA;

// 두 그룹으로 나눈다.
void track(int level)
{
	if (level == N && teamA.size() == N / 2)
	{
		// A팀이 꽉 찼으면, 나머지는 B팀으로 배정 후 팀 점수 계산
		vector<int> teamB;
		vector<bool> table(N, true);
		for (int i = 0; i < N / 2; i++)
			table[teamA[i]] = false;
		for (int i = 0; i < N; i++)
		{
			if (table[i])teamB.push_back(i);
		}

		mini = min(mini, abs(calculate(teamA) - calculate(teamB)));
		return;
	}
	else if (level == N || teamA.size() == N / 2) return;
	else
	{
		// A팀을 완성시켜나간다. 넣거나, 안넣거나
		teamA.push_back(level);
		track(level + 1);
		teamA.pop_back();
		track(level + 1);
	}

}

// 백준 #14889 : 스타트와 링크
// 1. 팀을 두 그룹으로 나눈다
// 2. 각 팀의 점수 계산 : 개인이 나머지 요소에 대해(나, 너) 의 합, 그 합을 모두가 계산.
// 3. 튀어나오는 그룹마다 전부 이걸 계산.
int main(void)
{
	cin >> N;
	arr = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		scanf("%d", &arr[i][j]);
	
	track(0);

	cout << mini;

	return 0;
}