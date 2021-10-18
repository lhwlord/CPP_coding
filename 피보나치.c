#include <stdio.h>


int cal(int n)
{
	int a = 0, b = 1, result = 0;
	if (n == 0) return 0;
	if (n == 1) return 1;

	for (int i = 2; i <= n; i++)
	{
		result = a + b;
		a = b;
		b = result;
	}

	return result;
}

void main(void)
{
	printf("%d\n", cal(10));
	return;
}