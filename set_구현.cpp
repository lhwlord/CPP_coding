#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// int ���� ���⿡ ���Ѵ�.
class IntElement {
private:
	int value; // ����Ʈ ���� ���� ����
	IntElement* next; // linked List�� ���� ������ �ּ� ����
public:
	// constructor
	IntElement(int val) 
	{
		value = val;
		next = NULL;
	} 

	// ��ü�� value �� return
	int getValue() 
	{
		return value;
	} 

	// ��ü�� next �� return
	IntElement* getNext() 
	{
		return next;
	} 

	// ��ü�� next �� ����
	void setNext(IntElement* element) 
	{
		next = element;
	}
};

// int�� ���� ���ҷ� ���� ����. ���� �������, ���� ���� �����Ѵ�.
// ���� ���� ���Ҹ� ���� �� Set�� ���ٰ� �����Ѵ�.
// ���Ḯ��Ʈ ������ int ���Ҹ� �����ϸ�, int���ҵ��� IntElement ��ü �����̴�.
class IntSet {
private:
	IntElement* mElements; // ����Ʈ�� �����ϱ� ���� ��ü ����
	int mSize; // ����Ʈ�� ũ�⸦ ��Ÿ���� ���� ����
public:
	IntSet() // Default constructor
	{
		mSize = 0;
		mElements = NULL;
	}

	IntSet(int* arr, int n) // constructor
	{
		mSize = n;
		IntElement *start = new IntElement(arr[0]), *temp = start;
		for (int i = 1; i < n; i++)
		{
			temp->setNext(new IntElement(arr[i]));
			temp = temp->getNext();
		}
		mElements = start;
	}

	~IntSet() // destructor
	{
		// �ڽ��� ���� �ִ� ��� ����� �޸𸮸� �����Ѵ�.
		IntElement* temp = mElements;
		for (int i = 0; i < mSize; i++)
		{
			delete mElements;
			mElements = temp->getNext();
		}
	}

	bool find(int val) // �Ķ���ͷ� ���� ���Ұ� ���� �ϴ����� ���� Boolean ���·� return.
	{
		IntElement* temp = mElements;
		for (int i = 0; i < mSize; i++)
		{
			if (temp->getValue() == val) return true;
			temp = temp->getNext();
		}
		return false;
	}

	void insert(int val) // ������ �� �ڿ� ���Ҹ� ����(���� ���� ������ �ȳ���)
	{
		if (mSize == 0)
		{
			mElements = new IntElement(val);
			mSize++;
			return;
		}

		if (find(val))
		{
			printf("���տ� �̹� %d��(��) �ֽ��ϴ�.\n", val);
			return;
		}
		

		IntElement* temp = mElements;
		for (int i = 0; i < mSize - 1; i++)
		{
			temp = temp->getNext();
		}
		temp->setNext(new IntElement(val));
		mSize++;
	}

	void remove(int val) // ���տ��� �Ķ���ͷ� ���� ���Ҹ� ����
	{
		if (!find(val)) return;

		IntElement* temp = mElements;
		if (mElements->getValue() == val)	// ù������ ���ƹ����� �ٷ� ������
		{
			mElements = mElements->getNext();
			delete temp;
			mSize--;
			return;
		}
		else
		{
			for (int i = 1; i < mSize; i++)
			{
				if (temp->getNext()->getValue() == val)
				{
					IntElement* temp2 = temp->getNext();
					temp->setNext(temp->getNext()->getNext());
					delete temp2;
					mSize--;
					return;
				}
				temp = temp->getNext();
			}
		}
	}

	void clear() // ������ ���Ҹ� ��� ����
	{
		IntElement* temp;
		for (int i = 0; i < mSize; i++)
		{
			temp = mElements;
			mElements = mElements->getNext();
			delete temp;
		}
		mSize = 0;
	}

	int getSize() // ������ ũ�� return
	{
		return mSize;
	}

	void printSet() // ������ ���Ҹ� ��� ���
	{
		if (mSize == 0)
		{
			printf("������ ����ֽ��ϴ�.\n");
			return;
		}
		IntElement* temp = mElements;
		for (int i = 0; i < mSize; i++)
		{
			printf("%d -> ", temp->getValue());
			temp = temp->getNext();
		}
		printf("\n");
	}

	IntElement* getElements() // ����Ʈ�� ù��° ������ �ּҸ� return
	{
		return mElements;
	}

	bool isEqual(IntSet& set) // �Ķ���ͷ� ���� Set�� ���Ҹ� ��
	{
		// �������� Ȯ��
		if (this->mSize != set.mSize) return false;

		// �ϳ��ϳ� �ִ��� Ȯ��
		IntElement* temp = mElements;
		for (int i = 0; i < mSize; i++)
		{
			if (!set.find(temp->getValue())) return false;
		}

		// �̰� �Ѱ����� ��� ���Ұ� �����ϴ� ��
		return true;
	}

};

int main() {
	int arr[4] = { 1, 2, 3, 4 };

	IntSet s1;
	IntSet s2(arr, 4);

	s1.printSet();
	s2.printSet();

	s1.insert(4);
	s1.insert(1);
	s1.insert(2);

	s2.remove(3);
	s2.insert(1);

	s1.printSet();
	s2.printSet();

	if (s1.isEqual(s2)) {
		cout << "s1 == s2" << endl;
	}
	else {
		cout << "s1 != s2" << endl;
	}

	s1.clear();
	s2.clear();

	s1.printSet();
	s2.printSet();

	return 0;
}