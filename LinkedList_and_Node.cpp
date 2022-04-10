#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Node	// 노드.
{
private:
	float value;	// 내부에 가질 값
	Node* next;		// 다음 노드 주소
public:
	Node(float num)	// 생성자.
	{
		value = num;
		next = NULL;
		printf("노드 생성.\n");
	}
	Node()	// 생성자(빈 채로 생성하는 경우)
	{
		Node(0.0);
	}

	~Node()
	{
		printf("노드 소멸.\n");
	}

	void printNode()	// 노드가 갖는 값 출력
	{
		printf("노드의 값은 %.1f\n", value);
	}

	float getValue()	// 노드의 값 가져오기
	{
		return value;
	}

	void setValue(float num)	// 노드의 값 설정
	{
		value = num;
	}

	Node* getNext()	// 다음 노드 가져오기
	{
		return next;
	}

	void setNext(Node* nextNode)	// 다음 노드 설정
	{
		next = nextNode;
	}
};


class LinkedList // 연결리스트.
{
private:
	Node* start;	// 연결리스트의 시작지점이 누구인가?
	Node* end;		// 연결리스트의 끝점이 어디인가?
	int size;	// 연결리스트 내부 노드 개수

public:
	LinkedList()	// 생성자
	{
		start = NULL;
		end = NULL;
		size = 0;
		printf("연결리스트 생성.\n");
	}
	~LinkedList()	// 소멸자. 단, 내부 노드가 new로 선언되었으므로 이들을 전부 없애야 한다.
	{
		Node* prev = NULL, *n;
		for (n = start; n != NULL; n = n->getNext())
		{
			if (n != start) delete prev;	// 우측값이지만 new로 선언되었으니 메모리 할당을 해제해야 한다.
			prev = n;
		}
		delete end;	// for문 구조 상 마지막 노드를 따로 해제해야 한다.
		printf("연결리스트 소멸.\n");
	}

	void add(Node* n)	// 연결리스트 끝에 새 노드 넣기
	{
		if (size == 0)
		{
			start = n;
			end = n;
			size++;
		}
		else
		{
			end->setNext(n);
			end = n;
			size++;
		}
	}

	void insert(int index, Node* n)	// 연결리스트 특정위치에 노드 삽입
	{
		if (index >= size)	// size 이상이면 인덱스 범위 초과
		{
			printf("인덱스 범위 초과. 작업실패.\n"); return;
		}

		if (index == 0)	// 처음에 추가
		{
			n->setNext(start);
			start = n;
			size++;
		}
		else if (index == size)	// 마지막에 추가 : add 이용
		{
			add(n);
		}
		else
		{
			Node* temp = start;
			for (int i = 1; i < index; i++)
			{
				temp = temp->getNext();
			}
			n->setNext(temp->getNext());
			temp->setNext(n);
			size++;
		}
	}

	void remove(int index)	// 특정 위치의 노드 제거
	{
		if (index > size)
		{
			printf("인덱스 범위 초과. 작업실패.\n"); return;
		}

		if (index == 0)	// 처음 제거
		{
			Node* temp = start;
			start = start->getNext();
			size--;

			delete temp;	// 메모리 해제
		}
		else
		{
			Node* temp = start;
			for (int i = 1; i < index; i++)
			{
				temp = temp->getNext();
			}
			// 마지막 값을 제거하는 경우 
			if (index == size - 1) end = temp;

			Node* delete_temp = temp->getNext();

			temp->setNext(temp->getNext()->getNext());
			size--;

			delete delete_temp;	// 메모리 해제
		}
	}

	void remove_find(float num)	// 특정 값을 가진 노드를 전부 제거
	{
		Node* temp = start, *temp2;

		for (int index = 0; temp != NULL; index++)
		{
			temp2 = temp->getNext();	// 노드가 if문 안에서 소멸되는 경우, temp는 오류값을 내뿜는다.
			if (temp->getValue() == num)
			{
				remove(index);
				index--;
			}
			temp = temp2;
		}
	}

	void setNode(int index, float num)	// 특정 위치의 노드 값 변경
	{
		if (index > size)	// 인덱스 초과
		{
			printf("인덱스 범위 초과. 작업실패.\n"); return;
		}

		Node* temp = start;
		for (int i = 0; i < index; i++)
		{
			temp = temp->getNext();
		}
		temp->setValue(num);
	}

	void printNodes()	// 리스트 내 노드 출력
	{
		printf("연결리스트의 모든 노드 값을 차례로 출력합니다.\n============\n");
		for (Node* n = start; n != NULL; n = n->getNext())
		{
			n->printNode();
		}
		printf("============\n");
	}

	int getSize()	// 리스트의 크기 반환
	{
		return size;
	}
};

//main함수에선 다음 코드를 작성할 것
//- 링크드리스트 객체 생성
//- 100.1 삽입
//- 200.2 삽입
//- 300.3 삽입
//- 500.5 삽입
//- 400.4를 3과 5 사이에 삽입
//- 300.3 값을 찾아 제거
//- 2째 리스트의 값 제거
//- 첫 값 제거
//- 첫 값을 202.1로 변경
//- 2째 공간에 202.2 삽입
//- 마지막 노드 제거
//- 그렇게 남은 노드 출력
int main(void)
{
	LinkedList list;
	list.add(new Node(100.1)); //list.printNodes();	// 각 단계 확인 가능
	list.add(new Node(200.2)); //list.printNodes();
	list.add(new Node(300.3)); //list.printNodes();
	list.add(new Node(500.5)); //list.printNodes();
	list.insert(3, new Node(400.4)); //list.printNodes();
	list.remove_find(300.3); //list.printNodes();
	list.remove(1); //list.printNodes();
	list.remove(0); //list.printNodes();
	list.setNode(0, 202.1); //list.printNodes();
	list.insert(1, new Node(202.2)); //list.printNodes();
	list.remove(list.getSize() - 1); //list.printNodes();
	list.printNodes();
}