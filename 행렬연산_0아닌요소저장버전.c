#include <stdio.h>
#define MAX_TERMS 100
typedef struct {
	int row;	//�� �ε�����
	int col;	//�� �ε�����
	int value;	//�ش� �ε����� �ִ� ��Ұ�
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	//���� ����� ���� ����
	int cols;	//���� ����� ���� ����
	int terms;	//���� ������ �����Ѵ�.
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
	SparseMatrix b;
	int bindex;	//��� b���� ���� ���� ��ġ
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;	//��������� ������ �������� �����̴�. �ؿ����� ���� ������ �ű�°�.
	if (a.terms > 0)
	{
		bindex = 0;
		for (int c = 0; c < a.cols; c++)	//c���� a�� �� ���̴�. �̰� �����鼭 ���� ������ Ž���Ѵ�.
		{
			for (int i = 0; i < a.terms; i++)	//i���� ��� �����͸� Ž���ϱ� ���� ���δ�.
			{
				if (a.data[i].col == c)	//������ ���� ���� Ž������ ���� ����ȣ�� �����ϴ� ������ ���� �����ͺ��� ���ʴ�� �̰ڴٴ� ��. �����ٸ� �����ϰ�, ����Ǵ� b�� �ε�����ȣ�� �÷� ���� �ε����� ������ �� �ֵ���.
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