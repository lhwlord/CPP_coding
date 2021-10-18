#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

typedef struct {
	char set[2];
	int combo;
}pattern;

void store(pattern*, string, int*);
void searchStore(pattern*, char, char, int*);
bool isAlpha(char);
void initPattern(pattern*);
void bigTrace(pattern*, int*);
void sortAndPrint(pattern*, int);
bool bigger(pattern, pattern);
// ���ĺ� �α��ڷ� �̷��� ���� ã��.
// ���� ���� �����ϴ� ���� ������� ǥ���Ѵ�.
// �ִ� ������ �����ϴٸ� �ƽ�Ű ������� �����ؼ� ����Ѵ�.
// 2ȸ �̻� �����ϴ� ������ �ϳ��� ������ Not present ���.
int main()
{
	string line;

	//���� ������ �Է¹޾� ó��
	while (getline(cin, line))
	{
		pattern patArr[MAX / 2];
		int count = 1;
		//�ʱ�ȭ.
		for (int i = 0; i < MAX / 2; i++)
		{
			initPattern(&patArr[i]);
		}

		//2���� ��� ���Ϲ迭�� ����.
		//�� ���������� ���ϸ鼭 ������ �޺��� �ø� ��.
		//����, �����µ� ������ ���ԵǾ��ٸ� ����ĥ ��.
		store(patArr, line, &count);

		//���Ϲ迭�� �ߺ������Ͽ� ���� �־���.
		//2�� �̻��� ������ ã�� ����ϵ�, �󵵰� ������ �ƽ�Ű ������� �����ؾ� �Ѵ�.
		//����� �ִ� : ���������� 1���� �󵵴� �ٷ� ����ϰ�, 2�� �̻��� �󵵵��� ���� �迭�� ����� ���� �Ŀ� ��������.

		//�� ���ư���. ���� �󵵿� ����, ū �󵵺��� ���� �迭�� �����ϰ�, ���� �� ����ϵ��� ����.
		bigTrace(patArr, &count); //ū �� ã�Ƽ� ������� ����/����Լ� �����ϴ°�
	}
	return 0;
}

void store(pattern* arr, string line, int* count)
{
	for (int i = 1; i < line.length(); i++)
	{
		if (!isAlpha(line[i]) || (!isAlpha(line[i - 1]))) continue;

		//���� ���� ���� ���� ������ ���� ���Ϲ迭�� �ֳ� Ȯ���ϰ� �ֱ�
		searchStore(arr, line[i - 1], line[i], count);
	}
	return;
}

void searchStore(pattern* arr, char a, char b, int* count)
{
	for (int i = 0; i < *count; i++)
	{
		if ((arr[i].set[0] == a) && (arr[i].set[1] == b))
		{
			arr[i].combo++;
			return;
		}
	}
	//for������ ���� ���� �������Դٴ� ���� ���ο� �����̶�� ���̹Ƿ� ī��Ʈ �ε����� ���� �� �ø���.
	arr[*count].set[0] = a;
	arr[*count].set[1] = b;
	arr[*count].combo++;
	(*count)++;
	return;
}

bool isAlpha(char a)
{
	if (((a >= 65) && (a <= 90)) || ((a >= 97) && (a <= 122))) return true;

	return false;
}

void initPattern(pattern* P)
{
	P->combo = 0;
}

//ū �󵵸� �����ϰ�, �׷��� ����� �迭�� �����ؼ� ����ϴ� ���α׷�.
void bigTrace(pattern* P, int* count)
{
	pattern temp[MAX / 2];
	int tempCount = 0;
	int big = 0;

	//���� ū�� ã��
	for (int i = 0; i < *count; i++)
	{
		if (big < P[i].combo) big = P[i].combo;
	}


	//���鼭 ū�Ŷ� ���� ��ġ�ϸ� �ӽù迭�� ����ֱ�
	for (int i = 0; i < *count; i++)
	{
		if (big == P[i].combo)
		{
			temp[tempCount++] = P[i]; //�ּ� �ű�°� �ƴ϶� ������
		}
	}

	if (big < 2)
	{
		cout << "Not present" << endl;
		return;
	}
	sortAndPrint(temp, tempCount);
}

//�� �ȿ��� ���� ���� ���ϵ鸸 �ִ�.
//������ ��¸��� �ǳʶٸ� �����ϰ�, �ϳ����̶�� ������ �ǳʶٰ�, 2�� �̻��̸� �պ��� ���ذ��� ��������.
//������ �Ϸ�Ǹ� ���������� ����Ʈ�ϸ� �ȴ�!
void sortAndPrint(pattern* temp, int count)
{
	if (count == 0) return;
	if (count == 1);
	else
	{
		//����.
		for (int i = 0; i < count - 1; i++)
		{
			if (bigger(temp[i], temp[i + 1]))
			{
				pattern tmp = temp[i];
				temp[i] = temp[i + 1];
				temp[i + 1] = tmp;
				i = 0;
			}
		}
	}

	//���.
	for (int i = count - 1; i >= 0; i--)
	{
		cout << temp[i].set[0] << temp[i].set[1] << ' ';
	}
	cout << endl;

}

//�� ���� �� ���� �� ū���� �Ǵ���.
//������ ���� ������ ���� �� ����.
bool bigger(pattern a, pattern b)
{
	//ù���ں��� �˻�
	if (a.set[0] < b.set[0]) return true;
	else if (a.set[0] > b.set[0]) return false;
	else
	{
		return a.set[1] < b.set[1] ? true : false;
	}
}