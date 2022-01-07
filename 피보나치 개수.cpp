#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 벡터끼리 비교. 자릿수가 더 큰지부터 보고, 같다면 하나하나 비교해서 앞이 크면 1, 뒤가 크면 -1, 같으면 0 리턴.
int cmp(vector<char> a, vector<char> b)
{
	if (a.size() > b.size()) return 1;
	else if (a.size() < b.size()) return -1;
	else
	{
		for (int i = a.size() - 1; i != -1; i--)
		{
			if (a[i] > b[i]) return 1;
			else if (a[i] < b[i]) return -1;
		}
	}
	return 0;
}

vector<char> plu(vector<char> a, vector<char> b)
{
	vector<char> c;
	int temp;

	int smaller = cmp(a, b) <= 0 ? a.size() : b.size();

	// 공통부분 계산
	for (int i = 0; i < smaller; i++)
	{
		int temp = c.size() - 1;
		if (temp < i) c.push_back(0);

		c[i] += a[i] + b[i];
		if (c[i] >= 10)
		{
			c.push_back(c[i] / 10);
			c[i] %= 10;
		}
	}
	
	// 남는부분 마저 계산
	if (a.size() > b.size())
	{
		
		for (int i = b.size(); i < a.size(); i++)
		{
			int temp = c.size() - 1;
			if (temp < i) c.push_back(0);

			c[i] += a[i];
			if (c[i] >= 10)
			{
				c.push_back(c[i] / 10);
				c[i] %= 10;
			}
		}
	}
	else if (a.size() < b.size())
	{
		for (int i = a.size(); i < b.size(); i++)
		{
			int temp = c.size() - 1;
			if (temp < i) c.push_back(0);

			c[i] += b[i];
			if (c[i] >= 10)
			{
				c.push_back(c[i] / 10);
				c[i] %= 10;
			}
		}
	}

	return c;
}

int main(void)
{
	string a, b;
	
	while (1)
	{
		cin >> a >> b;
		cout << a << b << endl;

		if (a[0] == 0 && b[0] == 0) break;
		vector<char> aa, bb;

		while (1)
		{
			if (a.length() != 0)
			{
				aa.push_back(a[a.length() - 1] - 0x30);
				a.erase(a.length() - 1, 1);
			}
			if (b.length() != 0)
			{
				bb.push_back(b[b.length() - 1] - 0x30);
				b.erase(b.length() - 1, 1);
			}

			if (a.length() == b.length() && a.length() == 0) break;
		}


		vector<char> fib, fib_prev, temp;
		fib.push_back(1);
		fib_prev.push_back(0);
		
		int count = 0;

		while (cmp(fib, bb) != 1)
		{
			// 현재 fib가 a보다 큰 경우 count++.
			if (cmp(fib, aa) != -1) count++;
			// temp에 fib 대입.
			temp = fib;
			// fib에는 자신과 이전 fib를 더하여 대입.
			fib = plu(fib, fib_prev);
			// 이전 fib는 temp로 대입.
			fib_prev = temp;

		}

		cout << count << endl;
	}
	
	return 0;
}