#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// �ִ밪 ������ �Ҽ� ������ ���� �����ؼ� ����.
// ���� ���� �� 100�������� ���� �ȴ�.
vector<long long> createPrimeSq(const long long &max)
{
	// max�� �������� ���� ���Ϸ��� ����ϱ� : ����Ž��
	// �ٵ� �ε��� �����°� �����ϱ� �ؿ����� �ö󰡸鼭, �Ѿ�� �ű���� ����Ž��.
	long long sqrt_max = 1;
	while (sqrt_max * sqrt_max < max) sqrt_max *= 2;

	// ���� �ִ��� ã�ƺ���. ����Ž�� ������ �ȴ�.
	if (sqrt_max * sqrt_max == max);	// ������ �׳� �װ� ���� �ȴ�. � ����.
	else
	{
		long long s_min = sqrt_max / 2, s_max = sqrt_max;
		while (s_min <= s_max)
		{
			sqrt_max = s_min + ((s_max - s_min) / 2);
			long long temp = sqrt_max * sqrt_max;
			if (temp == max) break;
			else if (temp > max)
				s_max = sqrt_max - 1;
			else // temp < max
				s_min = sqrt_max + 1;
		}
	}
	
	// ������(Ȥ�� �׿� ������) ������ ���� �ʱ�ȭ. Ư���� 0, 1�� �Ⱦ���.
	vector<bool> primeBool((int)sqrt_max + 2);
	vector<long long> result;
	fill(primeBool.begin(), primeBool.end(), true);
	primeBool[0] = false;
	primeBool[1] = false;

	// primeBool�� ü�� �Ÿ���.
	for (int i = 2; i < primeBool.size() / 2; i++)
	{
		if (primeBool[i] != false)
		{
			for (int j = 2 * i; j < primeBool.size() - 1; j += i)
			{
				primeBool[j] = false;
			}
		}
	}

	// primeBool�� true�� i���� �����ؼ� result�� �ִ´�.
	for (int i = 0; i < primeBool.size(); i++)
	{
		if (primeBool[i] == true) result.push_back((long long)i * (long long)i);
	}

	// ���� max �Ѱܼ� ���� ���� ����.
	for (int i = result.size() - 1; i != 0; i--)
	{
		if (result[i] > max) result.pop_back();
		else break;
	}
	return result;
}

// �ٽ�.
/*
* �ַ�� : long long�� �̿��ϰ�, ü�� �����Ѵ�.
* ü�� �����ϴ� ���� �˰��� �ð��� �̵��� �� ����.
*/
int main(void)
{
	long long min, max;
	cin >> min >> max;
	int result = (int)(max - min + 1);	// �� ���̸�ŭ ���� �ʱ�����
	vector<bool> table(result);
	fill(table.begin(), table.end(), true);

	// �Ҽ� ������ ���� ���ϱ�
	vector<long long> primeSq = createPrimeSq(max);



	// ���������� ü ����
	for (int i = 0; i < primeSq.size(); i++)
	{
		// �Ҽ� �������� ����� �����ϴ� �ּҰ�(�ε���) ���ϱ�
		long long leastNum;
		if (min % primeSq[i] == 0) leastNum = 0;
		else leastNum = primeSq[i] - (min % primeSq[i]);
		if (leastNum > max - min + 1) continue;

		// �Ÿ���
		for (long long j = leastNum; j <= table.size() - 1; j += primeSq[i])
		{
			if (table[(int)j] == true)
			{
				table[(int)j] = false;
				result--;
			}
		}
	}

	cout << result << endl;

	return 0;

}