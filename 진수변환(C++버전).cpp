#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void main(void)
{
	cout << "10진수/16진수 상호변환. 음수와 0 불가, 16진수는 0x 붙여서 표현." << endl;

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