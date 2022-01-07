#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
	node(int a): makeTime(a), total(a), added(false) {}	// 건설시간 들어가는 생성자
	int makeTime;	// 건설시간
	vector<node*> to;	// 내가 가리키는 구조체
	vector<node*> from;	// 나를 가리키는 구조체
	int total;	// 최종 건설소요시간
	bool added;	// '포인터 벡터' 에 추가됐는가?
}node;

// 그래프 주고, 최대 가중치 합계를 구하라는 문제.
/*
* 솔루션 : DP로 풀어야 한다. 근데 아직 위상정렬을 배우지 않았으므로 노드 이용해서 풀 것.
* 사실 DP의 정석대로라면 점화식과 테이블이 필요한데, 이건 좀 야매스럽다.
* 1. 구조체 그래프를 형성하고, 연결상태를 적용한다.
* 2. 구조체 중 자신이 말단이면 '포인터 벡터' 에 추가시킨다.
* 3. 목표 구조체가 말단이 아닌 한 반복한다.
* 3-1. '포인터 벡터' 의 요소를 순회하며, 말단인 구조체가 있다면 자신의 상위 건물과 가중치를 놓고 비교한 후 상위 건물에 적용 후, 포인터 벡터 추가여부에 따라 추가시킨다. 이후 해당 상위건물에게서 말단 구조체로의 연결(정확히는 상위건물의 '나를 가리키는' 연결만)을 끊고, 모든 상위건물에 대한 작업 완료 후 해당 말단 구조체는 '포인터 벡터' 에서 삭제.
*/
int main(void)
{
	int T;
	cin >> T;
	for (int T_i = 0; T_i < T; T_i++)
	{
		// 1단계 : 그래프 형성 및 전처리
		int N, K;
		scanf_s("%d %d", &N, &K);
		vector<node> arr;	// 구조체 담을 벡터

		for (int N_i = 0; N_i < N; N_i++)	// 건물 당 걸리는 시간으로 구조체 만들어서 추가
		{
			int temp_makeTime;
			scanf_s("%d", &temp_makeTime);
			arr.push_back(node(temp_makeTime));
		}

		for (int K_i = 0; K_i < K; K_i++)	// 규칙에 의한 구조체 포인터 추가. 단 이쪽의 번호는 인덱스로 받기 위해 모두 1씩 줄여서 처리할 것
		{
			int temp_from, temp_to;
			scanf_s("%d %d", &temp_from, &temp_to);
			temp_from--; temp_to--;
			arr[temp_from].to.push_back(&arr[temp_to]);
			arr[temp_to].from.push_back(&arr[temp_from]);
		}

		int target;	// 얘가 말단노드 처리되면 끝나는거다.
		scanf_s("%d", &target);
		target--;


		// 2단계 : 말단노드만 '포인터 벡터'에 추가
		vector<node*> pointer_arr;
		for (int i = 0; i < arr.size(); i++)
			if (arr[i].from.size() == 0)
			{
				arr[i].added = true;	// 사실 없어도 되는 코드지만, 규칙성을 위해 넣는다.
				pointer_arr.push_back(&arr[i]);
			}

		// 3단계 : 목표 구조체가 말단이 아닌 한 반복한다.
		while (arr[target].from.size() != 0)
		{
			// 3-1단계 : '포인터 벡터' 순회하며 적절한 작업 수행.
			for (int i = 0; i < pointer_arr.size(); i++)
			{
				// 말단 확인
				if (pointer_arr[i]->from.size() == 0)
				{
					// 말단이라면 상위 건물들과 비교 후 조건따라 추가, 상위건물은 말단from 삭제
					for (int j = 0; j < pointer_arr[i]->to.size(); j++)
					{
						// 가중치 비교 및 대입
						int edgeTime = pointer_arr[i]->total + pointer_arr[i]->to[j]->makeTime;
						if (pointer_arr[i]->to[j]->total < edgeTime)
							pointer_arr[i]->to[j]->total = edgeTime;

						// 추가 안됐으면 포인터벡터에 추가
						if (pointer_arr[i]->to[j]->added == false)
						{
							pointer_arr[i]->to[j]->added = true;
							pointer_arr.push_back(pointer_arr[i]->to[j]);
						}

						// 해당 상위건물의 말단from 삭제
						for (int k = 0; k < pointer_arr[i]->to[j]->from.size(); k++)
						{
							if (pointer_arr[i]->to[j]->from[k] == pointer_arr[i])
							{
								pointer_arr[i]->to[j]->from.erase(pointer_arr[i]->to[j]->from.begin() + k);
								break;
							}
						}
					}

					// 말단으로서의 작업이 전부 끝났으므로, '포인터 배열' 에서 삭제. 단, 이 위쪽에서 인덱스를 돌리고 있으므로 i도 1 줄여야 한다.
					pointer_arr.erase(pointer_arr.begin() + i);
					i--;
				}
			}
		}

		// 마무리 : 목표 구조체가 말단이 되었다는 것은 하위 노드들로부터의 최대값 계산이 끝났다는 것이다.
		cout << arr[target].total << endl;
	}
	return 0;
}