#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {		// ��ü!
	short r;
	short c;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	// return [code �ۼ�] : 4.����-1 13p ����
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	// return [code �ۼ�] : 4.����-1 13p ����
	return (s->top == MAX_STACK_SIZE - 1);
}
// �����Լ�
void push(StackType* s, element item)
{
	// if [code �ۼ�] : 4.����-1 14p ����
	// else [code �ۼ�]
	if (is_full(s)) { fprintf(stderr, "����\n"); exit(1); }
	else
		s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	// if [code �ۼ�] : 4.����-1 14p ����
	// else [code �ۼ�]
	if (is_empty(s)) { fprintf(stderr, "����\n"); exit(1); }
	else
		return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 


element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};
// ��ġ�� ���ÿ� ����
void push_loc(StackType* s, int r, int c)
{
	// [code �ۼ�] : 4.����-2 17p ����
	element tmp;
	tmp.r = r; tmp.c = c;
	if (r <= 0 || r >= MAZE_SIZE || c <= 0 || c >= MAZE_SIZE) return;
	if (maze[r][c] == '0' || maze[r][c] == 'x') push(s, tmp); return;
}
// �̷θ� ȭ�鿡 ����Ѵ�. 
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	// [code �ۼ�] : 4.����-2 17p ����
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
		// [code �ۼ�] : 4.����-2 18p ����
		maze[here.r][here.c] = '.';
		push_loc(&s, here.r + 1, here.c);
		push_loc(&s, here.r - 1, here.c);
		push_loc(&s, here.r, here.c + 1);
		push_loc(&s, here.r, here.c - 1);
		maze_print(maze);
		if (is_empty(&s)) {
			printf("����\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("����\n");
	return 0;
}