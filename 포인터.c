#include<stdio.h>
#define SIZE 6

void get_integers(int list[])	// 6���� ���� �Է¹޴� ��. �����̽��ٷ� ������ �� �ִ�.
{
	printf("6���� ������ �Է��Ͻÿ�: ");
	for (int i = 0; i < SIZE; i++)
	{
		scanf_s("%d", (list + i));	// �������� ��ĵ�Լ�. �� ��� ������ �ּ� ���� �Ѱܾ� ������ ���� ȣ��� ���� ������ �� �ִ�.
	}
}

int cal_sum(int list[])	// �հ� ���ϴ� ��.
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
	printf("�� = %d \n", cal_sum(list));
	return;
}