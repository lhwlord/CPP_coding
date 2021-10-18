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
			cout << "유효하지 않은 입력 : " << a << endl;
			break;
		}
	}
	cout << "종료." << endl;
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
		cout << "더 이상 넣을 수 없습니다 : " << x << endl;
	else
	{
		q->end = (q->end + 1) % MAX;
		q->q[q->end] = x;
		(q->count)++;
		//나중에 지울 것
		cout << "원형큐에 " << x << "삽입 완료." << endl;
	}

}

int deQ(queue* q)	// 제거와 반환을 동시에
{
	int x;
	if (isE(q))
	{
		cout << "더 이상 뺄 수 없습니다." << endl;
		return NULL;
	}
	else
	{
		x = q->q[q->start];
		q->start = (q->start + 1) % MAX;
		(q->count)--;
		//나중에 지울 것
		cout << "원형큐에서 " << x << "제거 및 반환 완료." << endl;
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