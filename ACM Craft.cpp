#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
	node(int a): makeTime(a), total(a), added(false) {}	// �Ǽ��ð� ���� ������
	int makeTime;	// �Ǽ��ð�
	vector<node*> to;	// ���� ����Ű�� ����ü
	vector<node*> from;	// ���� ����Ű�� ����ü
	int total;	// ���� �Ǽ��ҿ�ð�
	bool added;	// '������ ����' �� �߰��ƴ°�?
}node;

// �׷��� �ְ�, �ִ� ����ġ �հ踦 ���϶�� ����.
/*
* �ַ�� : DP�� Ǯ��� �Ѵ�. �ٵ� ���� ���������� ����� �ʾ����Ƿ� ��� �̿��ؼ� Ǯ ��.
* ��� DP�� ������ζ�� ��ȭ�İ� ���̺��� �ʿ��ѵ�, �̰� �� �߸Ž�����.
* 1. ����ü �׷����� �����ϰ�, ������¸� �����Ѵ�.
* 2. ����ü �� �ڽ��� �����̸� '������ ����' �� �߰���Ų��.
* 3. ��ǥ ����ü�� ������ �ƴ� �� �ݺ��Ѵ�.
* 3-1. '������ ����' �� ��Ҹ� ��ȸ�ϸ�, ������ ����ü�� �ִٸ� �ڽ��� ���� �ǹ��� ����ġ�� ���� ���� �� ���� �ǹ��� ���� ��, ������ ���� �߰����ο� ���� �߰���Ų��. ���� �ش� �����ǹ����Լ� ���� ����ü���� ����(��Ȯ���� �����ǹ��� '���� ����Ű��' ���Ḹ)�� ����, ��� �����ǹ��� ���� �۾� �Ϸ� �� �ش� ���� ����ü�� '������ ����' ���� ����.
*/
int main(void)
{
	int T;
	cin >> T;
	for (int T_i = 0; T_i < T; T_i++)
	{
		// 1�ܰ� : �׷��� ���� �� ��ó��
		int N, K;
		scanf_s("%d %d", &N, &K);
		vector<node> arr;	// ����ü ���� ����

		for (int N_i = 0; N_i < N; N_i++)	// �ǹ� �� �ɸ��� �ð����� ����ü ���� �߰�
		{
			int temp_makeTime;
			scanf_s("%d", &temp_makeTime);
			arr.push_back(node(temp_makeTime));
		}

		for (int K_i = 0; K_i < K; K_i++)	// ��Ģ�� ���� ����ü ������ �߰�. �� ������ ��ȣ�� �ε����� �ޱ� ���� ��� 1�� �ٿ��� ó���� ��
		{
			int temp_from, temp_to;
			scanf_s("%d %d", &temp_from, &temp_to);
			temp_from--; temp_to--;
			arr[temp_from].to.push_back(&arr[temp_to]);
			arr[temp_to].from.push_back(&arr[temp_from]);
		}

		int target;	// �갡 ���ܳ�� ó���Ǹ� �����°Ŵ�.
		scanf_s("%d", &target);
		target--;


		// 2�ܰ� : ���ܳ�常 '������ ����'�� �߰�
		vector<node*> pointer_arr;
		for (int i = 0; i < arr.size(); i++)
			if (arr[i].from.size() == 0)
			{
				arr[i].added = true;	// ��� ��� �Ǵ� �ڵ�����, ��Ģ���� ���� �ִ´�.
				pointer_arr.push_back(&arr[i]);
			}

		// 3�ܰ� : ��ǥ ����ü�� ������ �ƴ� �� �ݺ��Ѵ�.
		while (arr[target].from.size() != 0)
		{
			// 3-1�ܰ� : '������ ����' ��ȸ�ϸ� ������ �۾� ����.
			for (int i = 0; i < pointer_arr.size(); i++)
			{
				// ���� Ȯ��
				if (pointer_arr[i]->from.size() == 0)
				{
					// �����̶�� ���� �ǹ���� �� �� ���ǵ��� �߰�, �����ǹ��� ����from ����
					for (int j = 0; j < pointer_arr[i]->to.size(); j++)
					{
						// ����ġ �� �� ����
						int edgeTime = pointer_arr[i]->total + pointer_arr[i]->to[j]->makeTime;
						if (pointer_arr[i]->to[j]->total < edgeTime)
							pointer_arr[i]->to[j]->total = edgeTime;

						// �߰� �ȵ����� �����ͺ��Ϳ� �߰�
						if (pointer_arr[i]->to[j]->added == false)
						{
							pointer_arr[i]->to[j]->added = true;
							pointer_arr.push_back(pointer_arr[i]->to[j]);
						}

						// �ش� �����ǹ��� ����from ����
						for (int k = 0; k < pointer_arr[i]->to[j]->from.size(); k++)
						{
							if (pointer_arr[i]->to[j]->from[k] == pointer_arr[i])
							{
								pointer_arr[i]->to[j]->from.erase(pointer_arr[i]->to[j]->from.begin() + k);
								break;
							}
						}
					}

					// �������μ��� �۾��� ���� �������Ƿ�, '������ �迭' ���� ����. ��, �� ���ʿ��� �ε����� ������ �����Ƿ� i�� 1 �ٿ��� �Ѵ�.
					pointer_arr.erase(pointer_arr.begin() + i);
					i--;
				}
			}
		}

		// ������ : ��ǥ ����ü�� ������ �Ǿ��ٴ� ���� ���� ����κ����� �ִ밪 ����� �����ٴ� ���̴�.
		cout << arr[target].total << endl;
	}
	return 0;
}