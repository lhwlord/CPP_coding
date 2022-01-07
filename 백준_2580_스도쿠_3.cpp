#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool one = false;	// �ϳ��� ������ ����ġ����

vector<vector<int>> arr(9, vector<int>(9));
vector<pair<int, int>> zeros;
vector<vector<int>> num;

// ��Ʈ��ŷ ����, ������ ��ȿ���� Ȯ��
bool check(vector<vector<int>>& ar, int row, int col)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != row && ar[i][col] == ar[row][col]) return false;
		if (i != col && ar[row][i] == ar[row][col]) return false;
	}
	int row_ = row / 3, col_ = col / 3;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
	{
		if (row_ * 3 + i != row || col_ * 3 + j != col)
		{
			if (ar[row_ * 3 + i][col_ * 3 + j] == ar[row][col]) return false;
		}
	}
	return true;
}

void backtrack(vector<int> build)
{
	if (one) return;
	if (build.size() == num.size()) // ����.
	{
		vector < vector<int>> ar = arr;
		
		for (int i = 0; i < build.size(); i++)
		{
			ar[zeros[i].first][zeros[i].second] = build[i];
			if (!check(ar, zeros[i].first, zeros[i].second)) return;
		}
		one = true;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d ", ar[i][j]);
			}
			if(i != 8) printf("\n");
		}
		return;
	}
	if (one) return;
	for (int i = 0; i < num[build.size()].size(); i++)
	{
		build.push_back(num[build.size()][i]);
		backtrack(build);
		build.pop_back();
	}
	
}


// ���� #2580 : ������
int main(void)
{
	int zero = 0;

	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++)
	{
		scanf("%d", &arr[i][j]);
		if (arr[i][j] == 0) { zero++; zeros.push_back({ i, j });}
	}

	
	// ���� 0�� ��ǥ�鸸 ��������, ����/����/�׸𿡼� �ϳ��� 0�� ������� ä��������.
	bool once = true;	// �̹� �������� �ϳ��� �ٲ����� ��� ����
	while (once)
	{
		once = false;
		vector<int> unique_row(9, 0);
		vector<int> unique_col(9, 0);

		for (int i = 0; i < zeros.size(); i++)	// ����/���ο��� 0�� ��ǥ ���� �ľ�
		{
			unique_row[zeros[i].first]++;
			unique_col[zeros[i].second]++;
		}



		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)	// �׸𿡼� ȥ�ڸ� 0�� ��ǥ �ľ� �� ���ֱ�
		{
			int zero_count = 0;
			int temp_r = 0, temp_c = 0;
			for (int k = 0; k < 3; k++) for (int l = 0; l < 3; l++)
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

		// �̹� �ƴ��� Ȯ���ϰ�, ���������� zeros���� ����
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
			{
				zeros.erase(zeros.begin() + i--);
				zero--;
			}
		}


	}
	

	num = vector<vector<int>>(zeros.size());

	// ���� zeros ������ �ĺ����� num�� �ְ� ��Ʈ��ŷ
	for (int i = 0; i < zeros.size(); i++)
	{
		vector<bool> table(10, true);	// 1~9�� ���� �Ѵ�. 0�� ����
		for (int j = 0; j < 9; j++)
		{
			table[arr[zeros[i].first][j]] = false;
			table[arr[j][zeros[i].second]] = false;
		}
		int i_ = zeros[i].first / 3, j_ = zeros[i].second / 3;
		for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++)
		{
			table[arr[i_*3+j][j_*3+k]] = false;
		}

		for (int j = 1; j <= 9; j++)
		{
			if (table[j]) num[i].push_back(j);
		}
	}

	backtrack(vector<int>());

	return 0;
}