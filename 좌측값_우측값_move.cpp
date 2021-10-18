#include <iostream>
#include <string>

using namespace std;

int main() {

	string a = "abc";
	cout << a << endl;
	cout << &a << endl;

	string b = move(a);	// a는 좌측값에서 숙청당해 우측값이 된다. 다음 턴에 죽는다.

	cout << &a << endl;	// a의 위치는 여전히 존재한다. 내가 라벨 이름 붙였으니까.
	cout << a << endl;	// 대입 이후에 죽는다. C++ 스트링은 특히 값이 바로 사라진다.
	cout << &b << endl;
	cout << b << endl;

	string&& c = move(b);	// 우측 레퍼런스로 가져온다. b는 다음턴에 죽을 운명이었지만, &&연산자가 그걸 살렸다. 물론 사실은 b는 그대로 있고, c가 b의 값이 있는 곳으로 가서 '여기 내 땅' 한 꼴이다.

	cout << &b << endl;
	cout << b << endl;
	cout << &c << endl;
	cout << c << endl;	// c는 b와 같다. 주소참조했으니.

	move(c);	// 자기 혼자 우측값으로 바꿨지만 대입연산이 일어나지 않아 값의 파괴가 없다. 심지어 당장 반환할 타입을 그렇게 고른거라서 c는 여전히 좌측값이다.


	cout << c << endl;

	cout << "=================" << endl;
	string aa = "123";
	const string& bb = move(aa);	// aa를 우측값 대기시켰지만, const인 한 복제연산이 들어간다.
	cout << &aa << endl;
	cout << &bb << endl;
	string cc = move(aa);
	cout << "\"" << aa << "\"" << endl;
	return 0;
}