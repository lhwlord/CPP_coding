//char table[27] = "abcdefghijklmnopqrstuvwxyz";


// 두 알파벳의 차이를 계산하여 출력한다. 대소문자는 구별하지 않는다.
int gap(int a, int b)
{
	int temp;
	if (a > b)
	{
		temp = a - b;
		return temp;
	}
	else
	{
		temp = b - a;
		return temp;
	}
}

// 두 알파벳의 차이만큼을 출력한다.
alpha(int start, int amount)
{
	//start -= 'a';
	while (amount != 0)
	{
		putchar(start);
		amount = amount - 1;
		start = start + 1;
	}
	putchar('\n');
}

// 영문 소문자 두 개를 입력받으면, 그 사이의 알파벳들을 출력한다.
// 영문 소문자가 아닌 경우 입력을 종료한다. 사이의 알파벳은 오름차순으로 출력한다.
main()
{
	char from, to, check;
	int between;
	while (1)
	{
		check = 1;
		from = getchar();
		to = getchar();

		if (check == 1)
		{
			puts("종료.\n");
			exit();
		}

		between = to - from;

		putchar(between + '0');
		getchar();
	}
}