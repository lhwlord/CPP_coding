#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX = 10002;
int list[MAX] = { 0, };	// 0번은 안쓰는 셈 치고 진행

// 백준 #10989 : 수 정렬하기 3
int main(void)
{
	// 카운트 리스트를 이용한다.
	// 1. 정렬할 데이터에서 원소 개수가 몇개인지를 리스트로 만든다.(리스트 범위는 최소값~최대값)
	// 2. 오름차순 기준, 자기 앞의 원소 개수를 더해서 갱신한다.(내림차순이면 뒤의 원소 더하기)
	// 3. 입력데이터의 끝부터 하나씩 넣으면서 해당 위치의 리스트 값을 뺀다.(내림차순이면 앞부터)
	// ㄴ 끝부터 넣을 필요는 없어보인다. 한번 해보자.

	// 문제에선 범위를 1 ~ 9999까지로 정해줬다.

	// 수정 : 말 그대로 개수 세는 것까지만 진행해야 한다. 입력정보를 저장하려면 메모리 초과 문제가 생긴다.
	int N;
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		list[temp]++;
	}


	/*
	for (int i = 1; i < MAX; i++)
	{
		list[i] += list[i - 1];
	}

	
	vector<int> result(N);
	for (int i = 0; i < N; i++)
	{
		result[list[arr[i]]-- - 1] = arr[i];	// 리스트는 0번 인덱스를 1로 표시했으므로 1 빼야 한다.
	}
	for (int i = 0; i < N; i++)
		printf("%d\n", result[i]);
	*/



	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < list[i]; j++)
		{
			printf("%d\n", i);
		}
	}

	

	return 0;
}