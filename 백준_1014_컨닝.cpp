#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 백준 #1014 : 컨닝
int main(void)
{
	int C_;
	scanf("%d", &C_);
	while (C_--)
	{
		int row, col;
		scanf("%d %d", &row, &col);
		getchar();

		
		vector<vector<char>> table(row + 1, vector<char>(col + 1, 'W'));
		int bitmask = 1 << row;// 행개수만큼 마스킹할 비트 증가
		
		for (int i = 1; i <= row; i++) // 입력
		{
			for (int j = 1; j <= col; j++) // 입력
			{
				scanf("%c", &table[i][j]);
			}
			getchar();
		}

		// 장애물 비트 생성
		vector<int> obstacle(col + 1);
		for (int i = 1; i <= col; i++)
		{
			int mask = 0, times = 1;
			for (int j = row; j >= 1; j--)
			{
				if (table[j][i] == 'x') mask += times;
				times *= 2;
			}
			obstacle[i] = mask;
		}

		// dp[i][j] = i-1째 배치가 j형태일 때, i열의 배치와 기대값
		vector<vector<pair<int, int>>> dp(col + 1, vector<pair<int, int>>(bitmask, pair<int,int>(-1,-1)));	// 0번은 안쓰고, 1번은 미리 정의한다.

		// 1번행 미리 정의. 첫 루프의 장애물에 걸리는지만 확인할 것
		for (int i = 0; i < bitmask; i++)
		{
			//dp[1][i].first = i;
			//dp[1][i].second = 0;

			int bit_col = i;
			int bit_table = obstacle[1];
			for (int j = 0; j < row; j++)
			{
				if ((bit_col & 1) && (bit_table & 1))
				{
					dp[1][i].first = -1;
					dp[1][i].second = -10000;
					goto out;
				}
				bit_col >>= 1;
				bit_table >>= 1;
			}
			dp[1][i].first = i;
			dp[1][i].second = 0;
		out:;
		}

		// 2번행부터 dp 시작
		for (int i = 2; i < col + 1; i++)
		{
		
			for (int j = 0; j < bitmask; j++)
			{
				// 1. 열값인 이전상태가 장애물에 안걸리는 상태인가? (장애물과의 비트마스킹, 여기에 걸리면 바로 -1로 지정)
				// 열 개수만큼 돌면서, 끝부분 확인하고 2로 나누기.
				int bit_col = j;
				int bit_table = obstacle[i - 1];
				bool check = false;
				for (int k = 0; k < row; k++)
				{
					int temp_a = bit_col & 1;	// 2의 나머지연산
					int temp_b = bit_table & 1;
					if (temp_a & temp_b)
					{
						dp[i][j].first = -1;
						dp[i][j].second = -10000;	// 필요없을수도
						// 넘겨야 한다.
						check = true;
						break;
					}
					bit_col >>= 1;
					bit_table >>= 1;	// 2 나눔
				}
				if (check) continue;

				// 2. 이전상태가 가능하다면, 그곳에서 최대 조합은? (이전상태에서 앉아있는 자리마다 한칸씩 위아래로 조지고, 추가로 장애물까지 안되게 하고 나머지 값 넣기)
				// 장애물(1)이 있으면 결과값에도 1을 놓고, dp에 넣을땐 반전.
				int max_result = 0;
				int start_point = 1;
				bit_col = j;
				for (int k = 0; k < row; k++)
				{
					if (bit_col & 1)	// 열비트의 첫 값이 1, 즉 이미 있으면
					{	// 현재 위치와 앞뒤로 1 넣기
						max_result |= start_point;
						max_result |= start_point >> 1;
						max_result |= start_point << 1;
					}
					start_point <<= 1;
					bit_col >>= 1;
				}
				// 장애물 첨가 후, MSB 클램핑 및 반전
				max_result |= obstacle[i];
				max_result &= bitmask - 1;
				max_result = bitmask - 1 - max_result;
				dp[i][j].first = max_result;

				// 3. 최대 조합이 가능한 기대값은? (이전상태 인원 + 이전상태를 포함하는 이전 열의 셀의 최대 기대값 = 현재 셀의 기대값)
				int expect = -1;
				for (int k = 0; k < bitmask; k++)	// 현재 j값 비트와 이전 열의 비트끼리 비교한다.
				{ // 둘이 or연산 해서 이전 열의 비트가 나온다면, 먹어도 되는 셀이다. 해당 셀의 기대값을 expect에 최대갱신하고, 빠져나와서 max에 j의 1값 추가 후 현 셀에 대입.
					if ((j | dp[i - 1][k].first) == dp[i - 1][k].first)
					{
						if (dp[i - 1][k].second > expect) expect = dp[i - 1][k].second;
					}
				}
				
				bit_col = j;
				for (int k = 0; k < row; k++)
				{
					expect += bit_col & 1 ? 1 : 0;
					bit_col >>= 1;
				}

				dp[i][j].second = expect;
			
			}

		}

		// 4. 마지막까지 진행 후, 마지막 행의 기대값 + 인원 최대 수치를 계산해서 그 최대값 반환.
		int max_final = -1;
		for (int i = 0; i < bitmask; i++)
		{
			int bit_col = dp[col][i].first;
			int sitted = 0;
			for (int j = 0; j < row; j++)
			{
				sitted += bit_col & 1 ? 1 : 0;
				bit_col >>= 1;
			}
			sitted += dp[col][i].second;

			if (max_final < sitted) max_final = sitted;
		}


		// 출력
		printf("%d\n", max_final);
	}
	return 0;
}