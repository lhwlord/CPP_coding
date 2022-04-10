#include <iostream>
using namespace std;
class Person {
private:
	int a;
public:
	Person() {
		cout << "Parameterized constructor" << endl;
		a = 1;
	}
	~Person() {
		cout << "Destructor is called" << endl;
	}

	void testInnerFunction()
	{
		a = 2;
	}

	void testFunction() const
	{
		testInnerFunction();	// 안된다! 상위함수의 const 키워드에 제한받는다.
	}
};
int main() {
	Person p1();
	return 0;
}