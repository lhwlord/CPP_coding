#define MAX_DEGREE 101 // 다항식의 최대 차수 + 상수항 1
#include <stdio.h>

typedef struct {
	int degree;			// 방정식의 차수.
	float coef[MAX_DEGREE];
}poly;

poly poly_add(poly a, poly b)	//다항식 덧셈. 창기짱 거보다 간단하게 짜볼까?
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

void show(poly p)	// 다항식 출력. 굳이 메인쪽에 이거 3번씩 반복하기 싫어서.
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

	printf("a 다항식 : ");
	show(a);
	printf("\n");
	printf("b 다항식 : ");
	show(b);
	printf("\n");

	printf("a + b = ");
	c = poly_add(a, b);
	show(c);

}