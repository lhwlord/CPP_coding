#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
// malloc를 쓰기 위한 추가적인 2개의 라이브러리.
#define SIZE 10


void main(void)
{
	int* p;
	p = (int*)malloc(SIZE * sizeof(int));	// 배열
	if (p == NULL)
	{
		fprintf(stderr, "메모리 부족. 할당 불가.\n");
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
