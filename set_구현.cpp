#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// int 값을 여기에 감싼다.
class IntElement {
private:
	int value; // 리스트 내의 값을 저장
	IntElement* next; // linked List의 다음 원소의 주소 저장
public:
	// constructor
	IntElement(int val) 
	{
		value = val;
		next = NULL;
	} 

	// 객체의 value 값 return
	int getValue() 
	{
		return value;
	} 

	// 객체의 next 값 return
	IntElement* getNext() 
	{
		return next;
	} 

	// 객체의 next 값 설정
	void setNext(IntElement* element) 
	{
		next = element;
	}
};

// int형 값을 원소로 갖는 집합. 순서 상관없이, 같은 값을 배제한다.
// 또한 같은 원소를 가진 두 Set은 같다고 정의한다.
// 연결리스트 구조로 int 원소를 관리하며, int원소들은 IntElement 객체 형태이다.
class IntSet {
private:
	IntElement* mElements; // 리스트에 접근하기 위한 객체 생성
	int mSize; // 리스트의 크기를 나타내기 위한 변수
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
		// 자신이 갖고 있는 모든 요소의 메모리를 해제한다.
		IntElement* temp = mElements;
		for (int i = 0; i < mSize; i++)
		{
			delete mElements;
			mElements = temp->getNext();
		}
	}

	bool find(int val) // 파라미터로 받은 원소가 존재 하는지에 대해 Boolean 형태로 return.
	{
		IntElement* temp = mElements;
		for (int i = 0; i < mSize; i++)
		{
			if (temp->getValue() == val) return true;
			temp = temp->getNext();
		}
		return false;
	}

	void insert(int val) // 집합의 맨 뒤에 원소를 삽입(물론 값이 있으면 안넣음)
	{
		if (mSize == 0)
		{
			mElements = new IntElement(val);
			mSize++;
			return;
		}

		if (find(val))
		{
			printf("집합에 이미 %d이(가) 있습니다.\n", val);
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

	void remove(int val) // 집합에서 파라미터로 받은 원소를 제거
	{
		if (!find(val)) return;

		IntElement* temp = mElements;
		if (mElements->getValue() == val)	// 첫빠따에 같아버리면 바로 제끼기
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

	void clear() // 집합의 원소를 모두 제거
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

	int getSize() // 집합의 크기 return
	{
		return mSize;
	}

	void printSet() // 집합의 원소를 모두 출력
	{
		if (mSize == 0)
		{
			printf("집합이 비어있습니다.\n");
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

	IntElement* getElements() // 리스트의 첫번째 원소의 주소를 return
	{
		return mElements;
	}

	bool isEqual(IntSet& set) // 파라미터로 받은 Set과 원소를 비교
	{
		// 개수부터 확인
		if (this->mSize != set.mSize) return false;

		// 하나하나 있는지 확인
		IntElement* temp = mElements;
		for (int i = 0; i < mSize; i++)
		{
			if (!set.find(temp->getValue())) return false;
		}

		// 이거 넘겼으면 모든 원소가 존재하는 것
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