#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 좌표 구조체.
typedef struct
{
	int rowPos;
	int colPos;
}pos;

// 단방향 TSP 문제.
// 행렬을 입력하고, 좌상에서 시작해 우하로 끝나는 최단 가중치 경로를 출력한다.
// 이 때, 맨 위와 아래 행은 서로 연결된 것으로 취급한다.

// 나중에 수정할 것 : DP 설계부터 잘못됐다. 마지막 열부터 붙여나가야 한다.
int main(void)
{
	// while로 루프
	int row, col;
	while (scanf("%d %d", &row, &col))
	{
		vector<vector<int>> table(row, vector<int>(col));
		for (int i = 0; i < row; i++) for (int j = 0; j < col; j++)
			scanf("%d", &table[i][j]);

		// DP테이블을 만든다 : a좌표에서 b좌표로 가는 최단거리.
		// 이론상 못가는 경우를 체크하기 위해, 초기값은 전부 INT_MAX로.
		vector<vector<int>> DP(row * col, vector<int>(row * col, INT_MAX));

		// 경로추적을 위한 배열도 만든다. a좌표에서 b좌표로 갈 때, b 바로 이전 단계가 b의 입장에서 행방향으로 어딘지.
		vector<vector<int>> route(row * col, vector<int>(row * col));

		// DP를 입력값으로 초기화.
		for (int i = 0; i < DP.size(); i++) for (int j = 0; j < DP[0].size(); j++)
		{
			// i좌표와 j좌표의 차이가 열 1칸인 경우에만 시행. 또한 i의 열이 더 작아야 한다.
			int i_col = i % col, j_col = j % col;
			if (i_col + 1 == j_col)
			{
				// 이번엔 i와 j의 행 차이가 1 이하여야 한다.(절댓값 차가 1 이하거나 최대인 경우)
				int i_row = i / col, j_row = j / col;
				if (abs(i_row - j_row) <= 1 || abs(i_row - j_row) == row - 1)
				{
					// 이 경우에만 값을 들인다.
					DP[i][j] = table[i_row][i_col] + table[j_row][j_col];

					// 경로의 경우, 행관계를 이용해 정한다.
					int gap = j_row - i_row;
					if (gap == col - 1) route[i][j] = -1;
					else if (gap == -col + 1) route[i][j] = 1;
					else route[i][j] = gap;
				}
			}
		}

		// a와 b의 열차이 값을 올리면서 진행한다.
		for (int c = 2; c < col; c++)	// 열차이 값
		{
			for (int i = 0; i < DP.size(); i++) for (int j = 0; j < DP[0].size(); j++)
			{	// 전부 도는 만큼, 내부에서 유효검사를 해야 한다.
				
				// i의 열 + c가 j의 열인 경우에만 시행.
				int i_col = i % col, j_col = j % col;
				if (i_col + c == j_col)
				{
					// DP(a, b) = min(DP(a, c) + DP(c, b)). 단 c는 b의 바로 이전 상중하.
					int j_row = j / col;
					int c_col = j_col - 1;
					int temp[3] = {-1, 0, 1};	// c의 행값이 들어갈 것이다.
					for (int temp_i = 0; temp_i < 3; temp_i++)
					{
						temp[temp_i] = (j_row  + temp[temp_i] + row) % row;
					}
					// 저 행값으로 후보들의 가중치를 고른다. INT_MAX 클램핑.
					for (int temp_i = 0; temp_i < 3; temp_i++)
					{
						int temp_pos = temp[temp_i] * row + c_col;
						if (DP[i][temp_pos] == INT_MAX)
						{
							temp[temp_i] = INT_MAX;
							continue;
						}
						else
						{
							temp[temp_i] = DP[i][temp_pos] + DP[temp_pos][j] + table[j_row][j_col];
						}
					}

					// temp 배열에는 이제 가중치들이 들어갔다. 여기서 최소 고르면 된다.
					int minIndex = 0;
					for (int k = 0; k < 3; k++)
					{
						if (temp[minIndex] > temp[k]) minIndex = k;
					}
					DP[i][j] = temp[minIndex];

					// 경로도 설정한다.
					switch (minIndex)
					{
					case 0: route[i][j] = 1;
						break;
					case 1: route[i][j] = 0;
						break;
					case 2: route[i][j] = -1;
						break;
					default:break;
					}
				}
			}
		}

		// DP 채우기가 끝났다. 시작열에서 끝열로 진행하는 최소값을 찾아 그 가중치를 가져온다.
		int minNum = INT_MAX, min_a = 0, min_b = 0;
		for (int i = 0; i < row; i++) for(int j = 0; j < row; j++)
		{
			if (DP[i * row + 0][j * row + col - 1] < minNum)
			{
				minNum = DP[i * row + 0][j * row + col - 1];
				min_a = i * row + 0; 
				min_b = j * row + col - 1;
			}
		}
		/*
		// 경로도 가져올 수 있도록 한다.
		vector<int> pass;
		pass.push_back(min_b / col);
		for (int i = 0; i < col - 1; i++)
		{
			int temp = route[min_a][min_b];	// 어디로 가야 하는가
			int temp_row = ((min_b / col) - temp + row) % row, temp_col = min_b % col - 1;	// 임시좌표
			min_b = temp_row * row + temp_col;
			pass.push_back(temp_row);
		}

		for (int i = pass.size() - 1; i != -1; i--)
		{
			cout << pass[i] + 1 << ' ';
		}
		*/
		cout << endl << minNum << endl;


	}
	return 0;
}