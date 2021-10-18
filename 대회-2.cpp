#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
Step 1: 현재 위치를 원문 문자열의 첫 번째 위치로 초기화하고 사전에는 'A'와 'B'를 넣어 초기화합니다. 이때 'A'에는 색인번호 0을, 'B'에는 1을 부여합니다.
Step 2: 문자열의 현재 위치에서부터 사전에 들어있는 가장 긴 패턴과 일치하는 부분문자열 W를 찾아 해당 색인번호를 저장합니다. 만약 원문이 전부 색인번호로 변환 및 저장되었다면 변환된 색인번호 배열을 반환하고 종료합니다.
Step 3: 원문에서 W 바로 다음에 위치한 하나의 문자를 덧붙인 새로운 패턴을 사전에 추가합니다. 이때 추가되는 패턴의 색인번호는 1씩 증가합니다.
Step 4: 현재 위치를 W의 바로 다음 칸으로 옮긴 후 Step 2로 돌아갑니다.
*/
vector<int> solution(string text) {
    vector<int> answer;
    
   
    
    return answer;
}

int main(void)
{
    vector<int> a = solution("ABABAABAB");

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}