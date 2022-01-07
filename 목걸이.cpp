#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



// �����迭.
typedef struct
{
	int left;
	int right;	// ��, �� ���� ������ �������� �ٲ� �� �ִ�. �װ� �Լ��� ����.
}pearl;


vector<pearl> result;	// �ϳ��� ������ ��� ���̴�.
bool solved = false;	// ������ �ϳ��� ������ ������ �б�� ���� ���ٽ�Ű�� �뵵.


// ������ �����´�. ������ ǥ���� ����.
void flip(pearl &a)
{
	int temp = a.left;
	a.left = a.right;
	a.right = temp;
}


// �۾����Ϳ� ���粨 ���� �� �ִ��� Ȯ���ϰ�, ���� �� �ִٸ� �ְ� true ��ȯ, �ȵǸ� false.
bool attachTry(vector<pearl> &remain, int index, vector<pearl> &working )
{
	if (working[0].left == remain[index].right)	// ���� ���ʿ� ������ ���
	{
		working.insert(working.begin(), remain.begin() + index, remain.begin() + index + 1);
		remain.erase(remain.begin() + index);
		return true;
	}
	else if (working[0].left == remain[index].left) // ���� ���ʿ� ����� ������ ���
	{
		flip(remain[index]);
		working.insert(working.begin(), remain.begin() + index, remain.begin() + index + 1);
		remain.erase(remain.begin() + index);
		return true;
	}
	else if (working[working.size() - 1].right == remain[index].left)	// ���� �����ʿ� ������ ���
	{
		working.push_back(remain[index]);
		remain.erase(remain.begin() + index);
		return true;
	}
	else if (working[working.size() - 1].right == remain[index].right)	// ���� �����ʿ� ����� ������ ���
	{
		flip(remain[index]);
		working.push_back(remain[index]);
		remain.erase(remain.begin() + index);
		return true;
	}

	// ���� ����� ���캻��. i��°��, �� ���� �� ���̿� remain[index] �� �尥 �� �ִ��� Ȯ��.
	for (int i = 0; i < working.size() - 1; i++)
	{
		for (int j = 0; j < 2; j++)	// ������� Ȯ���϶�� �ִ°�.
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

// ���ο� Ʈ��ŷ �õ�.
void newTrack(vector<pearl> remain, vector<pearl> working)
{
	// �������� ������. �ƴ� ��쿡�� ����.
	if (!solved)
	{
		// ������ ���� ���� �尬���� ���⼭ ������.
		if (remain.size() == 0)
		{
			solved = true;
			result = working;
			return;
		}

		// �迭�� ���鼭, ������ ���� �� �ִ����� �˻��Ѵ�.�Ǹ� �׷��� �ϰ� ���.
		for (int i = 0; i < remain.size(); i++)
		{
			vector<pearl> temp_remain = remain;
			vector<pearl> temp_working = working;
			if (attachTry(temp_remain, i, temp_working)) newTrack(temp_remain, temp_working);
		}
	}
}

// ����̰� ��������. �ȿ� �ִ� ������ ������ 2���� �ִµ�, ����� ���¿��� ���ֺ��� ���� ����.
// ������ ������ ���� ��, �̰ɷ� ����� �ϳ��� �� ���� �� �ִ��� Ȯ��.
int main(void)
{
	// ����
	int T;
	cin >> T;
	for(int Ti = 0; Ti < T; Ti++)
	{
		solved = false;
		int N;
		scanf("%d", &N);

		vector<pearl> neck(N);

		// ���ο� Ʈ��ŷ ������ ��꺤��
		vector<pearl> work;

		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &neck[i].left, &neck[i].right);
		}

		// ù ���� ���÷� ����ְ� �����Ѵ�.
		work.push_back(neck[0]);
		neck.erase(neck.begin());

		// ���ο� ��Ʈ��ŷ �õ�
		newTrack(neck, work);

		printf("Case #%d\n", Ti + 1);
		// ������ ���. ���̽� ������ ��ĭ �ʿ�.
		if (result[0].left != result[result.size() - 1].right) printf("some beads may be lost\n\n");
		else
		{
			for (pearl i : result) printf("%d %d\n", i.left, i.right);
			printf("\n");
		}
	}
	return 0;
}