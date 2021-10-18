#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

typedef struct {
	short r;
	short c;
}element;	// 좌표 타입.
typedef struct {
	element* data;	// 좌표 스택에 저장하는 형식
	int capacity;
	int top;
}StackType;

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

element here = { 1,0 }, entry = { 1,0 };	// 현재위치, 시작점

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1',}

};

void push_loc(StackType* s, int r, int c)	// 해당 좌표를 넣을수 있는 경우에 스택에 넣는 전용 함수
{
	if (r < 0 || c < 0) return;	// 진행불가능한 경우임
	if (maze[r][c] != '1' && maze[r][c] != '.')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) // 미로 출력
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++)
	{
		for (int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c ", maze[r][c]);
		}
		printf("\n");
	}
}

void main()
{
	int r, c;
	StackType s;
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s))
		{
			printf("실패\n");
			return;
		}
		else here = pop(&s);
	}
	printf("출구 찾았음. 성공.\n");
	return;
}

