#include <iostream>
#include <string>

using namespace std;

void find(char**, string, int, int);
bool check(int, int, char**, string, int, int, int, int);

// �ܾ�ã�� ���α׷�.
// �Է� : �׽�Ʈ Ƚ��, ����, ���� ����, �׸�ŭ�� �׸���, ã�� ���� ��, ���� ���.
// ��� : �� ������ ù���ڰ� ó������ �����ϴ�(���/����) ��ǥ.
int main(void)
{
	int test;
	cin >> test;
	cin.ignore(1, '\0');
	for (int i = 0; i < test; i++)
	{
		int row, col;
		cin >> row >> col;
		char** arr = new char* [row];
		for (int j = 0; j < row; j++) arr[j] = new char[col];
		cin.ignore(1, '\0');
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				cin.get(arr[j][k]);
				//�Է¹��� �׸����� ��ҹ��� ����
				if (isupper(arr[j][k])) arr[j][k] = tolower(arr[j][k]);
			}
			cin.get();
		}
		int wordCount;
		cin >> wordCount;
		string* str = new string[wordCount];
		for (int j = 0; j < wordCount; j++)
		{
			cin >> str[j];
			// �Է¹��� ��Ʈ���� ��ҹ��� ����
			for (int k = 0; k < str[j].length(); k++)
				if (isupper(str[j][k])) str[j][k] = tolower(str[j][k]);
		}
		cin.ignore(1, '\0');
		//�������� �۾�.
		for (int j = 0; j < wordCount; j++) find(arr, str[j], row, col);
		//�����Ҵ� �޸� ����
		for (int j = 0; j < row; j++) delete arr[j];
		delete[] arr;
	}
	return 0;
}

// 2���� �迭���� s�� �ִ����� �˻�, �ִٸ� ó�� ������ ��ǥ���� �״�� ȭ�鿡 ���.
void find(char** arr, string s, int row, int col)
{
	int i, j;
	int dir[8][2] = { {-1,-1},{0,-1},{+1,-1},{-1,0},{-1,+1},{+1,-1},{+1,0},{+1,+1} };

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			// ù�ڸ� ã�Ҵٸ� 8������ ���� �ش� ������ ������������ �˻�.
			if (s[0] == arr[i][j])
			{
				// ��ǥ �������� ������ �� ������, ���ڿ��� Ȯ���Ǵ°��� ���� ����, �´ٸ� ������ üũ���� �ϴ� �Լ�. üũ�� ���̸� �ٷ� �������´�.
				for (int k = 0; k < 8; k++)
						if (check(dir[k][0], dir[k][1], arr, s, i, j, row, col)) goto EXIT;
			}
		}
	}
	// �迭�� ������ ���ȴµ��� �´� ���� ���ٸ�
	cout << "��ġ�ϴ� ���� �����ϴ�.\n";
	goto END;
EXIT : 
	cout << i + 1 << ' ' << j + 1 << endl;
END : 
	return;
}

// arr�� x,y ��ġ���� toX, toY ���⿡ s�� ������ �� �ִ��� �˻�.
bool check(int toX, int toY, char** arr, string s, int x, int y, int row, int col)
{
	if (!((0 <= (x + ((s.length()-1) * toX)) && (x + ((s.length()-1) * toX)) < row) && (0 <= (y + ((s.length()-1) * toY)) && (y + ((s.length()-1) * toY)) < col))) return false;   // ���� ���
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != arr[x + (toX * i)][y + (toY * i)]) return false;	// ���� �ٸ�
	}
	return true;
}