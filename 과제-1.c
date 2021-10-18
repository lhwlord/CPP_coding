#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {		// 교체!
	short r;
	short c;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	// return [code 작성] : 4.스택-1 13p 참고
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	// return [code 작성] : 4.스택-1 13p 참고
	return (s->top == MAX_STACK_SIZE - 1);
}
// 삽입함수
void push(StackType* s, element item)
{
	// if [code 작성] : 4.스택-1 14p 참고
	// else [code 작성]
	if (is_full(s)) { fprintf(stderr, "에러\n"); exit(1); }
	else
		s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	// if [code 작성] : 4.스택-1 14p 참고
	// else [code 작성]
	if (is_empty(s)) { fprintf(stderr, "에러\n"); exit(1); }
	else
		return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 


element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};
// 위치를 스택에 삽입
void push_loc(StackType* s, int r, int c)
{
	// [code 작성] : 4.스택-2 17p 참조
	element tmp;
	tmp.r = r; tmp.c = c;
	if (r <= 0 || r >= MAZE_SIZE || c <= 0 || c >= MAZE_SIZE) return;
	if (maze[r][c] == '0' || maze[r][c] == 'x') push(s, tmp); return;
}
// 미로를 화면에 출력한다. 
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	// [code 작성] : 4.스택-2 17p 참조
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int r, c;
	StackType s;

	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		// [code 작성] : 4.스택-2 18p 참조
		maze[here.r][here.c] = '.';
		push_loc(&s, here.r + 1, here.c);
		push_loc(&s, here.r - 1, here.c);
		push_loc(&s, here.r, here.c + 1);
		push_loc(&s, here.r, here.c - 1);
		maze_print(maze);
		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("성공\n");
	return 0;
}