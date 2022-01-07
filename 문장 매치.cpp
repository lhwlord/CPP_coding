#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// �� ���忡�� �ٸ� �������� ���� ���� �ּҺ���� ����Ѵ�.
// Ư�� ���ڸ� �ٸ� ���ڷ� �ٲٴ� ����, Ȥ�� �߰�/������ 3���� ������ �����ϴ�.
int main(void)
{
	string a, b, route;
	char c[50] = {'\0',};	// ��Ʈ�� �ޱ�� �ӽð�ü

	scanf("%[^\n]49s", c);	// ����ǥ���Ŀ� ����, ���๮�� �������� �ִ� 49�� �о c�� ����.
	a = c;

	getchar();	// ���� ����

	scanf("%[^\n]49s", c);	// ����
	b = c;

	cout << a << ' ' << b << endl;

	// �� ������ ���̸�ŭ ����
	vector<vector<int>> table(a.length() + 1, vector<int>(b.length() + 1));

	// ù ��� ù ���� ���� �ش��ϴ� ������ �ʱ�ȭ
	for (int i = 0; i < table.size(); i++)
	{
		table[i][0] = i;
	}
	for (int i = 0; i < table[0].size(); i++)
	{
		table[0][i] = i;
	}

	// for�� ���鼭 ����.
	for (int i = 1; i < table.size(); i++) for (int j = 1; j < table[i].size(); j++)
	{
		// �� ����, ����/���/�»��� ���� ���ؼ� �ִ´�. �� ��, ������ ��ܿ��� 1 �߰��ϰ�, �»��� i�� j�� �������� ���� �����Ѵ�.(i == j�� ��쿡�� �»� ���� �õ�. ��� ����ġ ����)
		int from_left = table[i][j - 1] + 1;
		int from_up = table[i - 1][j] + 1;
		if (a[i - 1] == b[j - 1])	// ��Ʈ�� �ε����� i, j��°���� 1 ����.
		{
			table[i][j] = min(min(from_left, from_up), table[i - 1][j - 1]);
		}	
		else  // ���� ���� �ٸ��ٸ�, �����ϴ� ������ ��Һ񱳷� ����.
		{
			table[i][j] = min(min(from_left, from_up), table[i - 1][j - 1] + 1);
		}
	}

	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}

	cout << table[table.size() - 1][table[0].size() - 1] << endl;


	// ���� a ���ڿ��� ��� �����ؾ� b ���ڿ��� �Ǵ��� �˾ƺ���.
	// �»󿡼� ���������� ��ġ�ų� ����ġ, ������ ���������� ����Ʈ, ���ʿ��� ���������� �μ�Ʈ�̴�. �࿡ �ִ� a ���ڿ��� ��������� ���� ���̱� ����.
	// �߰� : �� ����� ���� ���ɼ� �ִ� ��� �� �Ѱ������� �����ش�. ���� ���� �̰� �ǽ������� ���ͼ� Ư�� ��¸��� �䱸�ϰ� �ȴٸ�, �׶� �� �ؿ� Ž�������� ������ �ٲ�� �� ���̴�.
	int row = table.size() - 1, col = table[0].size() - 1;
	while (row != 0 || col != 0)
	{
		// �� �� �ϳ��� ���� 0�� �Ǹ� �������� �״�� �ֱ�.
		if (row == 0) // col�� ���� ���Ը� ����Ѵ�.
		{
			while (col--) route += 'I';
			col = 0;
		}
		else if (col == 0)	// row�� ���� ������ ����Ѵ�.
		{
			while (row--) route += 'D';
			row = 0;
		}
		else
		{
			// ����, ����, �»� �߿� �Ǵ� ������ ����. ������ ���⼭ �Ǵ� ������ ���� ���´ٴ°� ����� ��������� ���̴� �ϳ��� ���� �ȴ�.

			if (table[row - 1][col - 1] == table[row][col] && a[row - 1] == b[col - 1])
			{
			route += 'M';
			row--; col--;
			}
			else if (table[row - 1][col - 1] + 1 == table[row][col])
			{
			route += 'S';
			row--; col--;
			}
			else if (table[row - 1][col] + 1 == table[row][col])
			{
				route += 'D';
				row--;
			}
			else if (table[row][col - 1] + 1 == table[row][col])
			{
				route += 'I';
				col--;
			}
			// �� 4������ ��찡 �ƴϸ� ������ �� ����.
			else
			{
				cout << "���� �߸��ƴ�.\n";
				row = 0; col = 0;
			}
		}
	}

	// route�� ����� ������� ���´�.
	reverse(route.begin(), route.end());

	cout << route << endl;
	return 0;
}