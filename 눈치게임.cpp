#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;


// ���ӿ� �����ϴ� �÷��̾� ��ü
class Player
{
private:
	const int totalN;
	static int order;	// �÷��̾� id �����뵵
	int id;
	int waiting;	// �� ��� ���� ī��Ʈ
	bool done;	//	�̹� ���� ����°�?
	void setTime();	// wating�� ���� ����
public:
	Player(int num);	// ������(�����)
	bool play();	// �ð� ƽ���� waiting ���� ���� ��ų� ��ٸ�
	bool isOver();	// done�� üũ����
	int getPlayerID();	// �÷��̾� ID ��ȯ
};

int Player::order = 1;

// ������
// order�� ���̵� ����, done �ʱ�ȭ, setTime ȣ��
// ������ waiting ���
Player::Player(int num) : totalN(num)
{
	id = order++;
	done = false;
	setTime();
	printf("%d�� �÷��̾�� %d�Ͽ� ���� �� ���Դϴ�.\n", id, waiting - 1);
}

// ��Ⱚ �ʱ�ȭ��
void Player::setTime()
{
	waiting = rand() % totalN + 1;	// 0���̸� �ϰ��ҽ� -1�� �Ǿ� play���� �ľ� ����
}

// �� �ϸ��� waiting ����, ���� ���� �ϸ� true ��ȯ �� done ������Ʈ
bool Player::play()
{
	if (--waiting == 0)
	{
		done = true;
		return true;
	}
	else return false;
}

// done ��ȯ��
bool Player::isOver()
{
	return done;
}

// ID ��ȯ
int Player::getPlayerID()
{
	return id;
}

// ���� �����ϴ� ��ü
class TimingGame
{
private:
	static int curTime;	// ���� �ð��� ��ü�� ��������
	const int totalN;
	Player** players;	// ������ �迭 ����

public:
	TimingGame(int playerN);
	void simulateGame();
	~TimingGame();
};

int TimingGame::curTime = 0;

TimingGame::TimingGame(int playerN) : totalN(playerN)
{
	players = new Player*[playerN];	// �迭ũ�� �Ҵ�
	for (int i = 0; i < playerN; i++)
	{
		players[i] = new Player(playerN);	// �迭 ���� ��ü ������ �Ҵ�
	}
}

TimingGame::~TimingGame()	// �����Ҵ� �޸� ����
{
	for (int i = 0; i < totalN; i++)
	{
		delete players[i];
	}
	delete[] players;
}

// TimingGame �ùķ��̼�
// �ִ� �� ���� �÷��̾� ���� �����ϰ�
// �� �ϸ��� �յ�� �÷��̾� Ȯ��, �� ���ÿ� ��� �÷��̾� �߻��ϸ� conflict �߻�
// conflict �߻� �� ���� ���� �� �ش� �� ���
// �̰� ���� ���������� �������� conflict ���� �������� ������ �÷��̾� ID ���
void TimingGame::simulateGame()
{
	printf("���� ����.\n");
	int lastTemp = -1;	// ���� �۾��õ����� ������ �÷��̾��� ID. ���� ��ų�, ���������� ����� ��� �� �� ��� ����
	
		for (; curTime < totalN; curTime++)	// curTime�� tick���� �����ؼ� for���� ����
		{
			printf("===%d�� ��===\n", curTime);
			int count = 0;
			for (int j = 0; j < totalN; j++)
			{
				if (players[j]->play())
				{
					lastTemp = players[j]->getPlayerID();	// j+1�� �ص� ����� ����������, �ڵ� ���� �� ������ �����ϴ�.
					printf("%d���� ���� ������ϴ�.\n", lastTemp);
					count++;
				}
			}
			printf("\n");
			if (count > 1)
			{
				printf("���� ����. %d�� �Ͽ� �浹�� �߻��߽��ϴ�.\n", curTime);
				return;
			}
		}
		printf("\n���� ����. �浹�� �߻����� �ʾ�, %d���� �����ϴ�.\n", lastTemp);
		return;
}




// �Է��� int�� ������� ��ȯ, �ƴϸ� �ٽ� �Է¹޵���
int getPlayerNum()
{
_input : 
	string s;
	printf("�÷��̾� ���� �Է��Ͻÿ� : ");
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			printf("�ùٸ� ���ڰ� �Էµ��� �ʾҽ��ϴ�. �ٽ� �Է��ϼ���.\n");
			goto _input;
		}
	}
	if (stoi(s) == 0)
	{
		printf("�÷��̾�� ��� �� �� �̻��̾�� �մϴ�. �ٽ� �Է��ϼ���.\n");
		goto _input;
	}

	return stoi(s);
}



// ��ġ����.
// N���� ����� �ִٸ� N-1���� ��ȸ �ȿ� ��� ���� ���� �Ѵ�. �ߺ��Ǹ� �ƿ�.
int main(void)
{
	srand(time(NULL));

	int playerNum = getPlayerNum();
	TimingGame game = TimingGame(playerNum);
	game.simulateGame();

}