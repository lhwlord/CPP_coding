#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <conio.h>
using namespace std;

// ���� ������ �ܾ �Է¹޴´�. ������ �����ϰ�, �ܾ �Ľ��Ѵ�.
// ��, C������ ó���� C++������ ó�� ���� ��Ÿ���� ������ �ٸ���. C������ ���� char�迭�� ��� ��ū���� ������ ���̰�, C++������ ���� ���ʺ��� string���� ��Ʈ���� �޾ƴٰ� ����������� ������ ���̴�.
// ���ο� �õ��� �غ��� : �Է½ð��� ���̱� ���� C�� ������� char�迭�� �޵�, �̰� ��ū ���� string�� �ִ� �۾�.
int main()
{
	char c[101];	// �ܾ� �ִ���̴� ���ѵ� ������ �����Ѵ�. �̰͸��� ���� ������ C++ ��Ÿ�Ϸ� ���� �Ѵ�.

	char temp;
	while (scanf("%s", c))
	{
		cout << c;
		char tc = getchar();
		if (tc == '\n' || tc == EOF) break;
	}


}