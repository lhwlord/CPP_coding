#include <iostream>
#include <string>

using namespace std;

int cal(int a, char b, int c)
{
	switch (b)
	{
	case -7:
		return a + c;
		break;
	case -4:
		return a - c;
		break;
	case -3:
		return a * c;
		break;
	case -1:
		return a / c;
		break;
	default:
		return NULL;
		break;
	}
}

int test(string line)
{
	int isCor = 1;
	for (int i = 0; i < line.length(); i++)
	{
		int isCurY = 0;
		switch (line[i])
		{
		case 'P': case 'S': case 'T': case 'V':
			isCurY = 1;
			break;
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J':
			isCurY = 0;
			break;
		default:
			isCor = 0;
			break;
		}
		if ((i >= 1) && (((line[i - 1] == 'P') || (line[i - 1] == 'S') || (line[i - 1] == 'T') || (line[i - 1] == 'V')) && (isCurY == 1)))	// �������ڰ� �������̸鼭 ���ݲ��� �׷��ٸ�
			isCor = 0;
		
		
			
	}
	if ((line[line.length() - 1] == 'P') || (line[line.length() - 1] == 'S') || (line[line.length() - 1] == 'T') || (line[line.length() - 1] == 'V'))
		isCor = 0;
	return isCor;
}

//�������� ���̱�
int glue(int temp[], int tempInt)
{
	tempInt--;
	int jump = 1, count = 0;
	for (int i = tempInt; i >= 0; i--)
	{
		count += temp[i] * jump;
		jump *= 10;
	}
	return count;
}

int* parsing(string line)	// ���ڿ����� ���ڿ��� ���� ������
{
	int arr[1000];
	int count = 0;
	int temp[1000];
	int newArr[100];
	int tempInt = 0;
	int newInt = 0;
	for (int i = 0; i < line.length(); i++)
	{
		arr[i] = line[i] - 65;
		count++;
	}
	//80 83 84 86
	// ������ ������ �յڷ� ��� �����ϱ�
	for (int i = 0; i < count; i++)
	{
		if ((arr[i] == 15) || (arr[i] == 18) || (arr[i] == 19) || (arr[i] == 21))
		{
			//������ ���� �����迭�� ����, �����ڵ� �迭�� �ֱ�
			newArr[newInt++] = glue(temp, tempInt);
			tempInt = 0;

			newArr[newInt++] = arr[i] - 22;
			//�迭���� ���ϱⰡ -7, ����� -4, ���ϱ�� -3, ������� -1�� ����.
		}
		else
		{
			//�̰� �ƴϸ� ����ؼ� �ӽù迭�� �ֱ�
			temp[tempInt++] = arr[i];
		}
	}
	//������ ���� �ѹ� �� ���̱�
	newArr[newInt++] = glue(temp, tempInt);

	//���ݱ��� �� �Ƴ� Ȯ��
	/*
	for (int i = 0; i < newInt; i++)
	{
		cout << newArr[i] << ' ';
	}
	*/
	// �� �ȿ��� ���� �۾��ؾ� �� ���� �ִ�.

	int j;
	for (j = 0; j < newInt; j++)
	{
		if (newArr[j] < 0)
		{
			newArr[j + 1] = cal(newArr[j - 1], newArr[j], newArr[j + 1]);
			j++;
		}
	}
	j -= 1;
	cout << newArr[j] << endl;


	return arr;	//���ֵ���
}



int main()
{
	string line;
	int sum = 0;

	while (getline(cin, line))
	{
		int* arr;
		//������ �� �Էµǰ�, ���� ��ȿ�� �˻�(���ܹ��� Ȥ�� ������ ��ħ)
		
		if (test(line) == 0) //�������
		{
			cout << "Error" << endl;
			continue;
		}

		//��ȿ�� �˻簡 �� �Ǿ��ٸ� �迭���� �� ����־������װ�, ���ں��� �и��ϸ� ���
		arr = parsing(line);
		//���� ������ ����ֱ�
			}

	return 0;
}

