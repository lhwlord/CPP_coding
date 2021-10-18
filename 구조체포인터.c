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
		fprintf(stderr, "메모리없어 시발\n");
		exit(1);
	}
	strcpy_s(p->name, 10, "Park");	// 여기서도 참조연산을 위해 주소가 필요하지만 name은 애초에 배열이라 주소반환이 된다.
	p->age = 20;
	free(p);
	return;
}