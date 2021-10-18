#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
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

// 괄호검사
int check_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);	// n = 문자열의 길이
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
	if (!is_empty(&s)) return 0;	//스택에 괄호가 남아있다면 오류
	return 1; // 모든 검사가 끝났을 때 이상이 없으면 참 반환
}

void main()
{
	// 동적할당하는 경우.
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

	printf("이번엔 괄호검사를 해보자.\n");
	
	char* p = "{A[(i+1)]=0;}";
	if (check_matching(p) == 1) printf("%s에 대한 괄호검사 이상없음\n", p);
	else printf("%s에 대한 괄호검사 오류발견\n", p);
	
	return;
}

