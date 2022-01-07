int between;

// 두 알파벳의 차이를 계산하여 반환한다. 대소문자는 구별하지 않는다.
int gap(char a, char b)
{
	int temp;
	if (a > b)
	{
		temp = a - b + 1;
		return temp;
	}
	else
	{
		temp = b - a + 1;
		return temp;
	}
}

// 두 알파벳의 차이만큼을 출력한다.
alpha(char start)
{
	while (between != 0)
	{
		putchar(start);
		between = between - 1;
		start = start + 1;
	}
	putchar('\n');
}

// 영문 소문자 두 개를 입력받으면, 그 사이의 알파벳들을 출력한다.
// 영문 소문자가 아닌 경우 입력을 종료한다. 사이의 알파벳은 오름차순으로 출력한다.
main()
{
	char from, to, check;
	while (1)
	{
		check = 0;
		from = getchar();
		to = getchar();
		putchar('\n');

		if (from < 'a') check = 1;
		if (from > 'z') check = 1;
		if (to > 'z') check = 1;
		if (to < 'a') check = 1;
		if (check == 1)
		{
			puts("No lowercase alphabet. Exit program.\n");
			exit();
		}

		between = gap(from, to);

		if (from > to) alpha(to);
		else alpha(from);
	}
}