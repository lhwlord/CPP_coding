#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element* data;	// data�迭�� �ƴ� ������ ���·� ����
	int capacity;	// ũ�⿡ �����ϴ� ����. �����Ҵ翡 ����
	int top;
}StackType;

void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element));	// malloc�� ������ �ּҸ� �����Ҵ�
}

void push(StackType* s, element item)
{
	if (is_full(s))	// �� á���� ��������� �ƴ�, �޸� ���Ҵ��� ���� �ذ��ϱ�
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}