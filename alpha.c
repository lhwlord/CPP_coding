int between;

// �� ���ĺ��� ���̸� ����Ͽ� ��ȯ�Ѵ�. ��ҹ��ڴ� �������� �ʴ´�.
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

// �� ���ĺ��� ���̸�ŭ�� ����Ѵ�.
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

// ���� �ҹ��� �� ���� �Է¹�����, �� ������ ���ĺ����� ����Ѵ�.
// ���� �ҹ��ڰ� �ƴ� ��� �Է��� �����Ѵ�. ������ ���ĺ��� ������������ ����Ѵ�.
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