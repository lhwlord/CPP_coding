#include <iostream>
#include <string>

using namespace std;

void find(char**, string, int, int);
bool check(int, int, char**, string, int, int, int, int);

// 단어찾기 프로그램.
// 입력 : 테스트 횟수, 엔터, 가로 세로, 그만큼의 그리드, 찾을 낱말 수, 낱말 목록.
// 출력 : 각 낱말의 첫글자가 처음으로 등장하는(상단/좌측) 좌표.
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
				//입력받은 그리드의 대소문자 통일
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
			// 입력받은 스트링의 대소문자 통일
			for (int k = 0; k < str[j].length(); k++)
				if (isupper(str[j][k])) str[j][k] = tolower(str[j][k]);
		}
		cin.ignore(1, '\0');
		//본격적인 작업.
		for (int j = 0; j < wordCount; j++) find(arr, str[j], row, col);
		//동적할당 메모리 해제
		for (int j = 0; j < row; j++) delete arr[j];
		delete[] arr;
	}
	return 0;
}

// 2차원 배열에서 s가 있는지를 검사, 있다면 처음 나오는 좌표값을 그대로 화면에 출력.
void find(char** arr, string s, int row, int col)
{
	int i, j;
	int dir[8][2] = { {-1,-1},{0,-1},{+1,-1},{-1,0},{-1,+1},{+1,-1},{+1,0},{+1,+1} };

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			// 첫자를 찾았다면 8방향을 돌며 해당 방향이 가능한지부터 검사.
			if (s[0] == arr[i][j])
			{
				// 목표 방향으로 진행할 수 있으며, 문자열이 확보되는가를 먼저 보고, 맞다면 실제로 체크까지 하는 함수. 체크가 참이면 바로 빠져나온다.
				for (int k = 0; k < 8; k++)
						if (check(dir[k][0], dir[k][1], arr, s, i, j, row, col)) goto EXIT;
			}
		}
	}
	// 배열을 끝까지 돌렸는데도 맞는 값이 없다면
	cout << "일치하는 값이 없습니다.\n";
	goto END;
EXIT : 
	cout << i + 1 << ' ' << j + 1 << endl;
END : 
	return;
}

// arr의 x,y 위치에서 toX, toY 방향에 s가 존재할 수 있는지 검사.
bool check(int toX, int toY, char** arr, string s, int x, int y, int row, int col)
{
	if (!((0 <= (x + ((s.length()-1) * toX)) && (x + ((s.length()-1) * toX)) < row) && (0 <= (y + ((s.length()-1) * toY)) && (y + ((s.length()-1) * toY)) < col))) return false;   // 범위 벗어남
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != arr[x + (toX * i)][y + (toY * i)]) return false;	// 값이 다름
	}
	return true;
}