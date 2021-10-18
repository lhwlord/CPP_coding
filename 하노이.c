#include <stdio.h>

void hanoi(int level, char A, char B, char C) {
	if (level <= 0)
	{
		printf("원판이 없다.\n"); return;
	}
	if (level == 1)
	{
		printf("1을 %C에서 %C로 이동.\n", A, C);	// 출발지에서 목적지로 간다.
	}
	else
	{
		hanoi(level - 1, A, C, B);	// 밑 원판을 임시 막대로 옮긴다.
		printf("%d를 %c에서 %c로 이동.\n", level, A, C);// 현재 가장 큰 단계의 원판을 목적지로 옮긴다. 만약 이게 상대적 밑 원판이라면 임시 막대가 목적지가 되는 것.
		hanoi(level - 1, B, A, C);	// 상위 원판을 옮겼으니 하위 원판을 원래 목적지로 돌려놓을 차례.
	}

	return;
}

void main(void)
{
	hanoi(4, 'A', 'B', 'C');
}