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

// 어떤 순서로 일처리를 해야 벌금을 가장 적게 낼 수 있는가?
// 입력 : 테스트 케이스 개수, 빈줄, 테스트 케이스 당 작업수/(걸리는 시간 / 일당 벌금)
// 출력 : 작업순서

// 솔루션
// 걸리는 날짜 당 벌금 값을 찾아다가, 그게 높은 순서로 정렬한다. 이게 같으면 입력순서대로 처리.
int main(void)
{
	int testCase;
	cin >> testCase;

	for (int caseNum = 0; caseNum < testCase; caseNum++)
	{
		int order;
		vector<indexAndValue> table;	// (인덱스값, 날짜당 벌금) 의 배열.
		cin >> order;
		for (int orderNum = 0; orderNum < order; orderNum++)
		{
			int day, forfeit;
			cin >> day >> forfeit;
			// 테이블에 인덱스 객체를 생성자 이용해서 바로 집어넣는다.
			table.push_back(indexAndValue( orderNum + 1, (float)forfeit / (float)day));
		}

		// 테이블 벡터를 중복값 순서 보존하면서 정렬. 작업순서는 자연스레 따라온다.
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