#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> floor_global;

// ������ a��, b������ ���� ���� ��, �°��� �ȴ� �ּҰŸ�.(a�� b ���̿� �־�� �Ѵ�.)
// 0���� ����Ѵ�.
int walk(int a, int b)
{
	int sum = 0;
	//floor_global�� ����, 1��, a��, b�����κ����� ���밪 �ּҸ� ��ȯ.
	for (int i = 0; i < floor_global.size(); i++)
	{
		// �ش� ���� �ȿ� ���� ��쿡��, �ּҰ��� �����Ѵ�.
		if (floor_global[i] > a && floor_global[i] <= b)
			sum += min(floor_global[i] - a, b - floor_global[i]);
	}
	return sum;
}

// ���������� ����ȭ ����.
// �������� �����ϱ� ����, ���� ���ߴ� ȸ���� �ּ�ȭ�ؾ� �Ѵ�.
// ����, 13/14/15���� ���� ����� ���� �ִٸ�, 14���� �ѹ� ���߸� �ٷ� ������ �Ʒ������� �ɾ �� �����Ƿ� �ѹ��� ���߸� �ȴ�.
int main(void)
{
	// ����� Ÿ��, ��� ���� �� ���ϱ�
	int man, stop;
	scanf("%d %d", &man, &stop);

	// ����� ��� ������ �ֱ�(�������� ���ĵǾ��ִ� ����)
	vector<int> floor(man);
	for (int i = 0; i < man; i++) scanf("%d", &floor[i]);

	floor_global = floor;
	

	// DP���̺��� ����� : �ִ� ����, ���. 1������ ���ߴ� ��쵵 �ִ´�.
	vector<vector<int>> table(floor[floor.size() - 1] + 1, vector<int>(stop + 1));

	// �߰���, ��� ������ ���� ���̺� �����.
	vector<vector<int>> route = table;

	// �ʱ�ȭ : ù ���� walk(0,inf)���� �����Ѵ�. �൵ ����ϰ� �����صд�.
	for (int i = 0; i < table.size(); i++)
	{
		table[i][0] = walk(0, INT_MAX);
	}
	for (int i = 0; i < table[0].size(); i++)
	{
		table[0][i] = walk(0, INT_MAX);
	}

	// DPǮ�� ���� : ���ߴ� Ƚ���� 1�� ���� ��������, 0~���� �������� �����鼭 ����ġ�� ���ϰ�, �� �ּҸ� �ִ´�.
	for (int i = 1; i < table.size(); i++)
	{
		for (int j = 1; j < table[i].size(); j++)
		{
			int temp_min = 2147483647;
			for (int k = 0; k <= i; k++)	// ������ ���簡�� �˻�.
			{
				int temp_min_candi = table[k][j-1] - walk(k, INT_MAX) + walk(k, i) + walk(i, INT_MAX);
				if (temp_min_candi > 0 && temp_min > temp_min_candi)
				{
					temp_min = temp_min_candi;
					route[i][j] = k;	// �ּҷ� �����ϴ� ����� �� ���� �����Ѵ�.(�θ�)
				}
			}
			table[i][j] = temp_min;
		}
	}

	// ���̺� ���.
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
			cout << table[i][j] << ' ';
		cout << endl;
	}

	// ������� ��� : �̰� �������ε�, ����� �ּҷ� �����̴� ���̴�.
	cout << "�ּҷ� �����̴� �Ÿ� : " << table[table.size() - 1][table[0].size() - 1] << endl;

	// ����, �� ���̺��� ���� �ش����κ��� �������� �õ��Ѵ�. ������ ��� ������ ������ �ϴ��� ����. ����, �ش��ϴ� ��ŭ ������ �� ���� ����ġ�� ���� ���� �� ���� Ȯ���Ѵ�.
	int min_floor = 0;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i][stop] < table[min_floor][stop]) // i��° ���������� ����ġ�� �� ���ٸ�
			min_floor = i;	// ���� ���� ����ġ�� �� �������� ����� �Ѵ�.
	}

	// ���� �������� ����. ������ ���� ���� stop���� 1 ���� ��ŭ �������� �� ���� ���̹Ƿ�, �̰� route�� ���ؼ� �����ϸ� �ȴ�.
	vector<int> track;
	int tempStop = stop;
	while (tempStop)
	{
		track.push_back(min_floor);
		min_floor = route[min_floor][tempStop--];
	}
	
	// ���� ����ϸ� �ȴ�.
	reverse(track.begin(), track.end());
	for (auto i : track) cout << i << endl;


	return 0;
}