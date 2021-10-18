#include <stdio.h>
#define MAX_TERMS 100
typedef struct {
	int row;	//행 인덱스값
	int col;	//열 인덱스값
	int value;	//해당 인덱스에 있는 요소값
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	//쓰인 행렬의 행의 개수
	int cols;	//쓰인 행렬의 열의 개수
	int terms;	//항의 갯수를 저장한다.
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
	SparseMatrix b;
	int bindex;	//행렬 b에서 현재 저장 위치
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;	//여기까지의 대입은 형식적인 대입이다. 밑에꺼가 실제 데이터 옮기는거.
	if (a.terms > 0)
	{
		bindex = 0;
		for (int c = 0; c < a.cols; c++)	//c값은 a의 열 값이다. 이걸 돌리면서 낮은 열부터 탐색한다.
		{
			for (int i = 0; i < a.terms; i++)	//i값은 행렬 데이터를 탐색하기 위해 쓰인다.
			{
				if (a.data[i].col == c)	//간단히 말해 현재 탐색중인 낮은 열번호에 부합하는 열값을 지닌 데이터부터 차례대로 뽑겠다는 것. 뽑혔다면 저장하고, 저장되는 b의 인덱스번호를 올려 다음 인덱스에 저장할 수 있도록.
				{
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a)
{
	printf("=============================\n");
	for (int i = 0; i < a.terms; i++)
	{
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("=============================\n");
}

void main()
{
	SparseMatrix m = { {{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}}, 6, 6, 7 };
	SparseMatrix result;

	matrix_print(m);
	result = matrix_transpose2(m);
	matrix_print(result);

	return;
}