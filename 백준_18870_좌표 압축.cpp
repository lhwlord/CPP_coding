#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


int bin_search(vector<int>& arr, int n)
{
	int fir = 0, end = arr.size() - 1, mid = end / 2;
	while (arr[mid] != n)
	{
		if (arr[mid] > n)
			end = mid - 1;
		else
			fir = mid + 1;
		mid = (fir + end) / 2;
	}
	return mid;
}

// 백준 #18870 : 좌표 압축

int main(void)
{
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> arr_2(N); // set을 이용하지 않는 경우 N만큼 크기할당
	//set<int> temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		arr_2[i] = arr[i];	
		//temp.insert(arr[i]);
	}

	/* set을 이용하는 경우. (단, 여기선 정렬을 위해 다시 벡터로 집어넣는 과정에서 자원소모가 더 커진다.)
	for (auto i : temp)
	{
		arr_2.push_back(i);
	}
	*/

	sort(arr_2.begin(), arr_2.end());

	/*
	// 고유값만 놓는건 라이브러리 함수를 이용하면 문제없이 된다.
	arr_2.erase(unique(arr_2.begin(), arr_2.end()), arr_2.end());
	arr_2.shrink_to_fit();
	*/

	/* 
	// 이걸로 하면 시간초과가 뜬다. erase 대신 인덱스에 접근해서 처리하는 방법도 시간초과가 떴다.
	int M = N;
	for (int i = 1; i < M; i++)
	{
		if (arr_2[i] == arr_2[i - 1])
		{
			arr_2.erase(arr_2.begin() + i--);
			M--;
		}
	}
	*/


	// unique 직접 구현. 
	vector<int>::iterator start = arr_2.begin();
	vector<int>::iterator end = arr_2.end();
	vector<int>::iterator point = start;
	while (++start != end)
	{
		if (*start != *point)
		{
			*(++point) = *start;
		}
	}
	arr_2.erase(++point, end);
	arr_2.shrink_to_fit();


	for (int i = 0; i < N; i++)
	{
		printf("%d ", bin_search(arr_2, arr[i]));
	}
	

	return 0;
}