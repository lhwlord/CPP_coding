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

// 피보나치 함수에서 0과 1이 출력되는 횟수를 구하는 프로그램.
// 피보나치 40단계까지라지만, 제한시간이 0.25초인 관계로 DP로 바꿔야 한다.
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

    // N은 최대 40까지밖에 못올리므로, 아예 처음부터 40짜리 테이블을 만들어도 될 것.
    for (int i = 2; i < 41; i++)
    {
        zero.push_back(zero[i - 1] + zero[i - 2]);
        one.push_back(one[i - 1] + one[i - 2]);
    }

    // cNum만큼 수를 입력받고, 해당되는 테이블을 출력하면 끝.
    for (int i = 0; i < cNum; i++)
    {
        int temp;
        cin >> temp;
        cout << zero[temp] << ' ' << one[temp] << endl;
    }

    return 0;
}