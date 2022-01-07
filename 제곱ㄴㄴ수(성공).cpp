#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// 최대값 이하의 소수 제곱수 벡터 형성해서 리턴.
// 문제 조건 상 100만까지만 보면 된다.
vector<long long> createPrimeSq(const long long &max)
{
	// max의 제곱근을 대충 구하려고 노력하기 : 이진탐색
	// 근데 인덱스 터지는건 싫으니까 밑에부터 올라가면서, 넘어가면 거기부터 이진탐색.
	long long sqrt_max = 1;
	while (sqrt_max * sqrt_max < max) sqrt_max *= 2;

	// 이제 최대한 찾아본다. 이진탐색 돌리면 된다.
	if (sqrt_max * sqrt_max == max);	// 같으면 그냥 그거 쓰면 된다. 운도 좋다.
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
	
	// 제곱근(혹은 그에 근접한) 값으로 벡터 초기화. 특성상 0, 1은 안쓴다.
	vector<bool> primeBool((int)sqrt_max + 2);
	vector<long long> result;
	fill(primeBool.begin(), primeBool.end(), true);
	primeBool[0] = false;
	primeBool[1] = false;

	// primeBool을 체로 거른다.
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

	// primeBool이 true인 i값만 제곱해서 result에 넣는다.
	for (int i = 0; i < primeBool.size(); i++)
	{
		if (primeBool[i] == true) result.push_back((long long)i * (long long)i);
	}

	// 끝에 max 넘겨서 들어가는 값은 제거.
	for (int i = result.size() - 1; i != 0; i--)
	{
		if (result[i] > max) result.pop_back();
		else break;
	}
	return result;
}

// 다시.
/*
* 솔루션 : long long을 이용하고, 체를 구성한다.
* 체를 구성하는 쪽이 알고리즘 시간상 이득인 것 같다.
*/
int main(void)
{
	long long min, max;
	cin >> min >> max;
	int result = (int)(max - min + 1);	// 이 차이만큼 벡터 초기형성
	vector<bool> table(result);
	fill(table.begin(), table.end(), true);

	// 소수 제곱수 벡터 구하기
	vector<long long> primeSq = createPrimeSq(max);



	// 제곱ㄴㄴ수 체 형성
	for (int i = 0; i < primeSq.size(); i++)
	{
		// 소수 제곱수의 배수를 만족하는 최소값(인덱스) 구하기
		long long leastNum;
		if (min % primeSq[i] == 0) leastNum = 0;
		else leastNum = primeSq[i] - (min % primeSq[i]);
		if (leastNum > max - min + 1) continue;

		// 거르기
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