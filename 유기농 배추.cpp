// �����δ� ��� �����ϰ� scanf�� �� ����� ��(�ǹ����� �̷��� �Ѵٰ� �Ѵ�)
// �ӵ��� ���� ������ cin�� �� �� ������, cin.tie�� ���� �̱۽����� ���̶� ������ �� �� ����.
// ���� gcc�� scanf�� �������� �ʴ� ��, ��� �̰� �� ���ۿ� ���� ���̴�.
// scanf���¸� �Ⱦ� ���̶�� �ƿ� getchar�� �޾ƴٰ� - '0' �̰� �ؾ� �ϴµ�, ���� �Է°� ó���� ����� ��Ȳ���� �̰� ��� �Ѵ�? �۽�.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// ���� �׸��带 �޾ƴٰ� �̴´�. �����¿쿡 ���߰� �ִٸ� ���.
void countBachu(vector<vector<bool>> &arr, int row, int col)
{
	arr[row][col] = false;
	if (row > 0 && arr[row - 1][col]) countBachu(arr, row - 1, col);
	if (col > 0 && arr[row][col - 1]) countBachu(arr, row, col - 1);
	if (row < arr.size() - 1 && arr[row + 1][col]) countBachu(arr, row + 1, col);
	if (col < arr[row].size() - 1 && arr[row][col + 1]) countBachu(arr, row, col + 1);
	return;
}


// ���߹翡 ���� ��ġ�� ���� �ּ� ���������� ������.
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

		// �׸��� ���鼭 1 ������ ����� �Լ� ����
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