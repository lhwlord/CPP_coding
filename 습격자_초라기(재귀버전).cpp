#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int RESULT = 20000;	// ��������, �ٸ� �Լ����� �����Ӱ� ������ �� �ִ�. ���� ���.

// �� �� ��͸� ���� ����� �����Ѵ�.
// ���� �ܰ迡���� �迭�� ��������, row�� col�ε������� ��� �����ϸ�, �̴ϰ���� �����Ѵ�.
// �񱳰� ���� ���� ��쿡 �̴ϰ���� �������� RESULT�� ���Ͽ� ���� ������ �����Ѵ�.
// �����ܰ���� �Լ���ȯ�� �����ٸ� RESULT�� �� �б� �� ���� ���� ������ ������ ���̴�.
void cal(int** arr, int index_row, int index_col, int mini_result, const int platoonNum, const int floorNum)
{

	int tempNum = floorNum;	// ������ _msize�� �Ἥ ���� ��������, ���ؿ��� VC++�� �Լ��� _msize�� �������� �ʴ� ����� ���ڸ� ���� �߰�������, �� �������� �Լ��� �ȹٲٰ� �״�� ����
	//cout << "��� �� �� ũ�� ã�� : " << tempNum << "���� ����.\n";
	int** temp = new int* [2];
	temp[0] = new int[tempNum];
	temp[1] = new int[tempNum];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < tempNum; j++)
			temp[i][j] = arr[i][j];
	
	// 3���⿡ ���� �ش��ϴ� ������ �ֳ� ����, �бⰡ ����� ���.
	for (int i = index_row; i < 2; i++)
	{
		for (int j = index_col; j < tempNum; j++)
		{
			if (temp[i][j] != -1)	// ���� -1, �� �̹� ��ġ�� ���¶�� �� �� �ʿ䵵 ����.
			{
				bool leftPossible = false, rightPossible = false, otherSidePossible = false, matched = false;
				// ��ġ�� 0���� �ڱ� �ڽŸ� �ٲٰ� ������ �ȴ�.
				// ��ġ�� 1�� �̻��̸�, ó�� �ߴ� ��ġ�� �� �������� �����ϰ� �������� ��ͷ� ������.

				// ����Ž��.
				int toLeft = j == 0 ? tempNum - 1 : j - 1;
				if (temp[i][toLeft] != -1 && temp[i][toLeft] + temp[i][j] <= platoonNum)
					leftPossible = true;

				// ����Ž��.
				int toRight = j == tempNum - 1 ? 0 : j + 1;
				if (temp[i][toRight] != -1 && temp[i][toRight] + temp[i][j] <= platoonNum)
					rightPossible = true;

				// �ݴ���Ž��.
				if (temp[1 - i][j] != -1 && temp[1 - i][j] + temp[i][j] <= platoonNum)
					otherSidePossible = true;
				
				mini_result++;		// -1�� �ƴϴ� ��� 1�� �Ҵ�� �߰��ȴ�.
				temp[i][j] = -1;	// -1�� �ƴϴ� ��� ��Ȳ������ �� �ڽ��� �ٲ��.

				// ���ڿ� ���� �б⸦ ������ �ۼ��Ѵ�.
				{
					int temp_i, temp_j, temp_val;	// �ӽ÷� ������ ������. ó������ Ž���Ǿ� �� �������� �����ϴ� ��� ���⿡ ����.

					if (leftPossible)	// ù Ž���̹Ƿ� matched Ȯ���ʿ����, ���������ΰ��
					{
						matched = true;
						temp_i = i; temp_j = j; temp_val = temp[i][toLeft];
						temp[i][toLeft] = -1;
					}

					if (rightPossible)	// ���������ΰ��
					{
						if (!matched)
						{
							matched = true;
							temp_i = i; temp_j = j; temp_val = temp[i][toRight];
							temp[i][toRight] = -1;
						}
						else
						{
							// ��ġ�� ���� �ӽ÷� �ٲ۴�.
							temp[temp_i][temp_j] = temp_val;
							cal(temp, i, j, mini_result, platoonNum, floorNum);
							// ��ġ�� ���� �ٽ� -1�� �������´�.
							temp[temp_i][temp_j] = -1;
						}
					}

					if (otherSidePossible)	// �ݴ���Ⱑ���ΰ��
					{
						if (!matched)
						{
							// matched = true; ��ġ�ƴ��� ������ �ʿ������� �� ������ �������̶� ���ʿ�. temp_i,j,val ���� �ʿ����
							temp[1 - i][j] = -1;
						}
						else
						{
							// ��ġ�� ���� �ӽ÷� �ٲ۴�.
							temp[temp_i][temp_j] = temp_val;
							cal(temp, i, j, mini_result, platoonNum, floorNum);
							// ��ġ�� ���� �ٽ� -1�� �������´�.
							temp[temp_i][temp_j] = -1;
						}
					}
				}
			}
		}
	}

	// ��͹ݺ����� ���� �������Դٴ� ���� �迭�� ���� ��ȸ�ߴٴ� ��.
	// mini_result�� �����ϴ� �ϸ� ���Ҵ�.
	RESULT = RESULT > mini_result ? mini_result : RESULT;

	return;

}

// ������ �ʶ�� ����.
int main(void)
{
	///* ���ʿ� �˰����� ������, �Է½ð��� �� �� ���δٰ� �ؼ� ����� �ٲ��� �ʴ´�.
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);                    
	cout.tie(NULL);
	//*/
	int testCase;
	cin >> testCase;

	for (int testCaseNum = 0; testCaseNum < testCase; testCaseNum++)
	{
		int floorNum, platoonNum;
		cin >> floorNum >> platoonNum;

		int** arr = new int* [2];
		for (int i = 0; i < 2; i++) arr[i] = new int[floorNum];

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < floorNum; j++)
				cin >> arr[i][j];

		// ��&��͸� ���� �� ã�Ƴ���
		cal(arr, 0, 0, 0, platoonNum, floorNum);

		//cout << "���� ���� ������ �� �ִ� �Ҵ� ���� " << RESULT << "�Դϴ�.\n";

		cout << RESULT << endl;
		
		for (int i = 0; i < 2; i++) delete[] arr[i];
		delete[] arr;
	}
	return 0;
}