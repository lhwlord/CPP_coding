#include <iostream>
#include <string>

using namespace std;

// �޸� ����� ���� ����.

void main(void)
{
	char a;
	char* c = new char[1];

	cout << sizeof(a) << endl;
	cout << sizeof(c) << endl;
	cout << _msize(c) << endl;

	char** arr = new char* [10];
	for (int i = 0; i < 10; i++) arr[i] = new char[2];

	cout << _msize(arr) << endl;
	cout << _msize(arr[0]) << endl;
	return;
}

// ���.
// _msize�� �ڽ��� ��� �ִ� ��ü ��ü �� * �ڷ��� ��ŭ�� �����Ѵ�.
// �װ��� �Ϲ� �������� ��� �� ���¸� �״�� ��������,
// ���������Ͷ� ������ �ڷ����� ��� �ִ� ��� ��ü �� * ������ �ڷ����� �Ǿ�,
// ��������� �� �����Ͱ� ���� �ִ� ���� �ڷ����� ������� �������� ũ���� 4����Ʈ��ŭ �������� ���̴�.