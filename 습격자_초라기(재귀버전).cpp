#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int RESULT = 20000;	// 전역변수, 다른 함수들이 자유롭게 접근할 수 있다. 최종 결과.

// 비교 및 재귀를 통해 결과를 산출한다.
// 이전 단계에서의 배열을 가져오고, row와 col인덱스부터 계속 진행하며, 미니결과를 갱신한다.
// 비교가 전부 끝난 경우에 미니결과를 전역변수 RESULT와 비교하여 작은 값으로 갱신한다.
// 최종단계까지 함수반환이 끝난다면 RESULT는 각 분기 중 가장 작은 값으로 정해질 것이다.
void cal(int** arr, int index_row, int index_col, int mini_result, const int platoonNum, const int floorNum)
{

	int tempNum = floorNum;	// 기존에 _msize를 써서 직접 구했지만, 백준에서 VC++용 함수인 _msize를 지원하지 않는 관계로 인자를 따로 추가했으며, 그 과정에서 함수명 안바꾸고 그대로 대입
	//cout << "재귀 중 열 크기 찾기 : " << tempNum << "으로 나옴.\n";
	int** temp = new int* [2];
	temp[0] = new int[tempNum];
	temp[1] = new int[tempNum];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < tempNum; j++)
			temp[i][j] = arr[i][j];
	
	// 3방향에 대해 해당하는 구간이 있나 보고, 분기가 생기면 재귀.
	for (int i = index_row; i < 2; i++)
	{
		for (int j = index_col; j < tempNum; j++)
		{
			if (temp[i][j] != -1)	// 내가 -1, 즉 이미 매치된 상태라면 더 볼 필요도 없다.
			{
				bool leftPossible = false, rightPossible = false, otherSidePossible = false, matched = false;
				// 매치가 0개면 자기 자신만 바꾸고 끝내면 된다.
				// 매치가 1개 이상이면, 처음 뜨는 매치만 이 루프에서 수정하고 나머지는 재귀로 돌린다.

				// 좌측탐색.
				int toLeft = j == 0 ? tempNum - 1 : j - 1;
				if (temp[i][toLeft] != -1 && temp[i][toLeft] + temp[i][j] <= platoonNum)
					leftPossible = true;

				// 우측탐색.
				int toRight = j == tempNum - 1 ? 0 : j + 1;
				if (temp[i][toRight] != -1 && temp[i][toRight] + temp[i][j] <= platoonNum)
					rightPossible = true;

				// 반대행탐색.
				if (temp[1 - i][j] != -1 && temp[1 - i][j] + temp[i][j] <= platoonNum)
					otherSidePossible = true;
				
				mini_result++;		// -1은 아니니 적어도 1개 소대는 추가된다.
				temp[i][j] = -1;	// -1이 아니니 어느 상황에서도 나 자신은 바뀐다.

				// 숫자에 따라 분기를 적절히 작성한다.
				{
					int temp_i, temp_j, temp_val;	// 임시로 지정할 변수값. 처음으로 탐색되어 이 루프에서 진행하는 경우 여기에 들어간다.

					if (leftPossible)	// 첫 탐색이므로 matched 확인필요없음, 좌측가능인경우
					{
						matched = true;
						temp_i = i; temp_j = j; temp_val = temp[i][toLeft];
						temp[i][toLeft] = -1;
					}

					if (rightPossible)	// 우측가능인경우
					{
						if (!matched)
						{
							matched = true;
							temp_i = i; temp_j = j; temp_val = temp[i][toRight];
							temp[i][toRight] = -1;
						}
						else
						{
							// 매치된 값을 임시로 바꾼다.
							temp[temp_i][temp_j] = temp_val;
							cal(temp, i, j, mini_result, platoonNum, floorNum);
							// 매치된 값을 다시 -1로 돌려놓는다.
							temp[temp_i][temp_j] = -1;
						}
					}

					if (otherSidePossible)	// 반대방향가능인경우
					{
						if (!matched)
						{
							// matched = true; 매치됐는지 조건은 필요하지만 이 구문은 마지막이라 불필요. temp_i,j,val 또한 필요없음
							temp[1 - i][j] = -1;
						}
						else
						{
							// 매치된 값을 임시로 바꾼다.
							temp[temp_i][temp_j] = temp_val;
							cal(temp, i, j, mini_result, platoonNum, floorNum);
							// 매치된 값을 다시 -1로 돌려놓는다.
							temp[temp_i][temp_j] = -1;
						}
					}
				}
			}
		}
	}

	// 재귀반복문을 전부 빠져나왔다는 것은 배열을 전부 순회했다는 것.
	// mini_result를 대입하는 일만 남았다.
	RESULT = RESULT > mini_result ? mini_result : RESULT;

	return;

}

// 습격자 초라기 문제.
int main(void)
{
	///* 애초에 알고리즘의 문제라서, 입력시간을 좀 더 줄인다고 해서 결과가 바뀌진 않는다.
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

		// 비교&재귀를 통해 값 찾아내기
		cal(arr, 0, 0, 0, platoonNum, floorNum);

		//cout << "가장 적게 투입할 수 있는 소대 수는 " << RESULT << "입니다.\n";

		cout << RESULT << endl;
		
		for (int i = 0; i < 2; i++) delete[] arr[i];
		delete[] arr;
	}
	return 0;
}