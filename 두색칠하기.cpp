#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 그래프와 색깔표를 주고, 재귀하면서 들어간다.
bool findPath(vector<vector<int>>& arr, vector<int>& color, int cur, int prev)
{
	bool check = true;
	for (int i = 0; i < arr[cur].size(); i++)	// 배열의 해당 노드의 연결선 개수만큼 돌면서
	{
		// 값이 있는지, 있으면 자신과 값이 같은지부터 검사
		if (color[arr[cur][i]] > 0)
		{
			if (color[arr[cur][i]] == color[cur]) return false;
		}
		else
		{
			color[arr[cur][i]] = color[cur] == 1 ? 2 : 1;
			if (!findPath(arr, color, arr[cur][i], cur)) check = false;
		}
	}

	return check;
}



// 그래프가 있을 때, 연결된 선으로 매칭되는 두 노드의 색이 다르게 설정 가능한지 보기.

int main(void)
{
	int n;	// 노드 개수
	while (true)
	{
		scanf("%d", &n);
		if (n == 0) break;
		else // 여기부터가 메인 동작부.
		{
			int l;
			scanf("%d", &l);	// 연결선 개수
			vector<vector<int>> arr(n);	// 배열간의 연결관계 파악용
			vector<int> color(n, 0);	// 해당 노드가 무슨 색으로 칠해져있는가? 색없음 : 0
			while (l--)
			{
				int a, b;
				scanf("%d %d", &a, &b);
				arr[a].push_back(b);
				arr[b].push_back(a);
			}
			color[0] = 1;	// 초기화
			if (findPath(arr, color, 0, -1))// 0번 노드에서 시작하기. 이전값은 없으니 -1로 지정.
			{
				printf("가능.\n");
			}
			else printf("불가능.\n");
		}
	}
	return 0;
}