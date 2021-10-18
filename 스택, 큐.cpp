#include <iostream>
#include <stack>	// 스택 정의된 헤더
#include <queue>	// 큐 정의된 헤더

using namespace std;

int main(void)
{
	stack<int> S;	// int 쓰는 스택객체 생성. 자바와 다르게 C++은 객체 선언시 new 뭐시기 안해도 된다. 자바에서의 new 문법은 미리 상위객체를 선언해두고 나중에 구체화하는 느낌이라면, C++은 다중상속이 가능하므로 해당 타입을 처음부터 엄밀히 지정해야 하는듯.

	queue<int> Q;	// 역시 큐 객체 하나 생성.

	S.push(2);
	S.push(0);
	S.push(1);
	S.push(4);

	Q.push(2);
	Q.push(0);
	Q.push(1);
	Q.push(4);

	while (S.empty() == false)	// 스택은 마지막꺼부터 뺌. 상하관계
	{
		cout << S.top() << ", ";
		S.pop();
	}
	cout << endl;

	while (Q.empty() == false)	// 큐는 처음꺼부터 뺌. 수평관계
	{
		cout << Q.front() << ", ";
		Q.pop();
	}
	cout << endl;

	return 0;
}