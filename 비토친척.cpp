#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ����� ģô��.
// ����� ��� ģô������ �Ÿ� ������ ���� ���� ���� ���� ���ϰ� �;��Ѵ�.
// �Է� : ù ���� �׽�Ʈ���̽� ����, ���̽� �� ģô�� ��/������. ������ �ߺ�����
// ģô�� ���� 500 ����, �������� 30000 ���� ���.
// ��� : ��� ģô�������� �Ÿ� ����.

// �ַ��
// �迭�� ������ �ְ�, ������ ���� ���̳��� �� ���� for������ ����
// �� ���� �� i���� �ٸ� ������ �Ÿ��� �����ϰ�, �̰ɷ� �ּҰ� ã��
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int loop = 0; loop < testCase; loop++)
	{
		int houseNum, max = 0, min = 0;
		vector<int> adress;
		cin >> houseNum;
		for (int i = 0; i < houseNum; i++)
		{
			adress.push_back(0);
			cin >> adress[i];
			if (i == 0)
			{
				max = min = adress[0];
			}
			else if (max < adress[i]) max = adress[i];
			else if (min > adress[i]) min = adress[i];
		}

	
		int minDistance = 0;

		for (int i = min; i <= max; i++)
		{
			int distance = 0;
			for (int j = 0; j < adress.size(); j++)
			{
				int temp = i - adress[j] < 0 ? adress[j] - i : i - adress[j];
				distance += temp;	// �̰��� i�� ���� ���� ���� �Ÿ�����
			}
			// �ּ� �Ÿ����� ���ϱ�
			if (i == min) minDistance = distance;
			else if (minDistance > distance) minDistance = distance;
		}
		cout << minDistance << endl;
	}
	return 0;
}