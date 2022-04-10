#include <iostream>
using namespace std;

class box
{
public:
	~box()
	{
		printf("¼Ò¸ê\n");
	}
};


int main() {
	box a;
	a.~a();



	printf("main Á¾·á\n");
}