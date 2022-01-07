#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool one = false;	// 하나라도 나오면 빠꾸치도록

vector<vector<int>> arr(9, vector<int>(9));
vector<pair<int, int>> zeros;

void backtrack(vector<vector<int>> ar, vector<pair<int, int>> zero)
{
	if (one) return;
	
	if (zero.size() == 0)
	{
		one = true;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d ", ar[i][j]);
			}
			printf("\n");
		}
	}
	for (int i = 0; i < zero.size(); i++)
	{
		for (int j = 1; j <= 9; j++)
		{
		out:
			if (j > 9) break;
			for (int k = 0; k < 9; k++)
			{
				if (ar[k][zero[i].second] == j) { j++; goto out; }
				if (ar[zero[i].first][k] == j) { j++; goto out; }
			}
			vector<vector<int>> ar_2 = ar;
			ar_2[zero[i].first][zero[i].second] = j;
			vector<pair<int, int>> zero_2 = zero;
			zero_2.erase(zero_2.begin() + i);
			backtrack(ar_2, zero_2);
		
		}
	}
}


// 백준 #2580 : 스도쿠
int main(void)
{
	
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++)
	{
		scanf("%d", &arr[i][j]);
		if (arr[i][j] == 0) zeros.push_back({ i, j });
	}


	
	// 먼저 0인 좌표들만 가져오고, 가로/세로/네모에서 하나만 0인 값들부터 채워나간다.
	bool once = true;	// 이번 루프에서 하나라도 바꿨으면 계속 진행
	while (once)
	{
		once = false;
		vector<int> unique_row(9, 0);
		vector<int> unique_col(9, 0);
		
		for (int i = 0; i < zeros.size(); i++)	// 가로/세로에서 0인 좌표 도수 파악
		{
			unique_row[zeros[i].first]++;
			unique_col[zeros[i].second]++;
		}

		

		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)	// 네모에서 혼자만 0인 좌표 파악 후 없애기
		{
			int zero_count = 0;
			int temp_r = 0, temp_c = 0;
			for(int k = 0; k < 3; k++) for(int l = 0; l < 3; l++)
			{
				if (!arr[i * 3 + k][j * 3 + l])
				{
					zero_count++;
					temp_r = i * 3 + k;
					temp_c = j * 3 + l;
				}
			}
			if (zero_count == 1)
			{
				once = true;
				int index = -1;
				for (int k = 0; k < zeros.size(); k++)
				{
					if (zeros[k].first == temp_r && zeros[k].second == temp_c)
					{
						index = k; break;
					}
				}


				int num = 45;
				for (int k = 0; k < 3; k++) for (int l = 0; l < 3; l++)
				{
					num -= arr[i * 3 + k][j * 3 + l];
				}
				arr[temp_r][temp_c] = num;
				zeros[index].first = -1;

			}
		}

		// 이미 됐는지 확인하고, 최종적으로 zeros에서 제거
		for (int i = 0; i < 9; i++)
		{
			if (unique_row[i] == 1)
			{
				once = true;
				int index_ = -1;
				for (int j = 0; j < zeros.size(); j++)
				{
					if (zeros[j].first == i)
					{
						index_ = j; break;
					}
				}
				if (index_ != -1 && zeros[index_].first != -1)
				{
					int num = 45;
					for (int j = 0; j < 9; j++)
					{
						num -= arr[zeros[index_].first][j];
					}
					arr[zeros[index_].first][zeros[index_].second] = num;
					zeros[index_].first = -1;
				}
			}
			if (unique_col[i] == 1)
			{
				once = true;
				int index_ = -1;
				for (int j = 0; j < zeros.size(); j++)
				{
					if (zeros[j].second == i)
					{
						index_ = j; break;
					}
				}
				if (index_ != -1 && zeros[index_].first != -1)
				{
					int num = 45;
					for (int j = 0; j < 9; j++)
					{
						num -= arr[j][zeros[index_].second];
					}
					arr[zeros[index_].first][zeros[index_].second] = num;
					zeros[index_].first = -1;
				}
			}
		}
		for (int i = 0; i < zeros.size(); i++)
		{
			if (zeros[i].first == -1)
				zeros.erase(zeros.begin() + i--);
		}

		
	}
	
	//printf("남은 0의 수는 %d개\n", zeros.size());

	// 이제 백트래킹.
	backtrack(arr, zeros);

	
	
	return 0;
}