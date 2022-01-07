#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �׷����� ����ǥ�� �ְ�, ����ϸ鼭 ����.
bool findPath(vector<vector<int>>& arr, vector<int>& color, int cur, int prev)
{
	bool check = true;
	for (int i = 0; i < arr[cur].size(); i++)	// �迭�� �ش� ����� ���ἱ ������ŭ ���鼭
	{
		// ���� �ִ���, ������ �ڽŰ� ���� ���������� �˻�
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



// �׷����� ���� ��, ����� ������ ��Ī�Ǵ� �� ����� ���� �ٸ��� ���� �������� ����.

int main(void)
{
	int n;	// ��� ����
	while (true)
	{
		scanf("%d", &n);
		if (n == 0) break;
		else // ������Ͱ� ���� ���ۺ�.
		{
			int l;
			scanf("%d", &l);	// ���ἱ ����
			vector<vector<int>> arr(n);	// �迭���� ������� �ľǿ�
			vector<int> color(n, 0);	// �ش� ��尡 ���� ������ ĥ�����ִ°�? ������ : 0
			while (l--)
			{
				int a, b;
				scanf("%d %d", &a, &b);
				arr[a].push_back(b);
				arr[b].push_back(a);
			}
			color[0] = 1;	// �ʱ�ȭ
			if (findPath(arr, color, 0, -1))// 0�� ��忡�� �����ϱ�. �������� ������ -1�� ����.
			{
				printf("����.\n");
			}
			else printf("�Ұ���.\n");
		}
	}
	return 0;
}