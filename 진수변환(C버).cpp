#include <iostream>
#include <string.h>

using namespace std;

void main(void)
{
	char line[100];
	int num = 0;
	
	cout << "10진수-16진수를 각각 변환시켜주는 프로그램. 16진수는 앞에 0x를 붙인다. 0과 음수는 넣지 않는다." << endl;

	while (cin >> line)
	{
		
		if (line[0] == '0')
		{
			// 16진수이므로 10진수로 변환하는 작업 시행
			sscanf_s(line + 2, "%x", &num);
			printf("%d\n", num);
		}
		else
		{
			// 10진수이므로 16진수로 변환하는 작업 시행
			num = atoi(line);
			printf("0x%X\n", num);
		}
	}

	return;
}