#include <iostream>
#include <math.h>

using namespace std;



int main(void)
{
	int tCase;
	scanf_s("%d", &tCase);
	int x1, y1, r1, x2, y2, r2;
	for (int caseNum = 0; caseNum < tCase; caseNum++)
	{
		scanf_s("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int sq_distance = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
		int sq_marineDistance = (r1 + r2) * (r1 + r2);
		int smallerR = r1 > r2 ? r2 : r1;
		int biggerR = r1 > r2 ? r1 : r2;

		if (sq_distance == 0 && r1 == r2) cout << -1 << endl;
		else if (sq_distance > sq_marineDistance) cout << 0 << endl;
		else if (sq_distance == sq_marineDistance) cout << 1 << endl;
		else if (sq_distance < sq_marineDistance && sqrt(sq_distance) + smallerR > biggerR) cout << 2 << endl;
		else if (sqrt(sq_distance) + smallerR == biggerR) cout << 1 << endl;
		else if (sqrt(sq_distance) + smallerR < biggerR) cout << 0 << endl;
	}
	return 0;
}