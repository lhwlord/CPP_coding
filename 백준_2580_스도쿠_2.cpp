#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool one = false;	// �ϳ��� ������ ����ġ����

vector<vector<int>> arr(9, vector<int>(9));
vector<pair<int, int>> zeros;

void backtrack(vector<vector<int>> ar, int zero)
{
	if (one) return;
	if (!zero)
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
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++)
	{
		if (ar[i][j] == 0)	
		{
			for (int k = 1; k <= 9; k++)	// �ĺ�����
			{
				int ii = i / 3, jj = j / 3;
				for (int l = 0; l < 9; l++)
				{
					if (ar[i][l] == k) goto out;
					if (ar[l][j] == k) goto out;
					
					
				}
				for (int m = 0; m < 3; m++) for (int n = 0; n < 3; n++)
				{
					if (ar[ii * 3 + m][jj * 3 + n] == k) goto out;
				}
				ar[i][j] = k;
				backtrack(ar, zero - 1);
				ar[i][j] = 0;
			out:;
			}
		}
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


	backtrack(arr, zero);

	return 0;
}