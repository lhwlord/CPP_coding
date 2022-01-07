#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



// 구슬배열.
typedef struct
{
	int left;
	int right;	// 단, 이 둘은 순서가 언제든지 바뀔 수 있다. 그건 함수로 구현.
}pearl;


vector<pearl> result;	// 하나의 정답이 담길 것이다.
bool solved = false;	// 정답이 하나라도 나오면 나머지 분기는 전부 빠꾸시키는 용도.


// 구슬을 뒤집는다. 간결한 표현을 위해.
void flip(pearl &a)
{
	int temp = a.left;
	a.left = a.right;
	a.right = temp;
}


// 작업벡터에 현재꺼 넣을 수 있는지 확인하고, 넣을 수 있다면 넣고 true 반환, 안되면 false.
bool attachTry(vector<pearl> &remain, int index, vector<pearl> &working )
{
	if (working[0].left == remain[index].right)	// 가장 왼쪽에 가능한 경우
	{
		working.insert(working.begin(), remain.begin() + index, remain.begin() + index + 1);
		remain.erase(remain.begin() + index);
		return true;
	}
	else if (working[0].left == remain[index].left) // 가장 왼쪽에 뒤집어서 가능한 경우
	{
		flip(remain[index]);
		working.insert(working.begin(), remain.begin() + index, remain.begin() + index + 1);
		remain.erase(remain.begin() + index);
		return true;
	}
	else if (working[working.size() - 1].right == remain[index].left)	// 가장 오른쪽에 가능한 경우
	{
		working.push_back(remain[index]);
		remain.erase(remain.begin() + index);
		return true;
	}
	else if (working[working.size() - 1].right == remain[index].right)	// 가장 오른쪽에 뒤집어서 가능한 경우
	{
		flip(remain[index]);
		working.push_back(remain[index]);
		remain.erase(remain.begin() + index);
		return true;
	}

	// 이제 가운데를 살펴본다. i번째와, 그 다음 것 사이에 remain[index] 가 드갈 수 있는지 확인.
	for (int i = 0; i < working.size() - 1; i++)
	{
		for (int j = 0; j < 2; j++)	// 뒤집어서도 확인하라고 넣는거.
		{
			if (working[i].right == remain[index].left && working[i + 1].left == remain[index].right)
			{
				working.insert(working.begin() + i + 1, remain.begin() + index, remain.begin() + index + 1);
				remain.erase(remain.begin() + index);
				return true;
			}
			flip(remain[index]);
		}
	}
	return false;
}

// 새로운 트래킹 시도.
void newTrack(vector<pearl> remain, vector<pearl> working)
{
	// 끝났으면 제낀다. 아닌 경우에만 실행.
	if (!solved)
	{
		// 남은게 없이 전부 드갔으면 여기서 끝낸다.
		if (remain.size() == 0)
		{
			solved = true;
			result = working;
			return;
		}

		// 배열을 돌면서, 비집고 넣을 수 있는지를 검사한다.되면 그렇게 하고 재귀.
		for (int i = 0; i < remain.size(); i++)
		{
			vector<pearl> temp_remain = remain;
			vector<pearl> temp_working = working;
			if (attachTry(temp_remain, i, temp_working)) newTrack(temp_remain, temp_working);
		}
	}
}

// 목걸이가 끊어졌다. 안에 있는 구슬은 색깔이 2개씩 있는데, 꿰어진 상태에선 마주보는 색이 같다.
// 임의의 구슬을 줬을 때, 이걸로 목걸이 하나를 딱 만들 수 있는지 확인.
int main(void)
{
	// 테케
	int T;
	cin >> T;
	for(int Ti = 0; Ti < T; Ti++)
	{
		solved = false;
		int N;
		scanf("%d", &N);

		vector<pearl> neck(N);

		// 새로운 트래킹 버전의 계산벡터
		vector<pearl> work;

		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &neck[i].left, &neck[i].right);
		}

		// 첫 값은 예시로 집어넣고 시작한다.
		work.push_back(neck[0]);
		neck.erase(neck.begin());

		// 새로운 백트래킹 시도
		newTrack(neck, work);

		printf("Case #%d\n", Ti + 1);
		// 적절히 출력. 케이스 끝마다 빈칸 필요.
		if (result[0].left != result[result.size() - 1].right) printf("some beads may be lost\n\n");
		else
		{
			for (pearl i : result) printf("%d %d\n", i.left, i.right);
			printf("\n");
		}
	}
	return 0;
}