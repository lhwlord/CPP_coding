#include <iostream>
#include <vector>
using namespace std;

int zeroCount = 0, oneCount = 0;

int fibonacci(int n) {
    if (n == 0) {
        zeroCount++;
        return 0;
    }
    else if (n == 1) {
        oneCount++;
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// �Ǻ���ġ �Լ����� 0�� 1�� ��µǴ� Ƚ���� ���ϴ� ���α׷�.
// �Ǻ���ġ 40�ܰ����������, ���ѽð��� 0.25���� ����� DP�� �ٲ�� �Ѵ�.
int main(void)
{
    int cNum;
    cin >> cNum;
    vector<int> zero;
    vector<int> one;

    zero.push_back(1);
    zero.push_back(0);
    one.push_back(0);
    one.push_back(1);

    // N�� �ִ� 40�����ۿ� ���ø��Ƿ�, �ƿ� ó������ 40¥�� ���̺��� ���� �� ��.
    for (int i = 2; i < 41; i++)
    {
        zero.push_back(zero[i - 1] + zero[i - 2]);
        one.push_back(one[i - 1] + one[i - 2]);
    }

    // cNum��ŭ ���� �Է¹ް�, �ش�Ǵ� ���̺��� ����ϸ� ��.
    for (int i = 0; i < cNum; i++)
    {
        int temp;
        cin >> temp;
        cout << zero[temp] << ' ' << one[temp] << endl;
    }

    return 0;
}