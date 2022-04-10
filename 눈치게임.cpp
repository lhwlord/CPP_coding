#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;


// 게임에 참여하는 플레이어 객체
class Player
{
private:
	const int totalN;
	static int order;	// 플레이어 id 생성용도
	int id;
	int waiting;	// 손 들기 위한 카운트
	bool done;	//	이미 손을 들었는가?
	void setTime();	// wating을 랜덤 지정
public:
	Player(int num);	// 생성자(사람수)
	bool play();	// 시간 틱마다 waiting 따라 손을 들거나 기다림
	bool isOver();	// done을 체크해줌
	int getPlayerID();	// 플레이어 ID 반환
};

int Player::order = 1;

// 생성자
// order로 아이디 설정, done 초기화, setTime 호출
// 설정된 waiting 출력
Player::Player(int num) : totalN(num)
{
	id = order++;
	done = false;
	setTime();
	printf("%d번 플레이어는 %d턴에 손을 들 것입니다.\n", id, waiting - 1);
}

// 대기값 초기화용
void Player::setTime()
{
	waiting = rand() % totalN + 1;	// 0턴이면 턴감소시 -1이 되어 play에서 파악 못함
}

// 매 턴마다 waiting 감소, 손을 들어야 하면 true 반환 및 done 업데이트
bool Player::play()
{
	if (--waiting == 0)
	{
		done = true;
		return true;
	}
	else return false;
}

// done 반환용
bool Player::isOver()
{
	return done;
}

// ID 반환
int Player::getPlayerID()
{
	return id;
}

// 게임 실행하는 객체
class TimingGame
{
private:
	static int curTime;	// 현재 시간은 객체와 독립적임
	const int totalN;
	Player** players;	// 포인터 배열 형식

public:
	TimingGame(int playerN);
	void simulateGame();
	~TimingGame();
};

int TimingGame::curTime = 0;

TimingGame::TimingGame(int playerN) : totalN(playerN)
{
	players = new Player*[playerN];	// 배열크기 할당
	for (int i = 0; i < playerN; i++)
	{
		players[i] = new Player(playerN);	// 배열 안의 객체 실제로 할당
	}
}

TimingGame::~TimingGame()	// 동적할당 메모리 해제
{
	for (int i = 0; i < totalN; i++)
	{
		delete players[i];
	}
	delete[] players;
}

// TimingGame 시뮬레이션
// 최대 턴 수는 플레이어 수와 동일하게
// 각 턴마다 손드는 플레이어 확인, 손 동시에 드는 플레이어 발생하면 conflict 발생
// conflict 발생 시 게임 종료 후 해당 턴 출력
// 이게 없이 정상적으로 끝났으면 conflict 없이 끝났음과 마지막 플레이어 ID 출력
void TimingGame::simulateGame()
{
	printf("게임 시작.\n");
	int lastTemp = -1;	// 현재 작업시도중인 마지막 플레이어의 ID. 손을 들거나, 마지막까지 진행된 경우 둘 다 사용 가능
	
		for (; curTime < totalN; curTime++)	// curTime을 tick으로 설정해서 for문에 구현
		{
			printf("===%d번 턴===\n", curTime);
			int count = 0;
			for (int j = 0; j < totalN; j++)
			{
				if (players[j]->play())
				{
					lastTemp = players[j]->getPlayerID();	// j+1로 해도 출력은 동일하지만, 코드 수정 시 이쪽이 안전하다.
					printf("%d번이 손을 들었습니다.\n", lastTemp);
					count++;
				}
			}
			printf("\n");
			if (count > 1)
			{
				printf("게임 종료. %d번 턴에 충돌이 발생했습니다.\n", curTime);
				return;
			}
		}
		printf("\n게임 종료. 충돌이 발생하지 않아, %d번이 졌습니다.\n", lastTemp);
		return;
}




// 입력이 int형 정수라면 반환, 아니면 다시 입력받도록
int getPlayerNum()
{
_input : 
	string s;
	printf("플레이어 수를 입력하시오 : ");
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			printf("올바른 숫자가 입력되지 않았습니다. 다시 입력하세요.\n");
			goto _input;
		}
	}
	if (stoi(s) == 0)
	{
		printf("플레이어는 적어도 한 명 이상이어야 합니다. 다시 입력하세요.\n");
		goto _input;
	}

	return stoi(s);
}



// 눈치게임.
// N명의 사람이 있다면 N-1번의 기회 안에 모두 손을 들어야 한다. 중복되면 아웃.
int main(void)
{
	srand(time(NULL));

	int playerNum = getPlayerNum();
	TimingGame game = TimingGame(playerNum);
	game.simulateGame();

}