/*
�� ���� �޶������� �� �ٿ� ���ڸ� ����ִٸ� ���������̼� ������ ���� �Ѵ�. ���� �� ó���� ��ü ���ڿ��� �޾� ó���ϴ� �������� �˾Ƽ� ����ǵ��� �ؾ� �� ��.

-���ڿ����� ��ü �� �Է¹޴´�.
-������ ��ŭ ���鼭 �ϳ��ϳ� �������� �� ���� �´ٸ� ����.
-�װ� �ƴ϶�� ��¿������� ���������� �����ؾ� �Ѵ�.(���ڴ� ���ڴ� ���� ���� �߸��ż� ���Ա� ����)
-���ڿ��鿡�� ���ڸ��� ���� ���ٰ� �ٸ� �迭�� 1�� ������ ����ִ´�. ���⿡�� isdigit()�� ���� ���� ���ƺ��δ�.
-�װ� ���ؼ�, ������ ��¿���, �ٸ��� ����.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���Է°��� 0�� �ƴϸ� ������ �Է¹ް�, ���� ���Է°��� ���� ������� �Է¹޴´�.
// �Ϻ��� ��ġ�ϸ� �ش� ���̽� ���. Run #() : Accepted
// ���ڿ����� ���� ������ ��ġ�ϳ�(������ ������ ��ġ�ϸ� �� ���̿� ���ڰ� ��� �����) ���ڰ� �ϳ� �̻� ����ġ�ϸ� Run #() : Presentation Error
// ���� �� ������ �ش����� ������ Run #() : Wrong Answer
int main(void)
{
	int input, output;
	int count = 1;	// Run�� �� �õ��ѹ���
	while (true)
	{
		string inS[100];
		string outS[100];
		cin >> input;
		cin.get();
		if (input == 0) break;
		// ���ڿ� ��ü �� �Է¹ޱ�
		for (int i = 0; i < input; i++)
		{
			getline(cin, inS[i]);
		}
		cin >> output;
		cin.get();
		for (int i = 0; i < output; i++)
		{
			getline(cin, outS[i]);
		}

		// ������(��������) ���� Ȯ��
		bool isSame = true;
		if (input == output)
		{
			for (int i = 0; i < input; i++)
			{
				if (inS[i] != outS[i]) isSame = false;
			}
		}
		else
			isSame = false;
		if (isSame)
		{
			cout << "Run #" << count++ << ": Accepted\n";
			continue;
		}

		//���� �ʾƼ� ������� �Դ�. ���� ��¿�������, ���������� Ȯ���ؾ� �Ѵ�.
		vector<int> inDigit;
		vector<int> outDigit;
		int inDCount = 0, outDCount = 0;
		for (int i = 0; i < input; i++)
		{
			for (int j = 0; j < inS[i].length(); j++)
				if (isdigit(inS[i][j])) inDigit.push_back(inS[i][j]);
		}
		for (int i = 0; i < output; i++)
		{
			for (int j = 0; j < outS[i].length(); j++)
				if (isdigit(outS[i][j])) outDigit.push_back(outS[i][j]);
		}

		// ���ڸ� �� �����ؼ� ���Ϳ� ����־���. �̰� ���ʷ� ���ϴ� �ϸ� ���Ҵ�.
		bool isErr = true;
		if (inDigit.size() != outDigit.size()) isErr = false;
		else
		{
			for (int i = 0; i < inDigit.size(); i++)
			{
				if (inDigit[i] != outDigit[i]) isErr = false;
			}
		}

		// ���� isErr�� ���¿� ���� ����� �޸��ϸ� �ȴ�.
		if (isErr)
			cout << "Run #" << count++ << ": Presention Error\n";
		else
			cout << "Run #" << count++ << ": Wrong Answer\n";
	}
	return 0;
}