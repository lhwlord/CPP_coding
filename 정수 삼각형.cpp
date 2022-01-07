#include <iostream>
#include <vector>

using namespace std;

// 정수 삼각형이 주어졌을 때, 최대값의 경로를 찾기.
/*
DP를 써야 시간절약이 가능할 것이다.
*/
int main(void)
{
	int t_case; vector<vector<int>> arr;
	cin >> t_case;
	for (int i = 0; i < t_case; i++)
	{
		vector<int> temp;
		for (int j = 0; j <= i; j++)
		{
			int tmp;
			scanf_s("%d", &tmp);
			temp.push_back(tmp);
		}
		arr.push_back(temp);
	}

	vector<vector<int>> result;
	// DP코드.
	vector<int> temp_first;
	for (int i = 0; i < arr[arr.size() - 1].size(); i++)
	{
		temp_first.push_back(arr[arr.size() - 1][i]);
	}
	result.push_back(temp_first);
	for (int i = arr.size() - 2; i != -1; i--)
	{
		vector<int> temp_last;
		for (int j = 0; j < arr[i].size(); j++)
		{
			int cand1 = arr[i][j] + result[arr.size() -2 - i][j], cand2 = arr[i][j] + result[arr.size() -2 - i][j + 1];
			temp_last.push_back(cand1 > cand2 ? cand1 : cand2);
		}
		result.push_back(temp_last);
	}
	cout << result[result.size() - 1][0] << endl;
	
	return 0;
}