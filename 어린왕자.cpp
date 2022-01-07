#include <iostream>
#include <vector>

using namespace std;

// x,y�� ���� �ش� ��ġ�� ������ ��� �ȿ� ���ԵǴ°�?
// �Ÿ��� ����� ����ص� ������, ��ǥ�Ÿ� ���ϴ� ���� �� ���� ���·� ���ص� �ȴ�.
// �����ε� : ����迭 0�� : x, 1�� : y, 2�� : ������
bool checkInside(vector<int> star, int x, int y)
{
	int starRadius = star[2] * star[2];
	int distance = (abs(star[0] - x) * abs(star[0] - x)) + (abs(star[1] - y) * abs(star[1] - y));

	return starRadius > distance;	// ���� ���� �� ��ġ�� ���� ������ �ʴ´�.
}


// ��������� ���������� ���� ��� �� ���� ��踦 �ּҷ� ������ ����� ��� ��� �� ���ϱ�
/*
* �ַ�� : ���۰� ���� ���� ���� ���� �߾Ӱ��� �Ÿ��� ���� �������� �Ÿ� ���, �ش� ���� ���� ��� �ȿ� ������ ī��Ʈ 1 ����.
* ��, �� ���� �ȿ� ����/���� ��� ������ ī��Ʈ ����.
*/
int main(void)
{
	int caseNum;
	cin >> caseNum;
	for (int case_i = 0; case_i < caseNum; case_i++)
	{
		int start_x, start_y, end_x, end_y, starNum;
		cin >> start_x >> start_y >> end_x >> end_y;
		cin >> starNum;
		vector<vector<int>> starArr;	// ���� ���� ����
		
		// �� ���� ��ġ�� ������ �ֱ�
		for (int star_i = 0; star_i < starNum; star_i++)
		{
			int temp_x, temp_y, temp_radius;
			cin >> temp_x >> temp_y >> temp_radius;
			vector<int> tempArr;
			tempArr.push_back(temp_x);
			tempArr.push_back(temp_y);
			tempArr.push_back(temp_radius);
			starArr.push_back(tempArr);
		}

		// ���� ������, ����/������ �ȿ� �ֳ� Ȯ���ϰ� ��Ȳ�� �°� ī��Ʈ ����
		int count = 0;
		for (int i = 0; i < starNum; i++)
		{
			if (checkInside(starArr[i], start_x, start_y) != checkInside(starArr[i], end_x, end_y))
				count++;
		}
		cout << count << endl;
	}
	return 0;
}