#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 자판기의 기능들
// -판매제품, 각 제품의 재고와 가격
// -고객의 선택 입력받기
// -돈 받기
// -제품제공하고 잔돈돌려주기(화면출력형식)
// 

/*
	private멤버들
-음료정보(구조체 배열형태 : 이름, 재고, 가격)
- 사용자의 선택
- 사용자가 넣은 돈
- 현상태 출력함수(모든 제품의 가격과 재고)
- 선택입력함수
- 돈입력함수
- 입력처리 / 재고업뎃 / 음료와 잔돈 주는 함수
*/

/*
	public 멤버들
-생성자 : 물품 이름/가격/재고 인자로 받아서 설정하도록 하기.(3개 다)
	이건 동적할당으로 구조체타입 메모리 할당해서 쓸 것.
	생성자 종료시 안내문 또한 출력
-소멸자 : 아까 동적할당해서 넣은 구조체타입 메모리 해제할 것
-자판기 동작함수
	-현 자판기의 재고상황 출력
	-사용자의 음료선택(잘못하면(번호틀리면) 다시)
	-사용자의 금액입력(잘못하면(돈부족하면) 다시)
	-연산 및 동작완료 후 음료와 잔돈반환
*/

// 음료 이름, 가격, 재고 담는 구조체
typedef struct
{
	string name;
	int price;
	int stock;
} line;

// 자판기.
class machine
{
private:
	line* menu;	// 메뉴
	int choice;	// 사용자 선택
	int money;	// 사용자 입력돈
	int wallet = 0;	// 자판기 판매수익(출력은 안함)

	// 현상태 출력
	void printStatus()
	{
		printf("Currently I have..\n");
		for (int i = 0; i < 3; ++i)
		{
			printf("%s - [price : %d] [num : %d]\n", 
				menu[i].name.c_str(), menu[i].price, menu[i].stock);
		}
	}

	// 사용자 선택입력
	int inputChoice()
	{
		int tempNum;
		printf("Input your choice: 1) %s  2) %s  3) %s : ",
			menu[0].name.c_str(), menu[1].name.c_str(), menu[2].name.c_str());
		scanf("%d", &tempNum);
		tempNum--;	// 인덱스 맞추기
		return tempNum;
	}

	// 돈입력
	int inputMoney()
	{
		int tempNum;
		printf("Input money for your choice : ");
		scanf("%d", &tempNum);
		return tempNum;
	}

	// 음료처리 / 재고업뎃 / 음료와 잔돈 반환
	void work()
	{
		// 재고부터 확인
		if (menu[choice].stock == 0)
		{
			printf("not enough beverages, sorry\n");
			return;
		}

		menu[choice].stock--;
		wallet += menu[choice].price;

		printf("Here is your beverage, %s\n", menu[choice].name.c_str());
		printf("Here is your change, %d\n", money - menu[choice].price);
	}

public:

	machine(line a, line b, line c)	// 생성자. 동적할당
	{
		menu = new line[3];
		menu[0] = a;
		menu[1] = b;
		menu[2] = c;

		printf("Vending machine is ready\n");
	}

	~machine()	// 소멸자. 동적할당 해제
	{
		delete[] menu;
	}

	// 자판기 동작
	void run()
	{
		printStatus();	// 상태출력

		int temp = inputChoice();	// 선택입력
		while (temp < 0 || temp > 2)
		{
			printf("Wrong input\n");
			temp = inputChoice();
		}
		choice = temp;

		temp = inputMoney();	// 돈입력
		while (temp < menu[choice].price)
		{
			printf("Not enough money\n");
			temp = inputMoney();
		}
		money = temp;

		work();
	}
};



// 음료 3가지를 파는 자판기 객체 2개 생성 및 관리
// 2대의 자판기에 대한 정보를 입력받고 나서, 그 정보로 자판기 2대 생성
// 사용자의 선택에 따라 한 자판기 실행
// 별도입력 없을 시 무한반복함(자판기 선택에서 -1입력시 종료하는 등)
int main(void)
{
	line temp[3];

	machine* ma[2];	// for 블록 안에서 선언되는 machine 객체를 살리기 위해 동적할당
	// machine 객체 임시로 선언 후 for 블록 안에서 다시 대입하는건 안된다. 객체의 소멸조건은 변수가 아니라 인스턴스 생성시점에 귀속되는듯?

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("Input %dst item : ", j + 1);
			cin >> temp[j].name;
			printf("Input # of %s : ", temp[j].name.c_str());
			scanf("%d", &temp[j].stock);
			printf("Input the price of %s : ", temp[j].name.c_str());
			scanf("%d", &temp[j].price);
		}
		ma[i] = new machine(temp[0], temp[1], temp[2]);
	}

	// 무한루프. 기계 선택에서 -1이 입력되면 탈출
	while (1)
	{
		printf("choice the VendingMachine(1 or 2, exit: -1) : ");
		int machineNum;
		scanf("%d", &machineNum);
		if (machineNum == -1) break;
		else if (machineNum != 1 && machineNum != 2)
		{
			printf("Wrong input\n"); continue;
		}
		else // 1이거나 2인 경우
		{
			machineNum--;
			ma[machineNum]->run();
		}
	}

	printf("Program exit\n");

	// for문 밖에서 작업하기 위해 동적할당한 객체 2개 해제
	delete ma[0];
	delete ma[1];

	return 0;
}