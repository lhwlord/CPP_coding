#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// ū �� ������ ���� ���� ��ü �����. ���, ���� ��� ó���� �� �ֵ��� �غ���?
// �ش��ϴ� ������ ��ü ���ο��� ���� �� �ֵ��� �Ѵ�.
// ��ü ������.
// ���� ��ü�� �ν��Ͻ������� ���ڷ� �޾��� �� �ش� ��ü�� private �ʵ忡 ������ �����Ѱ�����.
// ������ �����ε����� �����߾�� �ߴµ�, �̹� �ʾ���.
class big
{
private:	// ���ε����� �ƴ� ��, �ٱ����� �ǵ���� ���� �� ���� ���� & �Ϻ� �Լ���
	vector<int> bigNum;	// ū�� ó���� ���κ���
	bool minus;	// �������� �Ǻ��ϴ� �Ұ�

	// ���ڸ��� 0�� �������ش�. �� �� ��ü�� 0�� ���� ������ �ϳ��� �츰��. �߰��� �ƿ� 0�� ��� ��ȣ�� ����� ���� �õ�.
	void removeZero()
	{
		if (bigNum.size() == 0)
		{
			bigNum.push_back(0); minus = false; return;
		}
		while (bigNum.size() != 0 && bigNum[0] == 0) bigNum.erase(bigNum.begin());
		if (bigNum.size() == 0) { bigNum.push_back(0); minus = false; }
	}

	// ū �� ���ø� ��������Ʈ.
	void x10(int n)
	{
		for (int i = 0; i < n; i++) bigNum.push_back(0);
		removeZero();
	}

	// ū �� 10���� ������. ū�����Ͱ� ��� ���͸� ��ȯ�Ѵ�. �� , ������.
	// �������� ���� ū ���� �ڸ������� ���ų� ū ����� ����ó���� �ʿ��ϴ�.
	// ���ǻ��� : ��� ������ �޼ҵ尡 �ƴ϶�, ���ϱ� ���߿� ���� �и� ��� �����ѰŴ�.
	vector<vector<int>> split(vector<int> numArr, int n)
	{
		vector<vector<int>> result;

		if (numArr.size() <= n)	// ������ ���� ���ų� ũ�� �ڸ��� ��ü�� �������� �尣��.
		{
			result.push_back({ 0 });
			result.push_back(numArr);
		}
		else if (n == 0) // ������ ���� �ƿ� ������ �� ����������, �� ���� ���� ��.
		{
			result.push_back(numArr);
			result.push_back({ 0 });
		}
		else // ������ ������.
		{
			result.push_back({});
			for (int i = 0; i < numArr.size() - n; i++)
			{
				result[0].push_back(numArr[i]);
			}
			numArr.erase(numArr.begin(), numArr.end() - n);	// �������⳪ �ֽ��� ��
			numArr.shrink_to_fit();
			result.push_back(numArr);
		}

		return result;
	}

	// ���ϱ� �޼ҵ��� �˸���. bigNum�� ���ٰ� ����Ѵ�.
	vector<int> mult_inner(vector<int> a, vector<int> b)
	{
		// ���ڸ��� 0�� �����ϴ� �������� �����ؾ� ��
		while (a.size() > 0 && a[0] == 0) a.erase(a.begin());
		while (b.size() > 0 && b[0] == 0) b.erase(b.begin());
		if (a.size() == 0) a.push_back(0);
		if (b.size() == 0) b.push_back(0);

		int max_pos = a.size() > b.size() ? a.size() : b.size();
		if ((a.size() == 1 && a[0] == 0) || (b.size() == 1 && b[0] == 0))
		{
			return { 0 };
		}
		else if (max_pos < 5) // ��� ���ϱ�
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
		else // �������� ����
		{
			int m = max_pos / 2;
			vector<vector<int>> first_table = split(a, m);
			vector<int> x = first_table[0], y = first_table[1];
			first_table = split(b, m);
			vector<int> w = first_table[0], z = first_table[1];

			// x�� y�� ���ϰ�, w�� z�� ���Ѵ�. ���� ��ü ���� �ؾ� �� ��.
			big temp_x(x), temp_y(y); temp_x.plus(temp_y);
			big temp_w(w), temp_z(z); temp_w.plus(temp_z);

			// r, p, q�� ���� ��ͷ� ���Ѵ�.
			vector<int> r = mult_inner(temp_x.bigNum, temp_w.bigNum);
			vector<int> p = mult_inner(x, w);
			vector<int> q = mult_inner(y, z);

			// ���������� r, p, q�� ���ٰ� ������ �ֹ����� ����.
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

	// num ���ڷ� �޴� ������. ������ ó���� �� �ֵ���.
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
	
	// string ���ڷ� �޴� ������. ��, string �ȿ��� ���ڸ� �־�� �Ѵ�.
	big(string s)
	{
		if (s[0] == '-')
		{
			minus = true;
			s.erase(0, 1);	// ù ���� ��ȣ�� �� ������ �̸� ����ó��
		}
		else minus = false;
		try // string �ȿ� ���ڸ� �ִ��� üũ. ���� �̿��� ���� ���ٸ� �� ������.
		{
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] < '0' || s[i] > '9') throw(s[i]);
				else bigNum.push_back(s[i] - '0');
			}
		}
		catch (char c)
		{
			cout << c << "��(��) �ֱ� ������ ū ���� string���� �ʱ�ȭ�� �� �����ϴ�.\n";
		}
		removeZero();
	}	

	// �ƿ� ��ü�� �޴� ��쿣 ��������ڷ� �Ҵ��� �� �ֵ���.
	big(const big& other)
	{
		bigNum = other.bigNum;
		minus = other.minus;
		removeZero();
	}

	// �������� ���� ������ ���� ���� ������. Ư���� ��ȣ�� ����� ����.
	big(vector<int> numArr)
	{
		bigNum = numArr;
	}

	// ��Ʈ�� ���·� ���Ϳ� ��ȣ�� ���� �� �ֵ���.
	string toString()
	{
		string s = "";
		if (minus == true) s += '-';
		for (int i : bigNum) s += i + '0';
		return s;
	}

	// ���ڷ� �ٸ� ū���� �޾ƴٰ�, ���⿡ ���Ѵ�.
	// ���� �͵� �׳� ����ٰ� �ٷ� ������ �� �־�δ�. other�� ������ �������� �Ǵϱ�.
	// ���������� ���� ����Ȯ���� ���� �س����Ƿ� this, other �� �� �������� 0 ���� ��.
	void plus(big other)	
	{
		// �ڸ����� 10��, �� 10�ڸ� ���̶�� stoi ó���ؼ� �ٷ� �����Ű�� ���� ���ƺ��δ�.
		if (bigNum.size() <= 9 && other.bigNum.size() <= 9)
		{
			big temp(stoi(this->toString()) + stoi(other.toString()));
			bigNum = temp.bigNum;
			removeZero();
			return;
		}

		// ���� �ڸ��� ũ�Ⱑ �ٸ��ٸ� ũ����� ���Ͻ�Ų�� : ����Ȯ��.
		if (this->bigNum.size() != other.bigNum.size())
		{
			big* p = this->bigNum.size() < other.bigNum.size() ? this : &other; // �������Ǻ�
			big* q = p == this ? &other : this;
			for (int i = p->bigNum.size(); i < q->bigNum.size(); i++)
			{
				p->bigNum.insert(p->bigNum.begin(), 0);
			}
		}

		// ������ ���� �߰� ����Ȯ�� 1ȸ��.
		bigNum.insert(bigNum.begin(), 0);
		other.bigNum.insert(other.bigNum.begin(), 0);

		// ���� ��ȣ��� �ٷ� ���ϸ� �ȴ�.
		if (this->minus == other.minus)
		{
			for (int i = bigNum.size() - 1; i != -1; i--)
			{
				bigNum[i] += other.bigNum[i];
				if (bigNum[i] > 9)
				{
					bigNum[i - 1]++;
					bigNum[i] %= 10;
				}	// ������ �߰� ����Ȯ�� ������ MSB�� ���� ������ ���ص� �ȴ�.
			}
		}
		// �ٸ� ��ȣ���, ū �ʿ��� ���� ���� ���� ū ���� ��ȣ�� ���󰣴�.
		else
		{
			if (this->isBiggerThan(other) == 0) // �ƿ� ������ ���� 0���� ó��
			{
				this->bigNum.clear();
				vector<int>().swap(this->bigNum);
				this->bigNum.push_back(0);
			}
			else if (this->isBiggerThan(other) == 1) // ���� �� ū ���.
			{
				for (int i = this->bigNum.size() - 1; i != 0; i--)
				{
					this->bigNum[i] -= other.bigNum[i];
					if (this->bigNum[i] < 0)
					{
						this->bigNum[i - 1]--;
						this->bigNum[i] = abs(this->bigNum[i]);
					} // ������ ���� �� Ŀ�� MSB�� ���� ������ ���ص� �ȴ�.
				}
			}
			else // ���� �� ���� ��� : �ӽð�ü �޾ƴٰ� �������.
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
					}	// ������ c���� �� Ŀ�� MSB�� ���� ������ ���ص� �ȴ�.
				}
			}
		}

		// ���ڸ��� ���ʿ��� 0���� �����Ѵ�.
		removeZero();
		other.removeZero();
	}

	// �ٸ� ū�� �޾ƴٰ� ���Ѵ�.
	// �� ��쵵 ������ ������ stoi �ؼ� �����´�.
	void mult(big other)
	{
		// ��ȣó��
		if (minus == true && other.minus == true) minus = false;
		else if (minus == false && other.minus == false);
		else minus = true;

		// �� ó��
		bigNum = mult_inner(bigNum, other.bigNum);
		removeZero();
	}

	// �ٸ� ū�� �޾ƴٰ� ������. ��, �������� ���Ϳ� ��� ��ȯ.
	// ���ǻ��� : ��� ��ü�� ��ٷ� �������� �ʴ´�. ���� ���� �� ������ ������ �ʿ��ϴ�.
	vector<big> divide(big a)
	{
		big div = *this;	// �̰ɷ� ��� ����ϵ��� �Ѵ�. ����� �������� �����ϵ���.
		vector<big> share;	// �������� Ű�������� ���⿡ ��� �����Ѵ�.
		big sharePoint(0);	// ���� ����ϱ� ���� ū ��.
		big shareStack(1);	// ��� ���� sharePoint�� ���ϱ� ���� ����.
		vector<big> shareLog;	// �ξ���� ������ �α׸� ���⿡ ���, �ξ�����Ʈ�� ����.
		big temp;
		vector<big> result;
		result.push_back(temp);	// 0�� �ε��� : ��
		result.push_back(temp);	// 1�� �ε��� : ������

		// ����ó��.�������� ������ ��ȣ ���󰡰�, ���� ��ȣ �ٸ��� ������.
		result[0].minus = this->minus != a.minus ? true : false;
		result[1].minus = this->minus;

		// ���꿡 ����� ��ü���� ���Ǹ� ���� ���� ���ȭ. ������ ��ȯ�� ��ȣ�� ����ִ�.
		a.minus = false;
		div.minus = false;

		// Ư���� �����⿡ ���� ����ó���� : ������ ���� 0, 1�̰ų�
		if (a.bigNum.size() == 1 && a.bigNum[0] == 0)
		{
			cout << "0���� �������ϴ�. ������ ������� �ʽ��ϴ�.\n";
			return result;
		}
		else if (a.bigNum.size() == 1 && a.bigNum[0] == 1)
		{
			result[0].bigNum = this->bigNum;
			result[1].minus = false;
			return result;
		}

		share.push_back(a);	// ���� �̰� �̿��ؼ� �� ���̴�.
		shareLog.push_back(shareStack);

		// ������ ���� 2�辿 �ø��鼭 ���������� Ŀ������ Ȯ���Ѵ�. 
		while (div.isBiggerThan(a) == 1)
		{
			a.mult(big(2));
			share.push_back(a);	// �� ������ share�� �ִ´�.
			shareStack.mult(big(2));
			shareLog.push_back(shareStack);	// �ξ���� ������ ���� Ŀ�� ������ ���� Ŀ���鼭, �ڽ� ���� �ξ�α׿� ����.
		}

		// ���ų� Ŀ���ٸ�, ���� �ٽ� �����´�.
		while (share.size() != 0)
		{
			if (share[share.size() - 1].isBiggerThan(div) != 1)
			{
				share[share.size() - 1].minus = true;	// ���� ���� ���۾�
				div.plus(share[share.size() - 1]);	// ���������� �� �� �ִ� �ش� �� ����
				sharePoint.plus(shareLog[shareLog.size() - 1]);	// ���� �ش� ���ø�ŭ ���ϱ�
			}
			// ���ۿ��ο� �����ϰ� ������ �ѹ� �Ǵܵ� �� ������ �ѹ��� �˵Ǿ�� ��
			share.pop_back();
			shareLog.pop_back();
		}

		// �ξ�����Ʈ�� ���� �׿���, div�� �������� �Ǿ���.
		result[0].bigNum = sharePoint.bigNum;
		result[1].bigNum = div.bigNum;

		return result;
	}

	// ���� ����� ������� ũ�⸦ ��ȯ�Ѵ�. ���� �� ũ�� 1, ��밡 �� ũ�� -1, ���� ���̸� 0.
	int isBiggerThan(const big& other)
	{
		// �ڸ��� ���̳��� ���̳��� ��� ����
		if (this->bigNum.size() < other.bigNum.size()) return -1;
		else if (this->bigNum.size() > other.bigNum.size()) return 1;
		// �ڸ����� ���ٸ� �������� ū �� ������� ��
		else
		{
			for (int i = 0; i < this->bigNum.size(); i++)
			{
				if (this->bigNum[i] < other.bigNum[i]) return -1;
				else if (this->bigNum[i] > other.bigNum[i]) return 1;
			}
		}
		// ���������� �������Դٴ� ���� ���� ���ٴ� ������, ũ�� �����Ƿ� 0 ����
		return 0;
	}

	// ��ȣ�� �����Ѵ�. '-' �� ������, '+' �� �����, '*'�� ��ȣ ������.
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
			cout << "�Է¿���. ��ü�� ��ȣ�� ������ �� �����ϴ�.\n";
			break;
		}
	}
};

// �Ҽ��� ã�� �����ϰ�, �� ���� ������ �ִ��(��ü)���� ���� �� �迭�� �ְ� �Ϸ� �� ��ȯ.
vector<big> findPrimeAndSquare(big upperLimit)
{
	vector<big> result;
	vector<int> primeArr;
	
	// 2���� �����ؼ� 100������ ���鼭, ü�� �ɷ� �Ҽ��� ã�Ƴ���.
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

		// �Ҽ����� �������ٸ� �Ҽ����Ϳ� �ְ�, ū ���� �����ؼ� ���ѿ� ���ԵǴ��� Ȯ��.
		if (check)
		{
			primeArr.push_back(i);
			big temp(i);
			temp.mult(temp);
			if (temp.isBiggerThan(upperLimit) != 1)
			{
				// ���ѿ� ���Եȴٸ� ������Ϳ� �ְ�, �ƴϸ� �ű⼭ ���߰� ����.
				result.push_back(temp);
			}
			else return result;
		}

	}
	return result;
}

// ������ ���� ������ ������������ ã�´�.
/*
* �ַ�� : ���. �޸��� ������ ��
* ��� : long long int�� 100�� ���������� ����� �� �־���. �� �ڵ�� ���߿� ū �� �������� �����, �ϴ� ���.
*/
int main(void)
{
	// ������ ū ���� �Է¹޴´�.
	string s_min, s_max;
	cin >> s_min >> s_max;
	big min(s_min), max(s_max);

	// ������ �ִ���������� �Ҽ��� �������� ã�´�.
	vector<big> primeSq = findPrimeAndSquare(max);

	// �Ҽ� ������ �迭�� ��ȸ�ϸ� ������������ ������ ã�´�.
	// �Ʒ� ������ ���� ���� ������ �ľ��ϴ� ����. ������ �ִ� 100���̹Ƿ� �������� int�� ��ȯ.
	big total = max;
	min.changeSign('*');
	total.plus(min);
	min.changeSign('*');
	total.plus(big(1));
	int gap = stoi(total.toString());
	int sqrNoNoCount = 0;
	
	// ������ �õ�.
	/*
	for (int i = 0; i < primeSq.size(); i++)
	{
		// �������� ������ �˸´� �ű� �ִ�/�ּ� ���ϱ�
		big newMin(min), newMax(max), minTemp = min.divide(primeSq[i])[1], temp = max.divide(primeSq[i])[1];
		minTemp.changeSign('*');
		big minTemp_receive(primeSq[i]);
		minTemp_receive.plus(minTemp);
		newMin.plus(minTemp_receive);
		temp.changeSign('*');
		newMax.plus(temp);

		// ���� ����ó��
		if (newMin.isBiggerThan(newMax) == 1) break;
		else if (newMin.isBiggerThan(newMax) == 0)
		{
			total.plus(-1); break;
		}

		// �ϳ��� �Ҽ����������� �����ϴ� �������� : ���� Ʋ��
		newMin.changeSign('*');
		newMax.plus(newMin);
		newMax = newMax.divide(primeSq[i])[0];
		newMax.plus(big(1));
		newMax.changeSign('*');
		total.plus(newMax);
		
	}*/

	// �迭�� �ϳ��� ���� ���� ���� �ŷ����� �������� ���δ�.
	// ����� ū���� min���� �����ؼ� �ϳ��� �ø��� �ɷ�. * min �Ѽյ� *
	for (int i = 0; i < gap; i++)
	{
		bool sqrNoNoCheck = true;
		for (int j = 0; j < primeSq.size(); j++)
		{
			if (min.isBiggerThan(primeSq[j]) == -1) break;	// ���ͻ����� ��ȣ�� ������, ������ �ڵ�� ����� �����Ƿ� �̷��� �����ϵ��� �Ѵ�.
			else if(min.divide(primeSq[j])[1].isBiggerThan(big(0)) == 0)
			{
				sqrNoNoCheck = false; break;
			}
		}
		if (sqrNoNoCheck) sqrNoNoCount++;
		min.plus(big(1));
	}


	// cout << "���� ���� ������������ " << total.toString() << "��.\n";

	cout << "���� ���� ������������ " << sqrNoNoCount << "��.\n";

	return 0;
}