#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int age;
	double gpa;
} student;


void main()
{
	student* p;
	p = (student*)malloc(sizeof(student));
	if (p == NULL)
	{
		fprintf(stderr, "�޸𸮾��� �ù�\n");
		exit(1);
	}
	strcpy_s(p->name, 10, "Park");	// ���⼭�� ���������� ���� �ּҰ� �ʿ������� name�� ���ʿ� �迭�̶� �ּҹ�ȯ�� �ȴ�.
	p->age = 20;
	free(p);
	return;
}