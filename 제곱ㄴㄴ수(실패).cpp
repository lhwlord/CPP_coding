#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 큰 수 연산을 위한 전용 객체 만들기. 양수, 음수 모두 처리할 수 있도록 해본다?
// 해당하는 연산은 객체 내부에서 끝낼 수 있도록 한다.
// 객체 연습용.
// 같은 객체형 인스턴스끼리는 인자로 받았을 때 해당 객체의 private 필드에 접근이 가능한가보다.
// 연산자 오버로딩으로 시작했어야 했는데, 이미 늦었다.
class big
{
private:	// 내부동작이 아닌 한, 바깥에서 건드려서 좋을 게 없는 변수 & 일부 함수들
	vector<int> bigNum;	// 큰수 처리용 메인변수
	bool minus;	// 음수인지 판별하는 불값

	// 앞자리의 0을 제거해준다. 단 값 자체가 0인 경우는 마지막 하나를 살린다. 추가로 아예 0인 경우 부호는 양수로 통일 시도.
	void removeZero()
	{
		if (bigNum.size() == 0)
		{
			bigNum.push_back(0); minus = false; return;
		}
		while (bigNum.size() != 0 && bigNum[0] == 0) bigNum.erase(bigNum.begin());
		if (bigNum.size() == 0) { bigNum.push_back(0); minus = false; }
	}

	// 큰 수 데시멀 좌측쉬프트.
	void x10(int n)
	{
		for (int i = 0; i < n; i++) bigNum.push_back(0);
		removeZero();
	}

	// 큰 수 10으로 나누기. 큰수벡터가 담긴 벡터를 반환한다. 몫 , 나머지.
	// 나누려는 수가 큰 수의 자릿수보다 같거나 큰 경우의 예외처리가 필요하다.
	// 주의사항 : 얘는 나누기 메소드가 아니라, 곱하기 도중에 들어가는 분리 기능 구현한거다.
	vector<vector<int>> split(vector<int> numArr, int n)
	{
		vector<vector<int>> result;

		if (numArr.size() <= n)	// 나누는 수가 같거나 크면 자릿수 전체가 나머지로 드간다.
		{
			result.push_back({ 0 });
			result.push_back(numArr);
		}
		else if (n == 0) // 나누는 수가 아예 없으면 몫에 몰빵이지만, 쓸 일은 없을 것.
		{
			result.push_back(numArr);
			result.push_back({ 0 });
		}
		else // 적당히 나누기.
		{
			result.push_back({});
			for (int i = 0; i < numArr.size() - n; i++)
			{
				result[0].push_back(numArr[i]);
			}
			numArr.erase(numArr.begin(), numArr.end() - n);	// 문제생기나 주시할 것
			numArr.shrink_to_fit();
			result.push_back(numArr);
		}

		return result;
	}

	// 곱하기 메소드의 알맹이. bigNum만 떼다가 계산한다.
	vector<int> mult_inner(vector<int> a, vector<int> b)
	{
		// 앞자리의 0을 제거하는 과정부터 진행해야 함
		while (a.size() > 0 && a[0] == 0) a.erase(a.begin());
		while (b.size() > 0 && b[0] == 0) b.erase(b.begin());
		if (a.size() == 0) a.push_back(0);
		if (b.size() == 0) b.push_back(0);

		int max_pos = a.size() > b.size() ? a.size() : b.size();
		if ((a.size() == 1 && a[0] == 0) || (b.size() == 1 && b[0] == 0))
		{
			return { 0 };
		}
		else if (max_pos < 5) // 통상 곱하기
		{
			string str_a = "", str_b = "";
			for (int i = 0; i < a.size(); i++)
			{
				str_a += a[i] + '0';
			}
			for (int i = 0; i < b.size(); i++)
			{
				str_b += b[i] + '0';
			}
			big temp(stoi(str_a) * stoi(str_b));
			return temp.bigNum;
		}
		else // 본격적인 시행
		{
			int m = max_pos / 2;
			vector<vector<int>> first_table = split(a, m);
			vector<int> x = first_table[0], y = first_table[1];
			first_table = split(b, m);
			vector<int> w = first_table[0], z = first_table[1];

			// x와 y를 더하고, w와 z를 더한다. 따로 객체 만들어서 해야 할 듯.
			big temp_x(x), temp_y(y); temp_x.plus(temp_y);
			big temp_w(w), temp_z(z); temp_w.plus(temp_z);

			// r, p, q를 각각 재귀로 구한다.
			vector<int> r = mult_inner(temp_x.bigNum, temp_w.bigNum);
			vector<int> p = mult_inner(x, w);
			vector<int> q = mult_inner(y, z);

			// 최종적으로 r, p, q를 갖다가 적절히 주물러서 리턴.
			big temp_r(r), temp_p(p), temp_q(q);
			big temp_result_1(p), temp_result_2(r), temp_result_3(q);

			temp_result_1.x10(2 * m);

			temp_p.minus = true;
			temp_q.minus = true;
			temp_result_2.plus(temp_p);
			temp_result_2.plus(temp_q);
			temp_result_2.x10(m);

			temp_result_1.plus(temp_result_2);
			temp_result_1.plus(temp_result_3);

			return temp_result_1.bigNum;
		}
	}

public:

	big() { bigNum.push_back(0); this->minus = false; }

	// num 인자로 받는 생성자. 음수도 처리할 수 있도록.
	big(int num)
	{
		if (num < 0)
		{
			minus = true;
			num = abs(num);
		}
		else minus = false;
		while (num != 0)
		{
			bigNum.insert(bigNum.begin(), num % 10);
			num /= 10;
		}
		removeZero();
	}
	
	// string 인자로 받는 생성자. 단, string 안에는 숫자만 있어야 한다.
	big(string s)
	{
		if (s[0] == '-')
		{
			minus = true;
			s.erase(0, 1);	// 첫 값이 부호일 수 있으니 이를 예외처리
		}
		else minus = false;
		try // string 안에 숫자만 있는지 체크. 숫자 이외의 값이 들어갔다면 걍 제낀다.
		{
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] < '0' || s[i] > '9') throw(s[i]);
				else bigNum.push_back(s[i] - '0');
			}
		}
		catch (char c)
		{
			cout << c << "이(가) 있기 때문에 큰 수를 string으로 초기화할 수 없습니다.\n";
		}
		removeZero();
	}	

	// 아예 객체를 받는 경우엔 복사생성자로 할당할 수 있도록.
	big(const big& other)
	{
		bigNum = other.bigNum;
		minus = other.minus;
		removeZero();
	}

	// 곱셈에서 벡터 덧셈을 위한 전용 생성자. 특성상 부호는 양수로 고정.
	big(vector<int> numArr)
	{
		bigNum = numArr;
	}

	// 스트링 형태로 벡터와 부호를 빼올 수 있도록.
	string toString()
	{
		string s = "";
		if (minus == true) s += '-';
		for (int i : bigNum) s += i + '0';
		return s;
	}

	// 인자로 다른 큰수를 받아다가, 여기에 더한다.
	// 빼는 것도 그냥 여기다가 바로 구현할 수 있어보인다. other에 음수가 들어가있으면 되니까.
	// 덧셈연산을 위해 제로확장을 많이 해놨으므로 this, other 둘 다 마지막에 0 빼줄 것.
	void plus(big other)	
	{
		// 자릿수가 10억, 즉 10자리 밑이라면 stoi 처리해서 바로 연산시키는 것이 좋아보인다.
		if (bigNum.size() <= 9 && other.bigNum.size() <= 9)
		{
			big temp(stoi(this->toString()) + stoi(other.toString()));
			bigNum = temp.bigNum;
			removeZero();
			return;
		}

		// 둘의 자릿수 크기가 다르다면 크기부터 통일시킨다 : 제로확장.
		if (this->bigNum.size() != other.bigNum.size())
		{
			big* p = this->bigNum.size() < other.bigNum.size() ? this : &other; // 작은놈판별
			big* q = p == this ? &other : this;
			for (int i = p->bigNum.size(); i < q->bigNum.size(); i++)
			{
				p->bigNum.insert(p->bigNum.begin(), 0);
			}
		}

		// 덧셈을 위한 추가 제로확장 1회씩.
		bigNum.insert(bigNum.begin(), 0);
		other.bigNum.insert(other.bigNum.begin(), 0);

		// 같은 부호라면 바로 더하면 된다.
		if (this->minus == other.minus)
		{
			for (int i = bigNum.size() - 1; i != -1; i--)
			{
				bigNum[i] += other.bigNum[i];
				if (bigNum[i] > 9)
				{
					bigNum[i - 1]++;
					bigNum[i] %= 10;
				}	// 어차피 추가 제로확장 했으니 MSB가 터질 걱정은 안해도 된다.
			}
		}
		// 다른 부호라면, 큰 쪽에서 작은 쪽을 빼고 큰 쪽의 부호를 따라간다.
		else
		{
			if (this->isBiggerThan(other) == 0) // 아예 같으면 벡터 0으로 처리
			{
				this->bigNum.clear();
				vector<int>().swap(this->bigNum);
				this->bigNum.push_back(0);
			}
			else if (this->isBiggerThan(other) == 1) // 내가 더 큰 경우.
			{
				for (int i = this->bigNum.size() - 1; i != 0; i--)
				{
					this->bigNum[i] -= other.bigNum[i];
					if (this->bigNum[i] < 0)
					{
						this->bigNum[i - 1]--;
						this->bigNum[i] = abs(this->bigNum[i]);
					} // 어차피 내가 더 커서 MSB가 터질 걱정은 안해도 된다.
				}
			}
			else // 내가 더 작은 경우 : 임시객체 받아다가 연산수행.
			{
				this->minus = other.minus;

				big c(other);

				for (int i = this->bigNum.size() - 1; i != 0; i--)
				{
					bigNum[i] = c.bigNum[i] - bigNum[i];
					if (bigNum[i] < 0)
					{
						c.bigNum[i - 1]--;
						bigNum[i] = abs(bigNum[i]);
					}	// 어차피 c쪽이 더 커서 MSB가 터질 걱정은 안해도 된다.
				}
			}
		}

		// 앞자리의 불필요한 0들을 제거한다.
		removeZero();
		other.removeZero();
	}

	// 다른 큰수 받아다가 곱한다.
	// 이 경우도 적당히 작으면 stoi 해서 가져온다.
	void mult(big other)
	{
		// 부호처리
		if (minus == true && other.minus == true) minus = false;
		else if (minus == false && other.minus == false);
		else minus = true;

		// 값 처리
		bigNum = mult_inner(bigNum, other.bigNum);
		removeZero();
	}

	// 다른 큰수 받아다가 나눈다. 몫, 나머지를 벡터에 담아 반환.
	// 주의사항 : 얘는 객체에 곧바로 적용하지 않는다. 따라서 적용 시 적절한 대입이 필요하다.
	vector<big> divide(big a)
	{
		big div = *this;	// 이걸로 대신 계산하도록 한다. 겸사겸사 나머지도 연산하도록.
		vector<big> share;	// 피제수를 키워나가며 여기에 잠시 저장한다.
		big sharePoint(0);	// 몫을 계산하기 위한 큰 수.
		big shareStack(1);	// 얘는 위의 sharePoint에 더하기 위해 쓴다.
		vector<big> shareLog;	// 셰어스택의 증가분 로그를 여기에 담고, 셰어포인트에 적용.
		big temp;
		vector<big> result;
		result.push_back(temp);	// 0번 인덱스 : 몫
		result.push_back(temp);	// 1번 인덱스 : 나머지

		// 음수처리.나머지는 피제수 부호 따라가고, 몫은 부호 다르면 음수로.
		result[0].minus = this->minus != a.minus ? true : false;
		result[1].minus = this->minus;

		// 연산에 사용할 객체들은 편의를 위해 전부 양수화. 어차피 반환형 부호는 살아있다.
		a.minus = false;
		div.minus = false;

		// 특이한 나누기에 대한 예외처리들 : 나누는 수가 0, 1이거나
		if (a.bigNum.size() == 1 && a.bigNum[0] == 0)
		{
			cout << "0으로 못나눕니다. 동작이 실행되지 않습니다.\n";
			return result;
		}
		else if (a.bigNum.size() == 1 && a.bigNum[0] == 1)
		{
			result[0].bigNum = this->bigNum;
			result[1].minus = false;
			return result;
		}

		share.push_back(a);	// 이제 이걸 이용해서 뺄 것이다.
		shareLog.push_back(shareStack);

		// 나누는 수를 2배씩 올리면서 피제수보다 커지는지 확인한다. 
		while (div.isBiggerThan(a) == 1)
		{
			a.mult(big(2));
			share.push_back(a);	// 뺄 수들을 share에 넣는다.
			shareStack.mult(big(2));
			shareLog.push_back(shareStack);	// 셰어스택은 나누는 수가 커질 때마다 같이 커지면서, 자신 또한 셰어로그에 들어간다.
		}

		// 같거나 커졌다면, 이제 다시 내려온다.
		while (share.size() != 0)
		{
			if (share[share.size() - 1].isBiggerThan(div) != 1)
			{
				share[share.size() - 1].minus = true;	// 빼기 위한 밑작업
				div.plus(share[share.size() - 1]);	// 피제수에서 뺄 수 있는 해당 수 빼기
				sharePoint.plus(shareLog[shareLog.size() - 1]);	// 몫은 해당 스택만큼 더하기
			}
			// 동작여부와 무관하게 스택은 한번 판단된 후 무조건 한번씩 팝되어야 함
			share.pop_back();
			shareLog.pop_back();
		}

		// 셰어포인트에 몫이 쌓였고, div는 나머지가 되었다.
		result[0].bigNum = sharePoint.bigNum;
		result[1].bigNum = div.bigNum;

		return result;
	}

	// 나와 대상의 상대적인 크기를 반환한다. 내가 더 크면 1, 상대가 더 크면 -1, 같은 값이면 0.
	int isBiggerThan(const big& other)
	{
		// 자릿수 차이나면 차이나는 대로 리턴
		if (this->bigNum.size() < other.bigNum.size()) return -1;
		else if (this->bigNum.size() > other.bigNum.size()) return 1;
		// 자릿수가 같다면 이제부터 큰 쪽 순서대로 비교
		else
		{
			for (int i = 0; i < this->bigNum.size(); i++)
			{
				if (this->bigNum[i] < other.bigNum[i]) return -1;
				else if (this->bigNum[i] > other.bigNum[i]) return 1;
			}
		}
		// 마지막까지 빠져나왔다는 것은 둘이 같다는 것으로, 크지 않으므로 0 리턴
		return 0;
	}

	// 부호를 변경한다. '-' 면 음수로, '+' 면 양수로, '*'면 부호 뒤집기.
	void changeSign(char c)
	{
		switch (c)
		{
		case '-' : 
			minus = true;
			break;
		case '+' : 
			minus = false;
			break;
		case '*' : 
			minus = !minus;
			break;
		default :
			cout << "입력오류. 객체의 부호를 변경할 수 없습니다.\n";
			break;
		}
	}
};

// 소수를 찾아 제곱하고, 그 수가 지정된 최대수(객체)보다 작은 한 배열에 넣고 완료 시 반환.
vector<big> findPrimeAndSquare(big upperLimit)
{
	vector<big> result;
	vector<int> primeArr;
	
	// 2부터 시작해서 100만까지 돌면서, 체를 걸러 소수를 찾아낸다.
	for (int i = 2; i < 1000000; i++)
	{
		bool check = true;
		for (int j = 0; j < primeArr.size(); j++)
		{
			if (i % primeArr[j] == 0)
			{
				check = false;
				break;
			}
		}

		// 소수임이 판정났다면 소수벡터에 넣고, 큰 수로 제곱해서 상한에 포함되는지 확인.
		if (check)
		{
			primeArr.push_back(i);
			big temp(i);
			temp.mult(temp);
			if (temp.isBiggerThan(upperLimit) != 1)
			{
				// 상한에 포함된다면 결과벡터에 넣고, 아니면 거기서 멈추고 리턴.
				result.push_back(temp);
			}
			else return result;
		}

	}
	return result;
}

// 지정된 범위 내에서 제곱ㄴㄴ수를 찾는다.
/*
* 솔루션 : 길다. 메모장 참고할 것
* 비고 : long long int가 100조 단위까지도 계산할 수 있었다. 본 코드는 나중에 큰 수 계산용으로 남기고, 일단 폐기.
*/
int main(void)
{
	// 범위를 큰 수로 입력받는다.
	string s_min, s_max;
	cin >> s_min >> s_max;
	big min(s_min), max(s_max);

	// 지정한 최대범위까지만 소수의 제곱수를 찾는다.
	vector<big> primeSq = findPrimeAndSquare(max);

	// 소수 제곱수 배열을 순회하며 제곱ㄴㄴ수의 개수를 찾는다.
	// 아래 문단은 범위 내의 개수를 파악하는 과정. 범위는 최대 100만이므로 마지막에 int로 변환.
	big total = max;
	min.changeSign('*');
	total.plus(min);
	min.changeSign('*');
	total.plus(big(1));
	int gap = stoi(total.toString());
	int sqrNoNoCount = 0;
	
	// 좌절된 시도.
	/*
	for (int i = 0; i < primeSq.size(); i++)
	{
		// 제곱수의 범위에 알맞는 신규 최대/최소 구하기
		big newMin(min), newMax(max), minTemp = min.divide(primeSq[i])[1], temp = max.divide(primeSq[i])[1];
		minTemp.changeSign('*');
		big minTemp_receive(primeSq[i]);
		minTemp_receive.plus(minTemp);
		newMin.plus(minTemp_receive);
		temp.changeSign('*');
		newMax.plus(temp);

		// 범위 예외처리
		if (newMin.isBiggerThan(newMax) == 1) break;
		else if (newMin.isBiggerThan(newMax) == 0)
		{
			total.plus(-1); break;
		}

		// 하나의 소수제곱수마다 차지하는 범위연산 : 현재 틀림
		newMin.changeSign('*');
		newMax.plus(newMin);
		newMax = newMax.divide(primeSq[i])[0];
		newMax.plus(big(1));
		newMax.changeSign('*');
		total.plus(newMax);
		
	}*/

	// 배열을 하나씩 도는 수가 차라리 매력적인 제안으로 보인다.
	// 연산용 큰수는 min에서 시작해서 하나씩 늘리는 걸로. * min 훼손됨 *
	for (int i = 0; i < gap; i++)
	{
		bool sqrNoNoCheck = true;
		for (int j = 0; j < primeSq.size(); j++)
		{
			if (min.isBiggerThan(primeSq[j]) == -1) break;	// 벡터삽입은 부호가 없지만, 당장의 코드는 양수만 들어오므로 이렇게 구현하도록 한다.
			else if(min.divide(primeSq[j])[1].isBiggerThan(big(0)) == 0)
			{
				sqrNoNoCheck = false; break;
			}
		}
		if (sqrNoNoCheck) sqrNoNoCount++;
		min.plus(big(1));
	}


	// cout << "범위 내의 제곱ㄴㄴ수는 " << total.toString() << "개.\n";

	cout << "범위 내의 제곱ㄴㄴ수는 " << sqrNoNoCount << "개.\n";

	return 0;
}