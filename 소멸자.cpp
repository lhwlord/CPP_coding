#include <iostream>
using namespace std;

class box
{
public:
	~box()
	{
		printf("�Ҹ�\n");
	}
};


int main() {
	box a;
	a.~a();



	printf("main ����\n");
}