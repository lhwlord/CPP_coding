#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
// malloc�� ���� ���� �߰����� 2���� ���̺귯��.
#define SIZE 10


void main(void)
{
	int* p;
	p = (int*)malloc(SIZE * sizeof(int));	// �迭
	if (p == NULL)
	{
		fprintf(stderr, "�޸� ����. �Ҵ� �Ұ�.\n");
		exit(1);
	}
	for (int i = 0; i < SIZE; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", p[i]);
	}
	free(p);
	return;		
}
