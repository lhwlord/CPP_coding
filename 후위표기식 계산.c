#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
	element* data;	// data�迭�� �ƴ� ������ ���·� ����
	int capacity;	// ũ�⿡ �����ϴ� ����. �����Ҵ翡 ����
	int top;
}StackType;

// ���� �ʱ�ȭ �Լ�. �����ͷ� ���� �ּҿ� ����
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element));	// malloc�� ������ �ּҸ� �����Ҵ�
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (s->capacity - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s))	// �� á���� ��������� �ƴ�, �޸� ���Ҵ��� ���� �ذ��ϱ�
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
		if (s->data == 0) fprintf(stderr, "�޸� ����\n");
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "������ �������.\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s; init_stack(&s);
	
	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - '0';	//char������ �ƽ�Ű�ڵ� ���� �������·� �ٲ�ٰ� �����ϸ� �ȴ��. �׷� ��� ����ǥ�⸦ �Է��� �� ���ڸ� ���ڸ� �� �� ���� ���̴�.
			push(&s, value);
		}
		else	// �������� ��� �ǿ����ڸ� ���ÿ��� �����ϰ� ���
		{	
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

void main()
{
	/*
	StackType* s;
	s = (StackType*)malloc(sizeof(StackType));
	printf("�����Ҵ� ���ñ���ü ������ Ȯ��\n");
	init_stack(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	free(s);	//�����Ҵ��ϸ� �̷��� ���� �� �ִ�.
	*/

	int result;
	printf("����ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("����� %d\n", result);

	return;
}

