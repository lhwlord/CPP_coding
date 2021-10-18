#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element* data;	// data배열이 아닌 포인터 형태로 선언
	int capacity;	// 크기에 관여하는 변수. 동적할당에 쓰임
	int top;
}StackType;

void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element));	// malloc로 포인터 주소를 동적할당
}

void push(StackType* s, element item)
{
	if (is_full(s))	// 다 찼더라도 에러출력이 아닌, 메모리 재할당을 통해 해결하기
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}