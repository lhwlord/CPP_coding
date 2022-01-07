#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 거북이를 쌓는다.
// 왕의 왕관을 만들기 위해 동원된 5607마리의 거북이는 체중과 체력이 모두 다르다.
// 가능한 한 가장 많은 거북이를 쌓는 방법을 찾는다.
// 입력은 (체중, 힘) 의 여러 줄.
int main(void)
{
	// 무게를 계속 구하면서 벡터에 넣는다.
	int w, p;
	vector<int> weight;
	vector<int> power;
	while (scanf("%d %d", &w, &p))	// 입력이 지속되는 한
	{
		weight.push_back(w);
		power.push_back(p);
	}

	// 적당히 소트. weight, power을 합쳐놨으면 퀵소트하면 되지만, 여튼.
	for (int i = 0; i < power.size(); i++)
	{
		for (int j = i; j < power.size(); j++)
		{
			if (power[i] > power[j])
			{
				int temp = power[i];
				power[i] = power[j];
				power[j] = temp;
				
				temp = weight[i];
				weight[i] = weight[j];
				weight[j] = temp;
			}
		}
	}
	
	// 테이블과의 연동을 위해, weight와 power에도 0번 인덱스를 추가한다. 더미다.
	power.insert(power.begin(), 0);
	weight.insert(weight.begin(), 0);

	// 테이블 생성. i마리, j마리.(최적해는 전체 테이블 돌면서 나오는, 셀값이 무한대가 아닌 최대 j값(인덱스)이다.)
	// i마리번째를 쓰는 것은 위에서 지정한 power, weight를 따라간다.
	vector<vector<int>> table(weight.size(), vector<int>(weight.size()));

	// 초기화 : 0번은 0으로 둔다. 0개 거북을 이용해 n마리는 무한대(해가 없음), 혹은 n개 거북을 이용해 0마리를 쓰는 것이면 최소무게 0이기 때문. i, j 둘 다 거북 수 + 1이므로 for문 한번에 작업 가능.
	for (int i = 0; i < table.size(); i++)
	{
		table[0][i] = INT_MAX;
		table[i][0] = 0;
	}

	// DP를 돌린다.()
	for (int i = 1; i < table.size(); i++)
	{
		for (int j = 1; j < table[i].size(); j++)
		{
			if (table[i - 1][j - 1] + weight[i] > 0 && table[i - 1][j - 1] + weight[i] <= power[i])
			{
				table[i][j] = min(table[i - 1][j - 1] + weight[i], table[i - 1][j]);
			}
			else
			{
				table[i][j] = table[i - 1][j];
			}
		}
	}

	// 테이블 출력
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table.size(); j++)
		{
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}

	// 최적해를 찾는다. INT_MAX가 아닌 값 중 가장 큰 값을 가진 j값의 위치를 찾는거다.
	// 그냥 이중for문 돌리자.
	int max_turtle = 0;
	for (int i = 0; i < table.size(); i++) for (int j = 0; j < table[i].size(); j++)
		if (table[i][j] != INT_MAX && max_turtle < j) max_turtle = j;

	cout << max_turtle << endl;
	return 0;
}