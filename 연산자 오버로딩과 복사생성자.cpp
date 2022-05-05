#include <iostream>
using namespace std;

class cat
{
private:
	int num;	// 이게 객체의 코어
public:
	cat(int a) : num(a) {}
	cat() : num(0) {}

	cat(const cat& other)	// const 선언 없을 때의 문제점 : 이걸 호출하려면 인자가 우측값으로 들어가는데, 우측값은 상수값이어야 하며, 다른 주소를 참조하는 식으로 드갈 수 없다.
		// 다른 경우에도 전부 상수화 처리돼서 들어가는거지, 우리가 직접 선언할 땐 일부러 바꿔야 한다.
		// & 선언 없을 때의 문제점 : 무한생성 루프에 빠질 수 있다.
	{
		num = other.num;
	}

	~cat()
	{
		// delete this는 의미가 없다. 동적할당이 안됐으면 delete를 쓸 필요가 없고, 됐으면 되려 delete가 호출되어야 소멸자가 동작하기 때문이다.
		
	}

	void printNum()
	{
		printf("%d\n", num);
	}

	cat operator+(cat& other)
	{
		cat a = cat(*this);
		a.num += other.num;
		return a;
	}

	cat operator-(cat& other)
		//  - 연산을 쓸 때 &을 넣으려면 동적할당 객체를 만들어야 하고, 그러면 다른 메소드를 만들어다가 동적할당 여부 변수 만들고,
		// 동적할당인 경우에만 자신을 delete 하는 식으로 동작해야 하는데, 이러면 괜히 프로그램이 복잡해지고, 추가로 - 연산에 그렇게 쓸데없이 비대하게 설정할 필요가 없다.
		// 따라서, ++이나 --처럼 자기 자신을 반환하는 것이 아닌 한, +나 -같은 경우라면 우측값 반환용으로 객체 자체를 복사시켜넣고 끝내도록 하자.
	{
		cat a = cat(*this);
		a.num -= other.num;
		return a;
	}
};

class cat2	: public cat // 하위클래스
{
	cat2() : cat(1) {}
};


int main(void)
{
	cat a = cat(1);
	cat b = cat(2);
	cat c = cat(3);
	
	cat d = a + a + b;

	d.printNum();

	cat2 e();	// 이건 활용할 수 없다. 우측값처럼 넘겨지기 때문이다.
	2;	// 이거랑 같은 의미다. 어디 담긴게 없는데 뭘 어떻게 하겠는가?

	cat f = c - a;
	f.printNum();
}