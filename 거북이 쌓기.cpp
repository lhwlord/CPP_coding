#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// �ź��̸� �״´�.
// ���� �հ��� ����� ���� ������ 5607������ �ź��̴� ü�߰� ü���� ��� �ٸ���.
// ������ �� ���� ���� �ź��̸� �״� ����� ã�´�.
// �Է��� (ü��, ��) �� ���� ��.
int main(void)
{
	// ���Ը� ��� ���ϸ鼭 ���Ϳ� �ִ´�.
	int w, p;
	vector<int> weight;
	vector<int> power;
	while (scanf("%d %d", &w, &p))	// �Է��� ���ӵǴ� ��
	{
		weight.push_back(w);
		power.push_back(p);
	}

	// ������ ��Ʈ. weight, power�� ���ĳ����� ����Ʈ�ϸ� ������, ��ư.
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
	
	// ���̺���� ������ ����, weight�� power���� 0�� �ε����� �߰��Ѵ�. ���̴�.
	power.insert(power.begin(), 0);
	weight.insert(weight.begin(), 0);

	// ���̺� ����. i����, j����.(�����ش� ��ü ���̺� ���鼭 ������, ������ ���Ѵ밡 �ƴ� �ִ� j��(�ε���)�̴�.)
	// i������°�� ���� ���� ������ ������ power, weight�� ���󰣴�.
	vector<vector<int>> table(weight.size(), vector<int>(weight.size()));

	// �ʱ�ȭ : 0���� 0���� �д�. 0�� �ź��� �̿��� n������ ���Ѵ�(�ذ� ����), Ȥ�� n�� �ź��� �̿��� 0������ ���� ���̸� �ּҹ��� 0�̱� ����. i, j �� �� �ź� �� + 1�̹Ƿ� for�� �ѹ��� �۾� ����.
	for (int i = 0; i < table.size(); i++)
	{
		table[0][i] = INT_MAX;
		table[i][0] = 0;
	}

	// DP�� ������.()
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

	// ���̺� ���
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table.size(); j++)
		{
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}

	// �����ظ� ã�´�. INT_MAX�� �ƴ� �� �� ���� ū ���� ���� j���� ��ġ�� ã�°Ŵ�.
	// �׳� ����for�� ������.
	int max_turtle = 0;
	for (int i = 0; i < table.size(); i++) for (int j = 0; j < table[i].size(); j++)
		if (table[i][j] != INT_MAX && max_turtle < j) max_turtle = j;

	cout << max_turtle << endl;
	return 0;
}