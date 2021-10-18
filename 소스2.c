#define MAX_DEGREE 101 // ���׽��� �ִ� ���� + ����� 1
#include <stdio.h>

typedef struct {
	int degree;			// �������� ����.
	float coef[MAX_DEGREE];
}poly;

poly poly_add(poly a, poly b)	//���׽� ����. â��¯ �ź��� �����ϰ� ¥����?
{
	poly bigger, smaller, c;
	int biggerDegree, correction;

	if (a.degree > b.degree)
	{
		bigger = a;
		smaller = b;
	}
	else
	{
		bigger = b;
		smaller = a;
	}

	c = bigger;
	correction = bigger.degree - smaller.degree;

	for (int i = 0; i < smaller.degree + 1; i++)
	{
		c.coef[i + correction] += smaller.coef[i];
	}


	return c;
}

void show(poly p)	// ���׽� ���. ���� �����ʿ� �̰� 3���� �ݺ��ϱ� �Ⱦ.
{
	for (int i = p.degree; i >= 0; i--)
	{
		printf("%dx^%d ", (int)p.coef[p.degree - i], i);
		if (i == 0) break; else {};
		printf("+ ");
	}
	return;
}

int main(void)
{
	poly a = { 5, {10, 0, 0, 0, 6, 3} };
	poly b = { 7, {3, 2, 1, 0, 0, 0, 3, 6} };
	poly c;

	printf("a ���׽� : ");
	show(a);
	printf("\n");
	printf("b ���׽� : ");
	show(b);
	printf("\n");

	printf("a + b = ");
	c = poly_add(a, b);
	show(c);

}