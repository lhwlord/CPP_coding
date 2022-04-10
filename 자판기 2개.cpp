#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ���Ǳ��� ��ɵ�
// -�Ǹ���ǰ, �� ��ǰ�� ���� ����
// -���� ���� �Է¹ޱ�
// -�� �ޱ�
// -��ǰ�����ϰ� �ܵ������ֱ�(ȭ���������)
// 

/*
	private�����
-��������(����ü �迭���� : �̸�, ���, ����)
- ������� ����
- ����ڰ� ���� ��
- ������ ����Լ�(��� ��ǰ�� ���ݰ� ���)
- �����Է��Լ�
- ���Է��Լ�
- �Է�ó�� / ������ / ����� �ܵ� �ִ� �Լ�
*/

/*
	public �����
-������ : ��ǰ �̸�/����/��� ���ڷ� �޾Ƽ� �����ϵ��� �ϱ�.(3�� ��)
	�̰� �����Ҵ����� ����üŸ�� �޸� �Ҵ��ؼ� �� ��.
	������ ����� �ȳ��� ���� ���
-�Ҹ��� : �Ʊ� �����Ҵ��ؼ� ���� ����üŸ�� �޸� ������ ��
-���Ǳ� �����Լ�
	-�� ���Ǳ��� ����Ȳ ���
	-������� ���ἱ��(�߸��ϸ�(��ȣƲ����) �ٽ�)
	-������� �ݾ��Է�(�߸��ϸ�(�������ϸ�) �ٽ�)
	-���� �� ���ۿϷ� �� ����� �ܵ���ȯ
*/

// ���� �̸�, ����, ��� ��� ����ü
typedef struct
{
	string name;
	int price;
	int stock;
} line;

// ���Ǳ�.
class machine
{
private:
	line* menu;	// �޴�
	int choice;	// ����� ����
	int money;	// ����� �Էµ�
	int wallet = 0;	// ���Ǳ� �Ǹż���(����� ����)

	// ������ ���
	void printStatus()
	{
		printf("Currently I have..\n");
		for (int i = 0; i < 3; ++i)
		{
			printf("%s - [price : %d] [num : %d]\n", 
				menu[i].name.c_str(), menu[i].price, menu[i].stock);
		}
	}

	// ����� �����Է�
	int inputChoice()
	{
		int tempNum;
		printf("Input your choice: 1) %s  2) %s  3) %s : ",
			menu[0].name.c_str(), menu[1].name.c_str(), menu[2].name.c_str());
		scanf("%d", &tempNum);
		tempNum--;	// �ε��� ���߱�
		return tempNum;
	}

	// ���Է�
	int inputMoney()
	{
		int tempNum;
		printf("Input money for your choice : ");
		scanf("%d", &tempNum);
		return tempNum;
	}

	// ����ó�� / ������ / ����� �ܵ� ��ȯ
	void work()
	{
		// ������ Ȯ��
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

	machine(line a, line b, line c)	// ������. �����Ҵ�
	{
		menu = new line[3];
		menu[0] = a;
		menu[1] = b;
		menu[2] = c;

		printf("Vending machine is ready\n");
	}

	~machine()	// �Ҹ���. �����Ҵ� ����
	{
		delete[] menu;
	}

	// ���Ǳ� ����
	void run()
	{
		printStatus();	// �������

		int temp = inputChoice();	// �����Է�
		while (temp < 0 || temp > 2)
		{
			printf("Wrong input\n");
			temp = inputChoice();
		}
		choice = temp;

		temp = inputMoney();	// ���Է�
		while (temp < menu[choice].price)
		{
			printf("Not enough money\n");
			temp = inputMoney();
		}
		money = temp;

		work();
	}
};



// ���� 3������ �Ĵ� ���Ǳ� ��ü 2�� ���� �� ����
// 2���� ���Ǳ⿡ ���� ������ �Է¹ް� ����, �� ������ ���Ǳ� 2�� ����
// ������� ���ÿ� ���� �� ���Ǳ� ����
// �����Է� ���� �� ���ѹݺ���(���Ǳ� ���ÿ��� -1�Է½� �����ϴ� ��)
int main(void)
{
	line temp[3];

	machine* ma[2];	// for ��� �ȿ��� ����Ǵ� machine ��ü�� �츮�� ���� �����Ҵ�
	// machine ��ü �ӽ÷� ���� �� for ��� �ȿ��� �ٽ� �����ϴ°� �ȵȴ�. ��ü�� �Ҹ������� ������ �ƴ϶� �ν��Ͻ� ���������� �ͼӵǴµ�?

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

	// ���ѷ���. ��� ���ÿ��� -1�� �ԷµǸ� Ż��
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
		else // 1�̰ų� 2�� ���
		{
			machineNum--;
			ma[machineNum]->run();
		}
	}

	printf("Program exit\n");

	// for�� �ۿ��� �۾��ϱ� ���� �����Ҵ��� ��ü 2�� ����
	delete ma[0];
	delete ma[1];

	return 0;
}