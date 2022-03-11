#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<char>> table;
int sight[4][2] = {
	{0, -1},
	{0, 1},
	{1, -1},
	{1, 1}
};

// 백준 #1014 : 컨닝
int main(void)
{
	int C_;
	scanf("%d", &C_);
	while (C_--)
	{
		int row, col;
		scanf("%d %d", &row, &col);
		getchar();

		// 백트래킹으로 먼저 시도. 안되면 DP.
		// '.', 'X' 외에 내가 고른 곳은 'A', 내가 버린 곳은 'B', A에 의해 막힌 곳은 'C'
		table = vector<vector<char>>(row + 2, vector<char>(col + 2, 'X'));
		
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++) // 입력
			{
				scanf("%c", &table[i][j]);
			}
			getchar();
		}



		// 백트래킹.
		int count = 0, max = -1;
		int row_go = 1, col_go = 1;

	backtrack:

		// 순서대로 지나가며 A를 찍는다.
		for (int i = row_go; i <= row; i++)
		{
			for (int j = col_go; j <= col; j++)
			{
				if (table[i][j] == '.')
				{
					table[i][j] = 'A'; count++;
					for (int k = 0; k < 4; k++)
					{
						table[i + sight[k][0]][j + sight[k][1]] = table[i + sight[k][0]][j + sight[k][1]] == '.' ? 'C' : table[i + sight[k][0]][j + sight[k][1]];
					}
				}
			}
			col_go = 1;	// 첫 루프에만 이전좌표를 먹인다. 행과는 다르게 새 열번호는 1부터 들어가야 한다.
		}
		if (max < count) max = count;	// 최대값 최신화

		// 역순으로 지나가며 첫 A를 짼다. 경로에 B가 있으면 걔도 짼다.
		for (int i = row; i >= 1; i--) for (int j = col; j >= 1; j--)
		{
			if (table[i][j] == 'B') table[i][j] = '.';
			if (table[i][j] == 'A')
			{
				row_go = i; col_go = j;
				table[i][j] = 'B'; count--;
				// 4방향의 C가 다른 A를 갖고 있는지 확인 후 조건부로 제거
				for (int k = 0; k < 4; k++)
				{
					int a = i + sight[k][0], b = j + sight[k][1];
					if (a == 0 || a == row + 1 || b == 0 || b == col + 1) continue;	// 범위확인
					else if(table[a][b] == 'C')	// 범위 안의 문자가 C인 경우만
					{
						for (int l = 0; l < 4; l++)
						{
							if (table[a - sight[l][0]][b - sight[l][1]] == 'A') goto out;
						}
						table[a][b] = '.';
					out:;	// A가 하나라도 있으면 C문자는 산다.
					}
				}
				goto loop_out;	// 첫 A를 정상적으로 쨌으니 백트래킹 시도.
			}
		}
	all_out : 
		printf("%d\n", max);
		continue;
	loop_out : 
		goto backtrack;





	}
	return 0;
}