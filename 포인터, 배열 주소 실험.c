#include<stdio.h>

void main(void)
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d %d %d\n", a, &a, &a[0]);
	printf("%d %d %d\n", a+1, &a[0]+1*(sizeof(int)), a+4);

	return;
}