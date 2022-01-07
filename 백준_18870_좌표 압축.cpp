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

// ���� #18870 : ��ǥ ����

int main(void)
{
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> arr_2(N); // set�� �̿����� �ʴ� ��� N��ŭ ũ���Ҵ�
	//set<int> temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		arr_2[i] = arr[i];	
		//temp.insert(arr[i]);
	}

	/* set�� �̿��ϴ� ���. (��, ���⼱ ������ ���� �ٽ� ���ͷ� ����ִ� �������� �ڿ��Ҹ� �� Ŀ����.)
	for (auto i : temp)
	{
		arr_2.push_back(i);
	}
	*/

	sort(arr_2.begin(), arr_2.end());

	/*
	// �������� ���°� ���̺귯�� �Լ��� �̿��ϸ� �������� �ȴ�.
	arr_2.erase(unique(arr_2.begin(), arr_2.end()), arr_2.end());
	arr_2.shrink_to_fit();
	*/

	/* 
	// �̰ɷ� �ϸ� �ð��ʰ��� ���. erase ��� �ε����� �����ؼ� ó���ϴ� ����� �ð��ʰ��� ����.
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


	// unique ���� ����. 
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