#include <stdio.h>

void hanoi(int level, char A, char B, char C) {
	if (level <= 0)
	{
		printf("������ ����.\n"); return;
	}
	if (level == 1)
	{
		printf("1�� %C���� %C�� �̵�.\n", A, C);	// ��������� �������� ����.
	}
	else
	{
		hanoi(level - 1, A, C, B);	// �� ������ �ӽ� ����� �ű��.
		printf("%d�� %c���� %c�� �̵�.\n", level, A, C);// ���� ���� ū �ܰ��� ������ �������� �ű��. ���� �̰� ����� �� �����̶�� �ӽ� ���밡 �������� �Ǵ� ��.
		hanoi(level - 1, B, A, C);	// ���� ������ �Ű����� ���� ������ ���� �������� �������� ����.
	}

	return;
}

void main(void)
{
	hanoi(4, 'A', 'B', 'C');
}