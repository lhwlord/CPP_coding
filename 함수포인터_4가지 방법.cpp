#include <iostream>
#include <functional>
using namespace std;

// 함수포인터.
// 포인터니까 다른 함수를 지정해야 한다. 여기선 선언만.

// 첫번째 방법 : 고전적 방법. 요즘은 굳이 이렇게 안한다.
// 정확히는 뒤에 인자 괄호가 붙는다는 점이 함수포인터의 특기사항이며,
// 이름에 포인터는 함수포인터니까 붙되 괄호는 bool*로 인식하지 않게끔 우선순위를 두는 역할.
bool(*fu)(int);

bool test(bool(*fu)(int))
{
	(*fu)(0);	// 고전적 사용방법.
	fu(0);		// 요즘은 그냥 일반 함수처럼 써도 컴파일러가 알아서 다 해준다.
	return true;
}



// 두번째 방법 : 함수포인터를 고전적으로 선언하되 typedef로 함수 자료형 선언
typedef bool(*funca)(int, int);

bool foo(funca a)
{
	a(0, 0);	// 이렇게 하면 함수타입을 일반적인 상황처럼 간단히 쓸 수 있다.
	return true;
}



// 여기부턴 C++ 11 필요.

// 세번째 방법 : using 키워드 사용. 별칭을 만들 수 있다.
using fcn = bool(*)();

// 네번째 방법 : functional 헤더 필요. typedef나 using 외에 별개의 자료형이 튀어나온 모습이다.
function<int(bool)> fcn2;	// bool을 인자로 갖는 int 반환타입의 fcn2함수포인터 지정


// 와! 즐겁다!


int main() {

}