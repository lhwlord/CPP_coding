#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
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

// ��ȣ�˻�
int check_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);	// n = ���ڿ��� ����
	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];
		switch (ch)
		{
		case '(': case '[': case '{':
			push(&s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(&s)) return 0;
			else
			{
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
					return 0;
			}
			break;
		}
	}
	if (!is_empty(&s)) return 0;	//���ÿ� ��ȣ�� �����ִٸ� ����
	return 1; // ��� �˻簡 ������ �� �̻��� ������ �� ��ȯ
}

void main()
{
	// �����Ҵ��ϴ� ���.
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

	printf("�̹��� ��ȣ�˻縦 �غ���.\n");
	
	char* p = "{A[(i+1)]=0;}";
	if (check_matching(p) == 1) printf("%s�� ���� ��ȣ�˻� �̻����\n", p);
	else printf("%s�� ���� ��ȣ�˻� �����߰�\n", p);
	
	return;
}

