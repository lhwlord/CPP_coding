#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

// ���� ���ϴ� �켱��Ģ
// ���⼱ �հ��� ���밪�� ũ�� ��, ���� ��� ��ȣ���� ũ�� ��. �̿��� ��Ȳ���� ����.
struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2))
			return true;
		else if (abs(n1) == abs(n2))
			if (n1 > n2)
				return true;
			else
				return false;
		return false;
	}
};

int main(void) {

	priority_queue<int, vector<int>, cmp> pq;
	pq.push(1);
	pq.push(-1);
	pq.push(7);
	pq.push(-4);
	pq.push(15);

	for (int i = 0; i < 5; i++) {
		cout << pq.top() << ' ';
		pq.pop();
	}
}