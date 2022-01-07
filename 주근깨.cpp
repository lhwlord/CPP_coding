#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 주근깨 연결하는 문제.
// 노드간의 거리를 아예 2차원배열로 지정한다.
// 임의의 1개 점을 집합에 놓고, 자기 집합에서 (집합내부요소 제외하고) 가장 가까운 요소 골라서 그 길이를 합계에 추가한다.
int main(void)
{
	int T;
	scanf("%d", &T);
	getchar();
	getchar();	// 빈줄 2개 입력받아서 버리는 용도
	while (T--)
	{
		int n;
		scanf("%d", &n);
		// 거리 구할 벡터
		vector<vector<double>> distance(n, vector<double>(n, 2147483647));
		// 좌표값 벡터. 이걸로 거리벡터를 채워야 한다.
		vector<vector<double>> pos(n, vector<double>(2));

		for (int i = 0; i < n; i++)	// 좌표값 입력받기
		{
			scanf("%lf %lf", &pos[i][0], &pos[i][1]);
		}

		// 거리 계산해서 거리벡터에 넣는다.
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		{
			distance[i][j] = sqrt((pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]) + (pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1]));
		}

		// 임의의 점을 하나 고른다. 해답에 들어가는 벡터와 아닌 벡터를 나눈다.
		vector<int> answer, notyet;
		double result = 0;
		answer.push_back(0);
		for (int i = 1; i < n; i++) { notyet.push_back(i); }	// 초기지정
		
		// 반복문 이용해서 구한다.
		while (notyet.size() != 0)
		{
			// 최소값 찾기 : 자신의 집합에서, 자신의 집합을 대상으로 하지 않은 값들 중에서 찾기.
			double min = 99e9;	// 적당히 크게 지정
			int targetIndex = -1;
			for (int i = 0; i < answer.size(); i++)
			{
				for (int j = 0; j < notyet.size(); j++)	// notyet에서 찾으면 어차피 내가 아니게 된다.
				{
					if (min > distance[answer[i]][notyet[j]])
					{
							min = distance[answer[i]][notyet[j]];
							targetIndex = j;
					}
				}
			}
			
			// 최소값에 해당하는 값을 결과값에 추가하고, 거기에 쓰인 값은 answer과 notyet에서 적당히 처리.
			result += min;
			answer.push_back(notyet[targetIndex]);
			notyet.erase(notyet.begin() + targetIndex);
		}

		// 결과 출력.
		printf("%f\n\n", result);
	}
}