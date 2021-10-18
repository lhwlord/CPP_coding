#include <iostream>

using namespace std;

class Calc {
private: int m_Value = 0;
public:
	Calc* Add(int value) { m_Value += value; return this; }	// 객체의 주소값을 포인터로 반환, 이거 받는 다른 객체는 이거 불러온 객체를 참조하는 포인터 변수임
	Calc& Sub(int value) { m_Value -= value; return *this; } // 객체 자체를 참조로 반환, 이거 받는 다른 객체는 이거 불러온 객체와 동일하게 취급됨
	Calc Mul(int value) { m_Value *= value; return *this; }		// 객체 자체를 임시로 복사해서 반환(새로운 객체를 반환하는 것이므로 체인 액션 불가, 이 객체를 쓸 일이 없어진다면 메모리 낭비하는 꼴. move() 를 써야 메모리를 아낄 수 있음)

	Calc&& Des(int value) { m_Value == 999;  return move(*this); }	// 객체 자체를 r값으로 설정하여 시한부로 만들었지만, 대신 반환할 때도 우측참조이므로 값은 계속 살고 임시객체로 복사할 필요도 없어진다.
	int GetValue() { return m_Value; }
};

int main() {
	Calc calc;
	//calc.Add(5).Sub(3).Mul(4); 

	Calc&& a = move(calc.Add(5)->Sub(3).Mul(4).Mul(5));	// 3째 Mul의 반환값은 객체인데, 우측값으로 '복사' 되어 새로 튀어나왔기 때문에, 그 복사된 값에 대해 Mul을 수행하는 것이므로, 4째 Mul은 새로운 객체에 대고 연산을 수행한다.
	// 이걸 담기 위해서 a를 만든다. 이 경우 Mul 함수에서 Calc 형을 반환하기 위해 한번 복사되고, a에 담기 위해 또 한번 복사된다. 
	// 2번째 복사를 막기 위해 move를 쓰고 a를 우측참조로 설정했다. 이러면 a는 복사된 임시객체로 가게 된다.

	cout << &calc << endl;
	cout << &a << endl;


	cout << calc.GetValue() << endl;
	cout << a.GetValue() << endl;
	return 0;
}
