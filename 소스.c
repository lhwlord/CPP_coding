#include <stdio.h>

int factorial(int n)
{
	if (n <= 1) return 1;
	else return (n * factorial(n - 1));
}

int factorial_iter(int n)
{
	int i, bigger = 1;
	for (i = 1; i <= n; i++)
		bigger *= i;

	return bigger;
}

int slow_power(double x, int n)
{
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++)
	{
		result *= x;
	}
	return result;
}

int power(int x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power(x ^ 2, n / 2);
	else return x * power(x ^ 2, (n - 1) / 2);
}

int fib(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else
		return fib(n - 2) + fib(n - 1);
}

long long int fib_iter(long long int n)
{
	if(n == 0) return 0;
	if (n == 1) return 1;

	long long int pp = 0;
	long long int p = 1;
	long long int result = 0;

	for (long long int i = 2; i <= n; i++)
	{
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)
	{
		printf("원판 1을 %c 에서 %c (으)로 옮긴다.\n", from, to);
	}
	else
	{
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을(를) %c 에서 %c (으)로 옮긴다\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int main()
{
	printf("%d\n", factorial(5));
	printf("성능좋은 성능좋은 성능좋은 성능좋은 성능좋은은은은은은은\n");
	printf("%d\n", factorial_iter(5));
	printf("3의 4제곱은 %d\n", slow_power(3, 4));
	printf("피보나치 순환함수로 계산한 10단계 피보나치 수 : %d\n", fib(10));
	printf("피보나치 반복문으로 계산한 50단계 피보나치 수 : %lld\n", fib_iter(50));
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}