#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ��� ���ϰ� �ϱ�� ���밪.
int abs(int a)
{
	return a < 0 ? -a : a;
}

// ���̽� ����, ���� ����, �� ���̽� ���̵� ����.
// ���̽��� �����, �������ŭ�� ü�ߵ�.
// ������ ���̸� 1�� ���Ϸ� �θ鼭 �������� �ּҷ� �Ǵ� ����� ���� ���� �հ踦 ���
/*
-������� ¦���� ������� ������, Ȧ���� 1�� ���̳����� ���� ����
-������ ū ���Ե���� ���س����鼭 ���纸�� ���� ����� ������ ��츸 ��ȯ
-�������� �����԰� ������ �պ��� �۰� ������ ���� ������ ����� Ʋ������... �˰����� ���ƾ���.
-�˰��� ��ü�� ��ȭ���� �ƴϹǷ� �ð��� �� �ɸ����� �ִ�.
-��� �ణ �߸ŷ� �� ���� �����ʾ� �ִ�. ���߿� ������ ���̸� ������ �� �ֵ���.
*/
int main(void)
{
	//srand(time(NULL));	// ������-1. ���� ������ ��


	int testCase;
	cin >> testCase;
	cin.get();	// ���ͳѱ��
	while(testCase--)
	{
		int human;
		scanf("%d", &human);
		//int* weight = new int[human];
		vector<int> weight(human);
		for (int hNum = 0; hNum < human; hNum++)
		{
			//scanf_s("%d", weight+hNum); // �̰ų� ���� �� �� �� �ϳ� ���.
			scanf("%d", &weight[hNum]);	// �迭�� ������ ����������, �� ���� �ε����� ��Ī�ϴ� ��� ���� �����ϱ� ������ �ּҿ����ڸ� �ٿ��� �Ѵ�.

			//weight[hNum] = rand() % 450 + 1;	// ������-2. ���� ������ ��(���� ��ɾ� Ȱ��ȭ)
		}


		int gap = 0;	// ���߿� ó���� ���� �̸� ȣ����� ���

		// ���� 1�������� �����ϱ�
		//int * teamA = new int[human - (human / 2)];
		//int * teamB = new int[human / 2];
		vector<int> teamA(human - (human / 2));
		vector<int> teamB(human / 2);
		int aIndex = 0, bIndex = 0;
		for (int i = 0; i < human; i++)
		{
			if (i % 2 == 0)
			{
				teamA[aIndex++] = weight[i];
				gap += weight[i];
			}
			else
			{
				teamB[bIndex++] = weight[i];
				gap -= weight[i];
			}
		}


		/*
		// ������-3. ���� ������ ��
		int temp_a = 0, temp_b = 0;
		cout << "A�� ���.\n";
		for (int i = 0; i < _msize(teamA) / sizeof(int); i++)
		{
			cout << i + 1 << "�� ���� : " << teamA[i] << endl;
			temp_a += teamA[i];
		}
		cout << endl << "B�� ���.\n";
		for (int i = 0; i < _msize(teamB) / sizeof(int); i++)
		{
			cout << i + 1 << "�� ���� : " << teamB[i] << endl;
			temp_b += teamB[i];
		}
		cout << temp_a << ' ' << temp_b << endl;
		*/


		// ������ n^2 ����. ��ȯ�� �̵��� ��쿡�� ������, �׷��� ���� ó������ ������.
		for (int i = 0; i < teamA.size(); i++)
		{
			for (int j = 0; j < teamB.size(); j++)
			{
				
				if (abs(gap) > abs(gap - 2 * (teamA[i] - teamB[j])))
				{
					gap = gap - 2 * (teamA[i] - teamB[j]);
					int temp = teamA[i];
					teamA[i] = teamB[j];
					teamB[j] = temp;
					i = 0;
					j = 0;
				}
			}
		}


		/*
		// ������-4. ���� ������ ��
		cout << "\n\n\n��а��.\n\nA�� ���.\n";
		for (int i = 0; i < _msize(teamA) / sizeof(int); i++)
		{
			cout << i + 1 << "�� ���� : " << teamA[i] << endl;
		}
		cout << endl << "B�� ���.\n";
		for (int i = 0; i < _msize(teamB) / sizeof(int); i++)
		{
			cout << i + 1 << "�� ���� : " << teamB[i] << endl;
		}
		*/
		

		// ������ Ż���ߴ� == ������ ���Ժй谡 ������ �̷�����, ��� ���� ���� �� ���ؼ� ���
		int aSum = 0, bSum = 0;
		for (int i = 0; i < teamA.size(); i++)
		{
			cout << teamA[i] << ' ';
			aSum += teamA[i];
		}
		cout << endl;
		for (int i = 0; i < teamB.size(); i++)
		{
			cout << teamB[i] << ' ';
			bSum += teamB[i];
		}
		cout << endl;

		

		if(aSum < bSum) cout << aSum << ' ' << bSum << endl << endl;
		else cout << bSum << ' ' << aSum << endl << endl;


		cin.get();	//���ͳѱ��
	}
	return 0;
}