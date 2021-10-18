#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct indexAndValue
{
	indexAndValue(int a, float b) : index(a), value(b){}
	int index;
	float value;
}indexAndValue;

// � ������ ��ó���� �ؾ� ������ ���� ���� �� �� �ִ°�?
// �Է� : �׽�Ʈ ���̽� ����, ����, �׽�Ʈ ���̽� �� �۾���/(�ɸ��� �ð� / �ϴ� ����)
// ��� : �۾�����

// �ַ��
// �ɸ��� ��¥ �� ���� ���� ã�ƴٰ�, �װ� ���� ������ �����Ѵ�. �̰� ������ �Է¼������ ó��.
int main(void)
{
	int testCase;
	cin >> testCase;

	for (int caseNum = 0; caseNum < testCase; caseNum++)
	{
		int order;
		vector<indexAndValue> table;	// (�ε�����, ��¥�� ����) �� �迭.
		cin >> order;
		for (int orderNum = 0; orderNum < order; orderNum++)
		{
			int day, forfeit;
			cin >> day >> forfeit;
			// ���̺� �ε��� ��ü�� ������ �̿��ؼ� �ٷ� ����ִ´�.
			table.push_back(indexAndValue( orderNum + 1, (float)forfeit / (float)day));
		}

		// ���̺� ���͸� �ߺ��� ���� �����ϸ鼭 ����. �۾������� �ڿ����� ����´�.
		stable_sort(table.begin(), table.end(),
			[&table](indexAndValue a, indexAndValue b) -> bool
			{
				if (a.value > b.value) return 1;
				else return 0;
			}		);

		for (auto i : table)
		{
			cout << i.index << ' ';
		}
		cout << endl;
	}
	return 0;
}