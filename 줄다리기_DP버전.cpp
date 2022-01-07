#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �ٴٸ��� ������ DP�� �ذ��Ѵ�.
// �ٵ� �������� ���� �ð����⵵�� �� ������. �Ǳ� ������, ��ư.
int main(void)
{
	int T;
	scanf("%d", &T);
	cin.get();
	while (T--)
	{
		int num, total = 0;
		scanf("%d", &num);
		
//		// ��������. ������ ��
//		srand(time(NULL));
//		num = 100;

		vector<int> weight(num);
		
		for (int i = 0; i < num; i++)
		{
			scanf("%d", &weight[i]);
			total += weight[i];
		}
		

//		// ��������. ������ ��
/*		for (int i = 0; i < num; i++)
		{
			weight[i] = rand() % 450;
			cout << weight[i] << ' ';
			total += weight[i];
		}cout << endl;
*/

		

		// ���� ���ո�ŭ�� ���� ����. ���߿� n��ŭ ���鼭 �� ���͸� ������ ���̴�.
		vector<vector<int>> arr(total + 1, vector<int>(0));

		// ��� ���Ը� �����ϴ� ����. num / 2 ũ�⸸ŭ á���� ���⿡ �ְ�, �̰͸� ���ϸ� �ȴ�.
		vector<int> ans;

		// ���� ���鼭 ������ �� �ֱ�
		for (int i = 0; i < num; i++)	// �� ���� ��
		{
			for (int j = 0; j < total + 1; j++)	// arr�� ���鼭
			{
				for (int k = 0; k < arr[j].size(); j++)	// ���� j�� ���� ���Ұ�����ŭ(������ �ڵ���ŵ)
				{
					// ������ ������� ���� ��쿡 ����ؼ� �÷�ġ�� �õ�.
					if (arr[j][k] + 1 < num / 2)
					{
						arr[j + weight[i]].push_back(arr[j][k] + 1);
					}
					else if (arr[j][k] + 1 == num / 2)	// ���ϴ� ��ŭ ä������ �ȳְ� �ٷ� ����
						ans.push_back(j + weight[i]);
					else // �̰� ������ �ȵȴ�.
						cout << "����.\n";
				}
			}
			// �̿ʹ� ������ �ڱ� �ڽŵ� �迭�� �߰�
			if (num / 2 == 1)
			{
				ans.push_back(weight[i]);
			}
			else arr[weight[i]].push_back(1);
		}

		// ������� ���鼭 ���� ���� ���̳��� �� ã��
		int smaller = 0;
		for (int temp : ans)
		{
			int temp2 = total - temp;
			if (abs(temp2 - temp) < total - smaller - smaller)
			{
				temp2 = temp2 < temp ? temp2 : temp;
				smaller = temp2;
			}
		}
		printf("%d %d\n\n", smaller, total - smaller);
		cin.get();
	}
	return 0;
}