#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int N;
int mini = 2147483647;

// �� ���� ���
int calculate(vector<int>& team)
{
	int result = 0;
	// for�� �����鼭 �����.
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

// �� �׷����� ������.
void track(int level)
{
	if (level == N && teamA.size() == N / 2)
	{
		// A���� �� á����, �������� B������ ���� �� �� ���� ���
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
		// A���� �ϼ����ѳ�����. �ְų�, �ȳְų�
		teamA.push_back(level);
		track(level + 1);
		teamA.pop_back();
		track(level + 1);
	}

}

// ���� #14889 : ��ŸƮ�� ��ũ
// 1. ���� �� �׷����� ������
// 2. �� ���� ���� ��� : ������ ������ ��ҿ� ����(��, ��) �� ��, �� ���� ��ΰ� ���.
// 3. Ƣ����� �׷츶�� ���� �̰� ���.
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