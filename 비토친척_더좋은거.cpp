#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ����� ģô��.
// ����� ��� ģô������ �Ÿ� ������ ���� ���� ���� ���� ���ϰ� �;��Ѵ�.
// �Է� : ù ���� �׽�Ʈ���̽� ����, ���̽� �� ģô�� ��/������. ������ �ߺ�����
// ģô�� ���� 500 ����, �������� 30000 ���� ���.
// ��� : ��� ģô�������� �Ÿ� ����.

// �ַ��
// ���ʿ� �Է¹޾ƴٰ� �̰� �����ϸ� ������ ��������. �߰����� ������ �Ǳ� ����.
// �߰����� ã�´�.
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int loop = 0; loop < testCase; loop++)
	{
		int houseNum;
		vector<int> adress;
		cin >> houseNum;
		for (int i = 0; i < houseNum; i++)
		{
			adress.push_back(0);
			cin >> adress[i];
		}

		 sort(&adress[0], &adress[adress.size() - 1] + 1);
		// sort(adress.begin(), adress.end());


		 int myHouse = adress[adress.size() / 2];

		 int result = 0;

		 for (int i = 0; i < adress.size(); i++)
			 result += myHouse - adress[i] > 0 ? myHouse - adress[i] : adress[i] - myHouse;

		 cout << result << endl;

	}
	return 0;
}