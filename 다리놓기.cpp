#pragma warning(disable:4996)

#include <iostream>
#include <vector>

using namespace std;

// 다리놓기 : nCr DP로 구하기. 딱봐도 재귀로 풀기엔 시간이 안된다.
// 멀티플랫폼 개발의 경우 scanf를 위험을 감수하고 써야 하는 것으로 보인다.
int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int aa, bb;
		scanf("%d %d", &aa, &bb);
		int a, b;
		a = aa > bb ? aa : bb;
		b = a == aa ? bb : aa;
		vector<vector<int>> arr(a + 1, vector<int>(b + 1, 1));
		for (int i = 1; i < a + 1; i++)
		{
			for (int j = 1; j <= i && j < b + 1; j++)
			{
				if (i == j) continue;
				else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
		cout << arr[arr.size() - 1][arr[arr.size() - 1].size() - 1] << endl;
	}
	return 0;
}