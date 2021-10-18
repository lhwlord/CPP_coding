#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
	element* data;	// data배열이 아닌 포인터 형태로 선언
	int capacity;	// 크기에 관여하는 변수. 동적할당에 쓰임
	int top;
}StackType;

// 스택 초기화 함수. 포인터로 원본 주소에 접근
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element));	// malloc로 포인터 주소를 동적할당
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
	if (is_full(s))	// 다 찼더라도 에러출력이 아닌, 메모리 재할당을 통해 해결하기
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
		if (s->data == 0) fprintf(stderr, "메모리 누수\n");
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택이 비어있음.\n");
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
			value = ch - '0';	//char형태의 아스키코드 값을 숫자형태로 바꿨다고 생각하면 된댄다. 그럼 적어도 후위표기를 입력할 땐 한자리 숫자만 쓸 수 있을 것이다.
			push(&s, value);
		}
		else	// 연산자인 경우 피연산자를 스택에서 제거하고 계산
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
	printf("동적할당 스택구조체 정상동작 확인\n");
	init_stack(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	free(s);	//동적할당하면 이렇게 없앨 수 있다.
	*/

	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과는 %d\n", result);

	return;
}

