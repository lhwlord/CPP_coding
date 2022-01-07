#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ū������� ���ϱ�.
vector<char> bigPlus(vector<char> a, vector<char> b)
{
	vector<char> temp;
	temp.push_back(0);
	//cout << (int)temp[0];

	// �ڸ��� ��ȣȮ��. ������ ���ϱ⸸ �̿��� ���̹Ƿ� ��ȣȮ���� ������ �ʿ�� ����.
	// ū ���� ��������� ���߿� �����ϰ������ �ϵ���. ������ �ƴϴ�.
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
	

	// ��ġ�� ���� �������� �ѱ�� ����
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
	// �� ���� 0���� �Ǻ��ϰ� 0�̸� ����ȭ�� ���� ����
	if (temp[temp.size() - 1] == 0)
		temp.pop_back();
	return temp;
}

// ū������� ���.
// �� ū�������� ���ڸ��� 1�� �ڸ��̱� ������ �Ųٷ� ����ϱ� ���� �����Ѵ�.
void bigPrint(vector<char> a)
{
	for (int i = a.size() - 1; i != -1; i--)
	{
		cout << (int)a[i];
	}
}

// ū������� ��.
// �� ū�������� ���ڸ��� 1�� �ڸ��̱� ������ �Ϲ� ���ͺ񱳴� �� �� ����.
// ��� �׷� �� �˾����� �׳� ���ڸ����� �ִ°�����, �̰͵� �����̶� �����ϰ� ����.
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
		// s�迭�� �ִ°� ������ ó��
		int num = stoi(s);
		
		// ū����������� �� �ϳ��̿� �ϳ���4 ����. ū���迭�� �����迭.
		vector<vector<char>> hanoi, hanoi4;
		
		// �ϳ��� �ʱⰪ ó��. ���� ���� 0, 1�� ���� ������ ����.
		vector<char> temp1, temp2;
		temp1.push_back(0);
		temp2.push_back(1);
		hanoi.push_back(temp1);
		hanoi4.push_back(temp1);
		hanoi.push_back(temp2);
		hanoi4.push_back(temp2);

		// �ϳ��� ������� ó��. 2�� + 1�� �ϸ� �ȴ�.
		for (int i = 2; i < num + 1; i++)
		{
			vector<char> temp = bigPlus(bigPlus(hanoi[i - 1], hanoi[i - 1]), { 1 });
			hanoi.push_back(temp);
		}

		int kIndex = 1;
		// n�� 1���� num���� �ø��鼭 hanoi4 ���ϱ�
		for (int n = 2; n < num + 1; n++)
		{
			// �����, �� �˰��򿡴� �ּڰ��� ���ؾ� �ϴ� ������ �ִ�. ���� k�� 1���� n-1���� �ø��鼭 ������ ������ ���� �ʿ��ϴ�.
			vector<char> hanoi4_candidate_minimum = bigPlus(hanoi[n-1], bigPlus(hanoi4[1], hanoi4[1]));
			for (int k = 2; k < n; k++)
			{
				vector<char> hanoi4_candidate_case = bigPlus(hanoi[n - k], bigPlus(hanoi4[k], hanoi4[k]));
				
				//������ �ڵ�.
				/*
				cout << k << "��° �õ� : ";
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
		
		// ������� �� �˻�.(������)
		/*
		if (num == 0) cout << "0�ܰ�� 0���� ���ǵ�." << endl;
		else if (num == 1) cout << "1�ܰ�� 1�� ���ǵ�." << endl;
		else
		{
			cout << num << " - " << kIndex << " = " << num - kIndex << "��ŭ�� �ϳ��� �ܰ� : ";
			bigPrint(hanoi[num - kIndex]);
			cout << ", �׸��� �׸�ŭ�� �ϳ���4 �� " << kIndex << "�ܰ�(";
			bigPrint(hanoi4[kIndex]);
			cout << ")��ŭ 2�� ������ ��� : ";
			bigPrint(hanoi4[num]);
			cout << endl;
		}
		*/

		//���������� �ϳ���4 ���.
		bigPrint(hanoi4[num]);
		cout << endl;
	}
	return 0;
}