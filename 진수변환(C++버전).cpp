#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void main(void)
{
	cout << "10����/16���� ��ȣ��ȯ. ������ 0 �Ұ�, 16������ 0x �ٿ��� ǥ��." << endl;

	string line;
	int num;


	while (getline(cin, line))
	{
		istringstream iss(line);

		if (line[0] == '0')
		{
			iss >> hex >> num;
			cout << num << endl;
		}
		else
		{
			iss >> num;
			cout << "0x" << hex << num << endl;
		}

	}

	return;
}