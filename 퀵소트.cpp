#include <iostream>

using namespace std;

void quickSort(int[], int, int);
void divide(int[], int, int, int&);

int main(void)
{
	int arr[8] = {123,34,189,56,150,12,9,240};

	for (int i = 0; i < 8; i++)
		cout << arr[i] << ' ';
	cout << endl;

	quickSort(arr, 0, 7);

	for (int i = 0; i < 8; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}


// ����Ʈ.
void quickSort(int arr[], int start, int end)
{
	int point;
	if (start <= end)
	{
		divide(arr, start, end, point);
		quickSort(arr, start, point - 1);
		quickSort(arr, point + 1, end);
	}
	return;
}

void divide(int arr[], int start, int end, int& point)
{
	int pivot = start;
	// arr[start]�� �������� ��� �� �������� ����
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[start] > arr[i])
		{
			pivot++;
			int temp = arr[i];
			arr[i] = arr[pivot];
			arr[pivot] = temp;
		}
	}
	point = pivot;
	// �ݺ��۾� ���� �� �ǹ������� ��ġ��
	int temp = arr[start];
	arr[start] = arr[pivot];
	arr[pivot] = temp;

	// �߰�����.
	cout << endl;
	for (int i = start; i <= end; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return;
}