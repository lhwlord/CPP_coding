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
		testInnerFunction();	// �ȵȴ�! �����Լ��� const Ű���忡 ���ѹ޴´�.
	}
};
int main() {
	Person p1();
	return 0;
}