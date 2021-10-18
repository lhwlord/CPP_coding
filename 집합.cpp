#include <iostream>
#include <algorithm>	// set_difference, sort ���� �뵵.
#include <vector>	// ���� ���� �뵵. ���ʹ� ��� �߰��� �迭�� �����.

using namespace std;

// �������� ���ϴ� ����.
int main()
{
	int first[] = { 5, 10, 15, 20, 25 };
	int second[] = { 50, 40, 30, 20, 10 };
	vector<int> v(10);	// 10�� ���� ���� ���� ���� �� �ʱ�ȭ.
	vector<int>::iterator it;

	sort(first, first + 5);	// �ش� ���� ���� ��ҵ��� �������� ����.
	sort(second, second + 5);

	it = set_difference(first, first + 5, second, second + 5, v.begin());	// ���� ���տ��� ���� ���հ� ��ġ�� ��ҵ��� ���� ������. �� ������ ������ iterator���� �����Ƿ� ������ �����ϸ�(���Ǽ�), iterator���� �۾��� �� v�� �־����Ƿ� �ڿ� �ʱ�ȭ������ ���� 0���� �����ؾ� �� ��.

	

	v.resize(it - v.begin());	// iterator�� ���� ������ ��ġ(��� 3�� ������ ��ŭ)���� ���� v�� ���ۺκи�ŭ ����, �� ������ 3�� ��Ҹ� �츰��.

	cout << "���̴� " << (v.size()) << "�� ��Ҵ� : " << endl;
	
	for (it = v.begin(); it != v.end(); it++)	// ������ ����� ������ ���� it�� �Ἥ, �װ� v�� ���������� �ֳ��� 1�� ������Ű�鼭 �����ϴ� ��.
		cout << ' ' << *it;
	cout << endl;
	return 0;
}