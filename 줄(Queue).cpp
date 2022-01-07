#include <iostream>
#include <string>
#include <vector>
using namespace std;

int human, leftSee, rightSee;	// ���� ū Ű, ���� �� �� �ִ� ���, ���� �� �� �ִ� ���. ��ͷ� ���̱⿣ �޸𸮰� �Ʊ��� �������� ����.
int permCount = 0;	// 

// ������ �����. ������ ���������� ��� ��Ʈ���� �̿��� ���Ѵ�.
void permutation(string grow, string left)
{
	if (left.length() == 0) // grow�� �ϼ��ƴٴ� ��.
	{
		// �������� �����ϸ� ������ �� �� �ִ� ��� �� ����
		int leftP = 1;
		int biggest = grow[0];
		for (int i = 0; i < grow.length(); i++)
		{
			if (biggest < grow[i])
			{
				biggest = grow[i];
				leftP++;
				if (grow[i] == human - 1) break;
			}
		}

		// �������� �����ϸ� ������ �� �� �ִ� ��� �� ����
		int rightP = 1;
		biggest = grow[grow.length() - 1];
		for (int i = grow.length() - 1; i != 0; i--)
		{
			if (biggest < grow[i])
			{
				biggest = grow[i];
				rightP++;
				if (grow[i] == human - 1) break;
			}
		}

		if (leftSee == leftP && rightSee == rightP) permCount++;
	}
	else
	{
		for (int i = 0; i < left.size(); i++)
		{
			// ����ð� ���̱� : ���� ū Ű�� ���� ��Ҵ� ��� ������ ���� �þ� ���ʿ� ���;� �Ѵ�.
			 if (!((left[i] == human - 1) && ((grow.length() < leftSee - 1) || (grow.length() > human - rightSee))))
			{
				string tempS = left;
				permutation(grow + left[i], tempS.erase(i, 1));
			}
		}
	}
}


// ���̽� ����, ���̽� �� �����, ���� �� �� �ִ� ���, ���� �� �� �ִ� ��� �Է�.
// ��/�츦 �ش��ϴ� ���ڸ�ŭ �� �� �ִ� ������ ���.
/*
�ַ�� : ��ͷ� ������ �����, ����.
��, ������ ��ŭ ���⵵�� ���丮��� �����Ѵ�. �̴� �ʹ� �����ϹǷ�, �߰��߰� Ʈ���� �̿��� ������� ���̵��� �Ѵ�.
*/
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int caseNum = 0; caseNum < testCase; caseNum++)
	{
		scanf_s("%d %d %d", &human, &leftSee, &rightSee);
		string leftString = "";
		for (int i = 0; i < human; i++) leftString += (char)(i + '0');
		permutation("", leftString);
		cout << permCount << endl;
		permCount = 0;
	}
	return 0;
}