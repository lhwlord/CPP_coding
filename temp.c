//char table[27] = "abcdefghijklmnopqrstuvwxyz";


// �� ���ĺ��� ���̸� ����Ͽ� ����Ѵ�. ��ҹ��ڴ� �������� �ʴ´�.
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

// �� ���ĺ��� ���̸�ŭ�� ����Ѵ�.
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

// ���� �ҹ��� �� ���� �Է¹�����, �� ������ ���ĺ����� ����Ѵ�.
// ���� �ҹ��ڰ� �ƴ� ��� �Է��� �����Ѵ�. ������ ���ĺ��� ������������ ����Ѵ�.
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
			puts("����.\n");
			exit();
		}

		between = to - from;

		putchar(between + '0');
		getchar();
	}
}