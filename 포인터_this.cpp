#include <iostream>

using namespace std;

class Calc {
private: int m_Value = 0;
public:
	Calc* Add(int value) { m_Value += value; return this; }	// ��ü�� �ּҰ��� �����ͷ� ��ȯ, �̰� �޴� �ٸ� ��ü�� �̰� �ҷ��� ��ü�� �����ϴ� ������ ������
	Calc& Sub(int value) { m_Value -= value; return *this; } // ��ü ��ü�� ������ ��ȯ, �̰� �޴� �ٸ� ��ü�� �̰� �ҷ��� ��ü�� �����ϰ� ��޵�
	Calc Mul(int value) { m_Value *= value; return *this; }		// ��ü ��ü�� �ӽ÷� �����ؼ� ��ȯ(���ο� ��ü�� ��ȯ�ϴ� ���̹Ƿ� ü�� �׼� �Ұ�, �� ��ü�� �� ���� �������ٸ� �޸� �����ϴ� ��. move() �� ��� �޸𸮸� �Ƴ� �� ����)

	Calc&& Des(int value) { m_Value == 999;  return move(*this); }	// ��ü ��ü�� r������ �����Ͽ� ���Ѻη� ���������, ��� ��ȯ�� ���� ���������̹Ƿ� ���� ��� ��� �ӽð�ü�� ������ �ʿ䵵 ��������.
	int GetValue() { return m_Value; }
};

int main() {
	Calc calc;
	//calc.Add(5).Sub(3).Mul(4); 

	Calc&& a = move(calc.Add(5)->Sub(3).Mul(4).Mul(5));	// 3° Mul�� ��ȯ���� ��ü�ε�, ���������� '����' �Ǿ� ���� Ƣ��Ա� ������, �� ����� ���� ���� Mul�� �����ϴ� ���̹Ƿ�, 4° Mul�� ���ο� ��ü�� ��� ������ �����Ѵ�.
	// �̰� ��� ���ؼ� a�� �����. �� ��� Mul �Լ����� Calc ���� ��ȯ�ϱ� ���� �ѹ� ����ǰ�, a�� ��� ���� �� �ѹ� ����ȴ�. 
	// 2��° ���縦 ���� ���� move�� ���� a�� ���������� �����ߴ�. �̷��� a�� ����� �ӽð�ü�� ���� �ȴ�.

	cout << &calc << endl;
	cout << &a << endl;


	cout << calc.GetValue() << endl;
	cout << a.GetValue() << endl;
	return 0;
}
