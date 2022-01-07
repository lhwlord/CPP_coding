// 앞으로는 경고 무시하고 scanf를 잘 사용할 것(실무에서 이렇게 한다고 한다)
// 속도의 문제 때문에 cin을 쓸 수 없으며, cin.tie는 거의 싱글스레드 용이라서 더더욱 쓸 수 없다.
// 또한 gcc가 scanf를 갱신하지 않는 한, 계속 이걸 쓸 수밖에 없는 것이다.
// scanf형태를 안쓸 것이라면 아예 getchar로 받아다가 - '0' 이걸 해야 하는데, 정수 입력과 처리가 빈번한 상황에서 이걸 계속 한다? 글쎄.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 배추 그리드를 받아다가 뽑는다. 상하좌우에 배추가 있다면 재귀.
void countBachu(vector<vector<bool>> &arr, int row, int col)
{
	arr[row][col] = false;
	if (row > 0 && arr[row - 1][col]) countBachu(arr, row - 1, col);
	if (col > 0 && arr[row][col - 1]) countBachu(arr, row, col - 1);
	if (row < arr.size() - 1 && arr[row + 1][col]) countBachu(arr, row + 1, col);
	if (col < arr[row].size() - 1 && arr[row][col + 1]) countBachu(arr, row, col + 1);
	return;
}


// 배추밭에 배추 배치에 따른 최소 배추지렁이 마리수.
int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int x, y, num;
		scanf("%d %d %d", &x, &y, &num);
		vector<vector<bool>> arr(x, vector<bool>(y, false));
		while (num--)
		{
			int bachu_x, bachu_y;
			scanf("%d %d", &bachu_x, &bachu_y);
			arr[bachu_x][bachu_y] = true;
		}

		// 그리드 돌면서 1 만나면 지우는 함수 실행
		int count = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (arr[i][j] == true)
				{
					countBachu(arr, i, j);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}