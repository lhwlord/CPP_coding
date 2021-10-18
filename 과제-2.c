#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ 
void init_deque(DequeType* q)
{
	// [code �ۼ�] : 5.ť-2 8p ����
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(DequeType* q)
{
	// return [code �ۼ�] : 5.ť-2 9p ����
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(DequeType* q)
{
	// return [code �ۼ�] : 5.ť-2 9p ����
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

// ����ť ��� �Լ�
void deque_print(DequeType* q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		// [code �ۼ�] : 5.ť-2 9p ����
		int i = q->front;
		printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (1); 	//i != q->front �̰� ���ְ� �غ���. �ɰŰ�����.
	}
	printf("\n");
}

// ���� �Լ�
void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	// [code �ۼ�] : 5.ť-2 10p ����
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element delete_front(DequeType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	// [code �ۼ�] : 5.ť-2 10p ����
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �Լ�
element get_front(DequeType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	// return [code �ۼ�] : 5.ť-2 11p ����
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	// [code �ۼ�] : 5.ť-2 11p ����
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	// [code �ۼ�] : 5.ť-2 12p ����
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	// return [code �ۼ�] : 5.ť-2 12p ����
	return q->data[q->rear];
}

int main(void)
{
	DequeType queue;

	init_deque(&queue);
	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}