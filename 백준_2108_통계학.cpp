#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


// πÈ¡ÿ #2108 : ≈Î∞Ë«–
// ∆Ú±’, ¡ﬂæ”, √÷∫Û, π¸¿ß √‚∑¬.
int main(void)
{
	int N;
	scanf("%d", &N);

	vector<int> table(8001, 0);
	double avr = 0;
	int min = 2147483647, max = -2147483648;
	int table_max = -1;
	int input, median = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		min = min <= input ? min : input;
		max = max >= input ? max : input;
		avr += input;

		table[input + 4000]++;
		if (table_max < table[input + 4000]) table_max = table[input + 4000];

	}

	avr /= N; 
	int a = (int)round(avr);	// ∆Ú±’

	//sort(arr.begin(), arr.end()); // ¡ﬂæ”. πÿø°≤´ ∞≥º±πˆ¿¸
	int count = 0;
	for (int i = 0; i < 8001; i++)
	{
		count += table[i];
		if (count > N / 2)
		{
			median = i - 4000; break;
		}
	}
	

	// √÷∫Û
	int mod;
	bool mini = false;
	for (int i = 0; i < 8001; i++)
	{
		if (table[i] == table_max && !mini) { mod = i - 4000; mini = true; }
		else if (table[i] == table_max && mini) { mod = i - 4000; break; }
	}
	

	printf("%d\n%d\n%d\n%d", a, median, mod, max - min);


	return 0;
}