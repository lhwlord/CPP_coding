#include <iostream>
#include <string.h>

using namespace std;

void main(void)
{
	char line[100];
	int num = 0;
	
	cout << "10����-16������ ���� ��ȯ�����ִ� ���α׷�. 16������ �տ� 0x�� ���δ�. 0�� ������ ���� �ʴ´�." << endl;

	while (cin >> line)
	{
		
		if (line[0] == '0')
		{
			// 16�����̹Ƿ� 10������ ��ȯ�ϴ� �۾� ����
			sscanf_s(line + 2, "%x", &num);
			printf("%d\n", num);
		}
		else
		{
			// 10�����̹Ƿ� 16������ ��ȯ�ϴ� �۾� ����
			num = atoi(line);
			printf("0x%X\n", num);
		}
	}

	return;
}