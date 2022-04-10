#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int* input;	// �Է°� ���� ������

int output_1 = 0, output_2 = 0;

int thread_Input_stack = -1, thread_cal_sq_done = 0, thread_cal_fib_done = 0, thread_Output_sq_done = 1, thread_Output_fib_done = 1;

int userMain(int arg)
{
	int thread_Input(int), thread_cal_sq(int),
		thread_cal_fib(int), thread_Output(int),
		thread_last(int),
		num;
	
	printf("%dth, main thread started.\n", threadSelf());
	printf("We will calculate and print N's square number and Nth fib number.\n");
	printf("input number of N : ");
	scanf("%d", &num);

	input = (int*)malloc(sizeof(int) * num);

	threadCreate(20, thread_Input, num);
	threadCreate(20, thread_cal_sq, num);
	threadCreate(20, thread_cal_fib, num);
	threadCreate(20, thread_Output, num);
	threadCreate(19, thread_last, 0);

	printf("%dth, main thread exit.\n", threadSelf());
	threadExit();
}

// A ������ : �Է¹ޱ�(argȽ����ŭ, ���� ��� prog_end 1�� ����)
int thread_Input(int arg)
{
	int i;
	printf("input %d numbers. You can input token by space or enter.\n", arg);
	printf("*WARNING : If you input enter, this will calculate at that point and continue input.\n");
	printf("*Notice : This program will show the threads' act, including their waiting.");
	printf("So it would be easier to see if you choose each N under about 12.\n");
	for (i = 0; i < arg; i++)
	{

		printf("%dth, input thread now running. Input the number(s) : ", threadSelf());
		scanf("%d", input + i);

		printf("\n");
		thread_Input_stack++;	// �Է�ó���� �� �ε��� ��ȣ���� �Ϸ�����
		threadYield();
	}
	printf("%dth, input thread exit.\n", threadSelf());
	threadExit();
}

// B-1 ������ : ���� ����ϱ�
int thread_cal_sq(int arg)
{
	int i;
	for (i = 0; i < arg; i++)
	{
		while (thread_Input_stack < i)
		{
			printf("(%dth, cal-1 thread is waiting for %dth input)\n", threadSelf(), i);
			threadYield();
		}


		while (thread_Output_sq_done == 0)
		{
			printf("(%dth, cal-1 thread is waiting for output)\n", threadSelf());
			threadYield();
		}
		thread_Output_sq_done = 0;

		output_1 = input[i] * input[i];
		printf("%dth thread, cal-1 thread job is done.\n", threadSelf());

		thread_cal_sq_done = 1;
		threadYield();
	}
	printf("%dth, cal-1 thread exit.\n", threadSelf());
	threadExit();
}

// B-2 ������ : �Ǻ���ġ ����ϱ�
int thread_cal_fib(int arg)
{
	int i;
	for (i = 0; i < arg; i++)
	{
		int j, output_2_prev = 0;
		while (thread_Input_stack < i)
		{
			printf("(%dth, cal-2 thread is waiting for %dth input)\n", threadSelf(), i);
			threadYield();
		}
		while (thread_Output_fib_done == 0)
		{
			printf("(%dth, cal-2 thread is waiting for output)\n", threadSelf());
			threadYield();
		}
		thread_Output_fib_done = 0;
		// �Ǻ���ġ ����. �� �ܰ踸ŭ ������ ������ �纸�ϵ��� �Ѵ�.
		output_2 = 1;
		for (j = 0; j < input[i] - 1; j++)
		{
			int temp = output_2;
			output_2 += output_2_prev;
			output_2_prev = temp;

			printf("(%dth, cal-2 thread is still calculating...)\n", threadSelf());
			threadYield();
		}
		printf("%dth thread, cal-2 thread job is done.\n", threadSelf());
		thread_cal_fib_done = 1;
		threadYield();
	}
	printf("%dth, cal-2 thread exit.\n", threadSelf());
	threadExit();
}

// C ������ : ����ϱ�
int thread_Output(int arg)
{
	int i;
	for (i = 0; i < arg; i++)
	{
		while (thread_cal_sq_done == 0 || thread_cal_fib_done == 0)
		{
			printf("(%dth, output thread is waiting for cal(1 or 2), should be 2)\n", threadSelf());
			threadYield();
		}
		thread_cal_sq_done = 0; thread_cal_fib_done = 0;


		printf("%dth, output thread : %d's square number is %d\n", threadSelf(), input[i], output_1);
		thread_Output_sq_done = 1;
		printf("%dth, output thread : %dth fib number is %d\n", threadSelf(), input[i], output_2);
		thread_Output_fib_done = 1;
		
		threadYield();
	}
	printf("%dth, output thread exit.\n", threadSelf());
	threadExit();
}

// Ż��� ������ ������. �갡 ����Ǵ� ���� �ٸ� ��� �����尡 ���� ����̴�. �켱���� ���� ���缭 ������ ��
int thread_last(int arg)
{
	free(input);
	printf("Program exit. Thank you.\n");
}