#include <iostream>
#define MAX 10

using namespace std;

typedef struct {
	int q[MAX];
	int start;
	int end;
	int count;

} queue;

void initQ(queue*);
void enQ(queue*, int);
int deQ(queue*);
bool isE(queue*);
bool isF(queue*);

int main()
{
	queue q;
	initQ(&q);
	bool loop = true;
	while (loop)
	{
		int a, b;
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			scanf_s("%d", &b);
			enQ(&q, b);
			break;
		case 2:
			deQ(&q);
			break;
		case 3 : 
			loop = false;
			break;
		default : 
			cout << "��ȿ���� ���� �Է� : " << a << endl;
			break;
		}
	}
	cout << "����." << endl;
	return 0;
}

void initQ(queue* q)
{
	q->start = 0;
	q->end = MAX - 1;
	q->count = 0;
}

void enQ(queue* q, int x)
{
	if (isF(q))
		cout << "�� �̻� ���� �� �����ϴ� : " << x << endl;
	else
	{
		q->end = (q->end + 1) % MAX;
		q->q[q->end] = x;
		(q->count)++;
		//���߿� ���� ��
		cout << "����ť�� " << x << "���� �Ϸ�." << endl;
	}

}

int deQ(queue* q)	// ���ſ� ��ȯ�� ���ÿ�
{
	int x;
	if (isE(q))
	{
		cout << "�� �̻� �� �� �����ϴ�." << endl;
		return NULL;
	}
	else
	{
		x = q->q[q->start];
		q->start = (q->start + 1) % MAX;
		(q->count)--;
		//���߿� ���� ��
		cout << "����ť���� " << x << "���� �� ��ȯ �Ϸ�." << endl;
		return x;
	}
}

bool isE(queue* q)
{
	return q->count == 0 ? true : false;
}

bool isF(queue* q)
{
	return q->count == MAX ? true : false;
}