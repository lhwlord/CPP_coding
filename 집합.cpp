#include <iostream>
#include <algorithm>	// set_difference, sort 쓰는 용도.
#include <vector>	// 벡터 쓰는 용도. 벡터는 기능 추가된 배열과 비슷함.

using namespace std;

// 차집합을 구하는 예제.
int main()
{
	int first[] = { 5, 10, 15, 20, 25 };
	int second[] = { 50, 40, 30, 20, 10 };
	vector<int> v(10);	// 10개 공간 갖는 벡터 생성 후 초기화.
	vector<int>::iterator it;

	sort(first, first + 5);	// 해당 범위 내의 요소들을 오름차순 정렬.
	sort(second, second + 5);

	it = set_difference(first, first + 5, second, second + 5, v.begin());	// 앞의 집합에서 뒤의 집합과 겹치는 요소들을 전부 제거함. 단 포인터 역할인 iterator에서 썼으므로 원본은 무사하며(뇌피셜), iterator에서 작업한 후 v에 넣었으므로 뒤에 초기화용으로 생긴 0들을 제거해야 할 것.

	

	v.resize(it - v.begin());	// iterator의 현재 포인팅 위치(요소 3개 지나간 만큼)에서 벡터 v의 시작부분만큼 빼서, 그 사이의 3개 요소만 살린다.

	cout << "차이는 " << (v.size()) << "개 요소다 : " << endl;
	
	for (it = v.begin(); it != v.end(); it++)	// 벡터의 출력은 포인팅 변수 it를 써서, 그걸 v의 시작지점에 둬놓고 1씩 증가시키면서 진행하는 것.
		cout << ' ' << *it;
	cout << endl;
	return 0;
}