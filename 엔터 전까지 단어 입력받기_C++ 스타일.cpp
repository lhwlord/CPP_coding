#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
	string s;
	//getline(cin, s);
	stringstream ss(s);
	vector<string> arr(1);
	
	while (getline(cin, arr[arr.size() - 1], ' '))	// ' ' 이 있어야 구분한다.
	{
		arr.push_back("");
	}

	for (auto i : arr)
		cout << i << '\n';
}