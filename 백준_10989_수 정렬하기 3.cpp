#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX = 10002;
int list[MAX] = { 0, };	// 0���� �Ⱦ��� �� ġ�� ����

// ���� #10989 : �� �����ϱ� 3
int main(void)
{
	// ī��Ʈ ����Ʈ�� �̿��Ѵ�.
	// 1. ������ �����Ϳ��� ���� ������ ������� ����Ʈ�� �����.(����Ʈ ������ �ּҰ�~�ִ밪)
	// 2. �������� ����, �ڱ� ���� ���� ������ ���ؼ� �����Ѵ�.(���������̸� ���� ���� ���ϱ�)
	// 3. �Էµ������� ������ �ϳ��� �����鼭 �ش� ��ġ�� ����Ʈ ���� ����.(���������̸� �պ���)
	// �� ������ ���� �ʿ�� ����δ�. �ѹ� �غ���.

	// �������� ������ 1 ~ 9999������ �������.

	// ���� : �� �״�� ���� ���� �ͱ����� �����ؾ� �Ѵ�. �Է������� �����Ϸ��� �޸� �ʰ� ������ �����.
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
		result[list[arr[i]]-- - 1] = arr[i];	// ����Ʈ�� 0�� �ε����� 1�� ǥ�������Ƿ� 1 ���� �Ѵ�.
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