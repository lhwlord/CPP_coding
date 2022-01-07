#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// �ֱٱ� �����ϴ� ����.
// ��尣�� �Ÿ��� �ƿ� 2�����迭�� �����Ѵ�.
// ������ 1�� ���� ���տ� ����, �ڱ� ���տ��� (���ճ��ο�� �����ϰ�) ���� ����� ��� ��� �� ���̸� �հ迡 �߰��Ѵ�.
int main(void)
{
	int T;
	scanf("%d", &T);
	getchar();
	getchar();	// ���� 2�� �Է¹޾Ƽ� ������ �뵵
	while (T--)
	{
		int n;
		scanf("%d", &n);
		// �Ÿ� ���� ����
		vector<vector<double>> distance(n, vector<double>(n, 2147483647));
		// ��ǥ�� ����. �̰ɷ� �Ÿ����͸� ä���� �Ѵ�.
		vector<vector<double>> pos(n, vector<double>(2));

		for (int i = 0; i < n; i++)	// ��ǥ�� �Է¹ޱ�
		{
			scanf("%lf %lf", &pos[i][0], &pos[i][1]);
		}

		// �Ÿ� ����ؼ� �Ÿ����Ϳ� �ִ´�.
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		{
			distance[i][j] = sqrt((pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]) + (pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1]));
		}

		// ������ ���� �ϳ� ����. �ش信 ���� ���Ϳ� �ƴ� ���͸� ������.
		vector<int> answer, notyet;
		double result = 0;
		answer.push_back(0);
		for (int i = 1; i < n; i++) { notyet.push_back(i); }	// �ʱ�����
		
		// �ݺ��� �̿��ؼ� ���Ѵ�.
		while (notyet.size() != 0)
		{
			// �ּҰ� ã�� : �ڽ��� ���տ���, �ڽ��� ������ ������� ���� ���� ���� �߿��� ã��.
			double min = 99e9;	// ������ ũ�� ����
			int targetIndex = -1;
			for (int i = 0; i < answer.size(); i++)
			{
				for (int j = 0; j < notyet.size(); j++)	// notyet���� ã���� ������ ���� �ƴϰ� �ȴ�.
				{
					if (min > distance[answer[i]][notyet[j]])
					{
							min = distance[answer[i]][notyet[j]];
							targetIndex = j;
					}
				}
			}
			
			// �ּҰ��� �ش��ϴ� ���� ������� �߰��ϰ�, �ű⿡ ���� ���� answer�� notyet���� ������ ó��.
			result += min;
			answer.push_back(notyet[targetIndex]);
			notyet.erase(notyet.begin() + targetIndex);
		}

		// ��� ���.
		printf("%f\n\n", result);
	}
}