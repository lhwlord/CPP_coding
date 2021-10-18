// 수업상 3, 3으로 넘어갔지만 행렬을 변경하는 과정에서 프린트함수를 고쳐야 한다.
// 시험공부해야되서 넘어간다.

#include <stdio.h>
#define ROWS 5
#define COLS 3

void matrix_transpose(int A[ROWS][COLS], int B[COLS][ROWS])
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			B[c][r] = A[r][c];
		}
	}
}

void matrix_print(int A[ROWS][COLS])
{
	printf("==============================\n");
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			printf("%d ", A[r][c]);
		}
		printf("\n");
	}
	printf("==============================\n");
}


void main(void)
{
	int a[ROWS][COLS] = { {2, 3, 0}, {8, 9, 1}, {7, 0, 5}, {9, 8, 7}, {6, 5, 4} };
	int b[COLS][ROWS];

	matrix_transpose(a, b);
	matrix_print(a);
	matrix_print(b);

	return;
}