#include <iostream>
#include <string>

using namespace std;

// 메모리 사이즈에 대한 고찰.

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

// 결론.
// _msize는 자신이 담고 있는 전체 개체 수 * 자료형 만큼을 리턴한다.
// 그것이 일반 포인터인 경우 그 형태를 그대로 보내지만,
// 이중포인터라서 포인터 자료형을 담고 있는 경우 개체 수 * 포인터 자료형이 되어,
// 결론적으로 그 포인터가 갖고 있는 최종 자료형에 관계없이 포인터의 크기인 4바이트만큼 곱해지는 것이다.