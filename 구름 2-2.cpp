#include <iostream>
#include <string>
#include <string.h>

using namespace std;

typedef struct
{
	char c;
	int num;
} tier;

int main();

void mytier(tier*, char*);
void initTier(tier*);
void tierCmp(tier*, tier*);

// A~Z���� �ִ� ī�并ġ. �� 26*4�� ī�并ġ. ���߿��� ��� ������ ���� 5�徿 �̴´�.
// ��ī�� : ������ 4��, Ʈ���� : ������ 3��, ��� : ������ 2��.
// ������ �������� ����, ���� ����̸� ����ī�� ���ڰ� �ļ���(Z�� ��������) ����.
// �ڽ��� ���� 5�� �� ���� ������� �ܷ��, ��Ȥ ���� ���� ����� ���º��̴�.
// ��� ���� ������� �� ����� �а� �־����� ���� �������� ����� ��. ���ºθ� ���.
int main()

{
	//�� ���� �迭�� �Է¹��� ��.
	string line;

	//�Է¹޾� �и��ϴ� �ܰ���� ���⿡ �ۼ�
	while (getline(cin, line))
	{
		tier aT, bT;
		initTier(&aT);
		initTier(&bT);
		char* a, *b;
		a = strtok_s((char*)line.c_str(), " ", &b);

		//�ڽ��� �ִ� ����� ã�Ƽ� �����ϴ� �Լ�
		mytier(&aT, a);
		mytier(&bT, b);

		//���ؼ� ���� �켼���� ����ϴ� �Լ�. ���ο��� ��±��� �ȴ�.
		tierCmp(&aT, &bT);
	}

	return 0;
}

void mytier(tier* T, char* a)
{
	int arr[100] = { 0, };//���ĺ� �빮�ڴ� �ƽ�Ű�� 65~90
	int maxCombo = 0;
	for (int i = 0; i < 5; i++)
	{
		arr[a[i]]++;
	}
	//�ִ��ġ ã��. ���Ž���ϸ鼭 2 �̻��̰� ���� �ִ��ġ �̻��̸� �װɷ� ���Ƴ����. ���� 2�� �Ѵ� ��ġ�� ���ٸ� �ʱⰪ�� 0�� �״�� ���� ���̴�.
	for (int i = 65; i < 91; i++)
	{
		if ((arr[i] >= maxCombo) && arr[i] >= 2)
		{
			T->c = (char)i;
			T->num = arr[i];
		}
	}
	return;
}

void initTier(tier* T)
{
	T->c = 0;
	T->num = 0;
}

// �� ����� ���Ѵ�.
// ���� �޺����� ���ϰ�, ������ ĳ���͸� ���Ѵ�. �̰ű��� ������ ��ο�.
void tierCmp(tier* a, tier* b)
{
	int result = 0;

	if (a->num > b->num)
		result = 1;
	else if (a->num < b->num)
		result = 2;
	else	// ���� ���� ���
	{
		if (a->c > b->c)
			result = 1;
		else if (a->c < b->c)
			result = 2;
		// ���������� ���� ������ ��ο�.
	}

	switch (result)
	{
	case 0 : 
		cout << "Draw" << endl;
		break;
	case 1 : 
		cout << "Tom" << endl;
		break;
	case 2 : 
		cout << "Jerry" << endl;
		break;
	default : 
		cout << "�̰� ���ü��� ����" << endl;
		break;
	}

	return;
}
