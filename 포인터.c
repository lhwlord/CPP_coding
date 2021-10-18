#include<stdio.h>
#define SIZE 6

void get_integers(int list[])	// 6개의 정수 입력받는 곳. 스페이스바로 구분할 수 있다.
{
	printf("6개의 정수를 입력하시오: ");
	for (int i = 0; i < SIZE; i++)
	{
		scanf_s("%d", (list + i));	// 오랜만의 스캔함수. 이 경우 변수의 주소 값을 넘겨야 참조에 의한 호출로 값을 변경할 수 있다.
	}
}

int cal_sum(int list[])	// 합계 구하는 곳.
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += list[i];
	}
	return sum;
}


void main(void)
{
	int list[SIZE];
	get_integers(list);
	printf("합 = %d \n", cal_sum(list));
	return;
}