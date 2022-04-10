#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Node	// ���.
{
private:
	float value;	// ���ο� ���� ��
	Node* next;		// ���� ��� �ּ�
public:
	Node(float num)	// ������.
	{
		value = num;
		next = NULL;
		printf("��� ����.\n");
	}
	Node()	// ������(�� ä�� �����ϴ� ���)
	{
		Node(0.0);
	}

	~Node()
	{
		printf("��� �Ҹ�.\n");
	}

	void printNode()	// ��尡 ���� �� ���
	{
		printf("����� ���� %.1f\n", value);
	}

	float getValue()	// ����� �� ��������
	{
		return value;
	}

	void setValue(float num)	// ����� �� ����
	{
		value = num;
	}

	Node* getNext()	// ���� ��� ��������
	{
		return next;
	}

	void setNext(Node* nextNode)	// ���� ��� ����
	{
		next = nextNode;
	}
};


class LinkedList // ���Ḯ��Ʈ.
{
private:
	Node* start;	// ���Ḯ��Ʈ�� ���������� �����ΰ�?
	Node* end;		// ���Ḯ��Ʈ�� ������ ����ΰ�?
	int size;	// ���Ḯ��Ʈ ���� ��� ����

public:
	LinkedList()	// ������
	{
		start = NULL;
		end = NULL;
		size = 0;
		printf("���Ḯ��Ʈ ����.\n");
	}
	~LinkedList()	// �Ҹ���. ��, ���� ��尡 new�� ����Ǿ����Ƿ� �̵��� ���� ���־� �Ѵ�.
	{
		Node* prev = NULL, *n;
		for (n = start; n != NULL; n = n->getNext())
		{
			if (n != start) delete prev;	// ������������ new�� ����Ǿ����� �޸� �Ҵ��� �����ؾ� �Ѵ�.
			prev = n;
		}
		delete end;	// for�� ���� �� ������ ��带 ���� �����ؾ� �Ѵ�.
		printf("���Ḯ��Ʈ �Ҹ�.\n");
	}

	void add(Node* n)	// ���Ḯ��Ʈ ���� �� ��� �ֱ�
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

	void insert(int index, Node* n)	// ���Ḯ��Ʈ Ư����ġ�� ��� ����
	{
		if (index >= size)	// size �̻��̸� �ε��� ���� �ʰ�
		{
			printf("�ε��� ���� �ʰ�. �۾�����.\n"); return;
		}

		if (index == 0)	// ó���� �߰�
		{
			n->setNext(start);
			start = n;
			size++;
		}
		else if (index == size)	// �������� �߰� : add �̿�
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

	void remove(int index)	// Ư�� ��ġ�� ��� ����
	{
		if (index > size)
		{
			printf("�ε��� ���� �ʰ�. �۾�����.\n"); return;
		}

		if (index == 0)	// ó�� ����
		{
			Node* temp = start;
			start = start->getNext();
			size--;

			delete temp;	// �޸� ����
		}
		else
		{
			Node* temp = start;
			for (int i = 1; i < index; i++)
			{
				temp = temp->getNext();
			}
			// ������ ���� �����ϴ� ��� 
			if (index == size - 1) end = temp;

			Node* delete_temp = temp->getNext();

			temp->setNext(temp->getNext()->getNext());
			size--;

			delete delete_temp;	// �޸� ����
		}
	}

	void remove_find(float num)	// Ư�� ���� ���� ��带 ���� ����
	{
		Node* temp = start, *temp2;

		for (int index = 0; temp != NULL; index++)
		{
			temp2 = temp->getNext();	// ��尡 if�� �ȿ��� �Ҹ�Ǵ� ���, temp�� �������� ���մ´�.
			if (temp->getValue() == num)
			{
				remove(index);
				index--;
			}
			temp = temp2;
		}
	}

	void setNode(int index, float num)	// Ư�� ��ġ�� ��� �� ����
	{
		if (index > size)	// �ε��� �ʰ�
		{
			printf("�ε��� ���� �ʰ�. �۾�����.\n"); return;
		}

		Node* temp = start;
		for (int i = 0; i < index; i++)
		{
			temp = temp->getNext();
		}
		temp->setValue(num);
	}

	void printNodes()	// ����Ʈ �� ��� ���
	{
		printf("���Ḯ��Ʈ�� ��� ��� ���� ���ʷ� ����մϴ�.\n============\n");
		for (Node* n = start; n != NULL; n = n->getNext())
		{
			n->printNode();
		}
		printf("============\n");
	}

	int getSize()	// ����Ʈ�� ũ�� ��ȯ
	{
		return size;
	}
};

//main�Լ����� ���� �ڵ带 �ۼ��� ��
//- ��ũ�帮��Ʈ ��ü ����
//- 100.1 ����
//- 200.2 ����
//- 300.3 ����
//- 500.5 ����
//- 400.4�� 3�� 5 ���̿� ����
//- 300.3 ���� ã�� ����
//- 2° ����Ʈ�� �� ����
//- ù �� ����
//- ù ���� 202.1�� ����
//- 2° ������ 202.2 ����
//- ������ ��� ����
//- �׷��� ���� ��� ���
int main(void)
{
	LinkedList list;
	list.add(new Node(100.1)); //list.printNodes();	// �� �ܰ� Ȯ�� ����
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