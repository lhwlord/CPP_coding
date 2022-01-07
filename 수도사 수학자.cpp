#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 큰수연산용 더하기.
vector<char> bigPlus(vector<char> a, vector<char> b)
{
	vector<char> temp;
	temp.push_back(0);
	//cout << (int)temp[0];

	// 자릿수 부호확장. 어차피 더하기만 이용할 것이므로 부호확장을 걱정할 필요는 없다.
	// 큰 수의 음수계산은 나중에 구현하고싶으면 하도록. 지금은 아니다.
	if (a.size() > b.size())
	{
		int high = a.size() - b.size();
		for (int i = 0; i < high; i++)
			b.push_back(0);
	}
	else
	{
		int high = b.size() - a.size();
		for (int i = 0; i < high; i++)
			a.push_back(0);
	}
	

	// 넘치는 수를 다음으로 넘기며 진행
	for (int i = 0; i < a.size(); i++)
	{
		temp[i] += a[i] + b[i];
		if (temp[i] >= 10)
		{
			temp.push_back(1);
			temp[i] %= 10;
		}
		else
		{
			temp.push_back(0);
		}
	}
	// 맨 끝이 0인지 판별하고 0이면 최적화를 위해 지움
	if (temp[temp.size() - 1] == 0)
		temp.pop_back();
	return temp;
}

// 큰수연산용 출력.
// 내 큰수연산은 앞자리가 1의 자리이기 때문에 거꾸로 출력하기 위해 설정한다.
void bigPrint(vector<char> a)
{
	for (int i = a.size() - 1; i != -1; i--)
	{
		cout << (int)a[i];
	}
}

// 큰수연산용 비교.
// 내 큰수연산은 앞자리가 1의 자리이기 때문에 일반 벡터비교는 할 수 없다.
// 사실 그럴 줄 알았으면 그냥 앞자리부터 넣는거지만, 이것도 연습이라 생각하고 진행.
int bigCmp(vector<char> a, vector<char> b)
{
	if (a.size() > b.size()) return 1;
	else if(b.size() > a.size()) return -1;
	else
	{
		for (int i = a.size() - 1; i != -1; i--)
		{
			if (a[i] > b[i]) return 1;
			else if (a[i] < b[i]) return -1;
		}
	}
	return 0;
}

int main(void)
{
	string s;
	while (getline(cin, s))
	{
		// s배열에 있는걸 적당히 처리
		int num = stoi(s);
		
		// 큰수연산용으로 들어갈 하노이와 하노이4 생성. 큰수배열의 수열배열.
		vector<vector<char>> hanoi, hanoi4;
		
		// 하노이 초기값 처리. 나는 각각 0, 1을 직접 값으로 줬음.
		vector<char> temp1, temp2;
		temp1.push_back(0);
		temp2.push_back(1);
		hanoi.push_back(temp1);
		hanoi4.push_back(temp1);
		hanoi.push_back(temp2);
		hanoi4.push_back(temp2);

		// 하노이 연산부터 처리. 2배 + 1을 하면 된다.
		for (int i = 2; i < num + 1; i++)
		{
			vector<char> temp = bigPlus(bigPlus(hanoi[i - 1], hanoi[i - 1]), { 1 });
			hanoi.push_back(temp);
		}

		int kIndex = 1;
		// n을 1부터 num까지 올리면서 hanoi4 구하기
		for (int n = 2; n < num + 1; n++)
		{
			// 참고로, 이 알고리즘에는 최솟값을 구해야 하는 문제가 있다. 따라서 k를 1부터 n-1까지 올리면서 값들을 저장할 곳이 필요하다.
			vector<char> hanoi4_candidate_minimum = bigPlus(hanoi[n-1], bigPlus(hanoi4[1], hanoi4[1]));
			for (int k = 2; k < n; k++)
			{
				vector<char> hanoi4_candidate_case = bigPlus(hanoi[n - k], bigPlus(hanoi4[k], hanoi4[k]));
				
				//디버깅용 코드.
				/*
				cout << k << "번째 시도 : ";
				bigPrint(hanoi[n - k]);
				cout << " + 2 * ";
				bigPrint(hanoi4[k]);
				cout << " = ";
				bigPrint(hanoi4_candidate_case);
				cout << endl;
				*/

				if (bigCmp(hanoi4_candidate_minimum, hanoi4_candidate_case) == 1)
				{
					hanoi4_candidate_minimum = hanoi4_candidate_case;
					kIndex = k;
				}
			}
			hanoi4.push_back(hanoi4_candidate_minimum);
		}
		
		// 최종출력 전 검사.(디버깅용)
		/*
		if (num == 0) cout << "0단계는 0으로 정의됨." << endl;
		else if (num == 1) cout << "1단계는 1로 정의됨." << endl;
		else
		{
			cout << num << " - " << kIndex << " = " << num - kIndex << "만큼의 하노이 단계 : ";
			bigPrint(hanoi[num - kIndex]);
			cout << ", 그리고 그만큼의 하노이4 를 " << kIndex << "단계(";
			bigPrint(hanoi4[kIndex]);
			cout << ")만큼 2번 진행한 결과 : ";
			bigPrint(hanoi4[num]);
			cout << endl;
		}
		*/

		//마지막으로 하노이4 출력.
		bigPrint(hanoi4[num]);
		cout << endl;
	}
	return 0;
}