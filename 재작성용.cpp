#include <iostream>
#include <string>

using namespace std;

int cal(int a, char b, int c)
{
	switch (b)
	{
	case 'P':
		return a + c;
		break;
	case 'S':
		return a - c;
		break;
	case 'T':
		return a * c;
		break;
	case 'V':
		return a / c;
		break;
	default:
		return NULL;
		break;
	}
}

int test(string line)
{
	for (int i = 0; i < line.length(); i++)
	{
		int isCurY = 0;
		switch (line[i])
		{
		case 'P': case 'S': case 'T': case 'V':
			isCurY = 1;
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J':
			break;
		default:
			return 0;
			break;
		}
		if ((i >= 1) && (((line[i - 1] == 'P') || (line[i - 1] == 'S') || (line[i - 1] == 'T') || (line[i - 1] == 'V')) && (isCurY == 1)))	// 이전문자가 연산자이면서 지금꺼도 그렇다면
			return 0;
	}
}

//떨어진거 붙이기
/*int glue(int temp[], int tempInt)
{
	tempInt;
	int jump = 1, count = 0;
	for (int i = tempInt; i != 0; i--)
	{
		count += temp[i] * jump;
		jump *= 10;
	}
	return count;
}*/

int* parsing(string line)	// 문자열들을 숫자열로 전부 보내기
{
	int arr[1000];
	int count = 0;
	int temp[1000];
	int newArr[100];
	int tempInt = 0;
	int newInt = 0;
	for (int i = 0; i < line.length(); i++)
	{
		arr[i] = line[i] - 64;
		count++;
	}
	//80 83 84 86
	// 연산자 단위로 앞뒤로 끊어서 저장하기
	for (int i = 0; i < count; i++)
	{
		if ((arr[i] == 80) || (arr[i] == 83) || (arr[i] == 84) || (arr[i] == 86))
		{
			//맞으면 끊고 최종배열에 저장, 연산자도 배열에 넣기
			newArr[newInt++] = glue(temp, tempInt);
			tempInt = 0;

			newArr[newInt++] = arr[i];
		}
		else
		{
			//이게 아니면 계속해서 임시배열에 넣기
			temp[tempInt++] = arr[i];
		}
	}

	
	//끝나고 나서 한번 더 붙이기
	newArr[newInt++] = glue(temp, tempInt);

	//지금까지 잘 됐나 확인
	for (int i = 0; i < newInt; i++)
	{
		cout << newArr[i] << ' ';
	}
	cout << endl;
	// 이 안에서 전부 작업해야 할 수도 있다.



	return arr;	//없애도됨
}



int main()
{
	string line;
	int sum = 0;

	while (getline(cin, line))
	{
		int* arr;
		//수식은 잘 입력되고, 이후 유효성 검사(예외문자 혹은 연산자 겹침)
		if (test(line) == 0) //에러출력
		{
			cout << "Error" << endl;
			continue;
		}

		//유효성 검사가 다 되었다면 배열까지 잘 집어넣어졌을테고, 숫자별로 분리하며 계산
		arr = parsing(line);
		//숫자 개별로 집어넣기

	}

	return 0;
}

