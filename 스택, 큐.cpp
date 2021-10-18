#include <iostream>
#include <stack>	// ���� ���ǵ� ���
#include <queue>	// ť ���ǵ� ���

using namespace std;

int main(void)
{
	stack<int> S;	// int ���� ���ð�ü ����. �ڹٿ� �ٸ��� C++�� ��ü ����� new ���ñ� ���ص� �ȴ�. �ڹٿ����� new ������ �̸� ������ü�� �����صΰ� ���߿� ��üȭ�ϴ� �����̶��, C++�� ���߻���� �����ϹǷ� �ش� Ÿ���� ó������ ������ �����ؾ� �ϴµ�.

	queue<int> Q;	// ���� ť ��ü �ϳ� ����.

	S.push(2);
	S.push(0);
	S.push(1);
	S.push(4);

	Q.push(2);
	Q.push(0);
	Q.push(1);
	Q.push(4);

	while (S.empty() == false)	// ������ ������������ ��. ���ϰ���
	{
		cout << S.top() << ", ";
		S.pop();
	}
	cout << endl;

	while (Q.empty() == false)	// ť�� ó�������� ��. �������
	{
		cout << Q.front() << ", ";
		Q.pop();
	}
	cout << endl;

	return 0;
}