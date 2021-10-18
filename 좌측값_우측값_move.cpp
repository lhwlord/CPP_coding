#include <iostream>
#include <string>

using namespace std;

int main() {

	string a = "abc";
	cout << a << endl;
	cout << &a << endl;

	string b = move(a);	// a�� ���������� ��û���� �������� �ȴ�. ���� �Ͽ� �״´�.

	cout << &a << endl;	// a�� ��ġ�� ������ �����Ѵ�. ���� �� �̸� �ٿ����ϱ�.
	cout << a << endl;	// ���� ���Ŀ� �״´�. C++ ��Ʈ���� Ư�� ���� �ٷ� �������.
	cout << &b << endl;
	cout << b << endl;

	string&& c = move(b);	// ���� ���۷����� �����´�. b�� �����Ͽ� ���� ����̾�����, &&�����ڰ� �װ� ��ȴ�. ���� ����� b�� �״�� �ְ�, c�� b�� ���� �ִ� ������ ���� '���� �� ��' �� ���̴�.

	cout << &b << endl;
	cout << b << endl;
	cout << &c << endl;
	cout << c << endl;	// c�� b�� ����. �ּ�����������.

	move(c);	// �ڱ� ȥ�� ���������� �ٲ����� ���Կ����� �Ͼ�� �ʾ� ���� �ı��� ����. ������ ���� ��ȯ�� Ÿ���� �׷��� ���Ŷ� c�� ������ �������̴�.


	cout << c << endl;

	cout << "=================" << endl;
	string aa = "123";
	const string& bb = move(aa);	// aa�� ������ ����������, const�� �� ���������� ����.
	cout << &aa << endl;
	cout << &bb << endl;
	string cc = move(aa);
	cout << "\"" << aa << "\"" << endl;
	return 0;
}