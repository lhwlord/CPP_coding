#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(string s) {
    vector<string> answer;

    answer.push_back("");

    int start = 0; // 어떤 문장을 넣을건지(start부터 i까지)
    bool hasSamed = false;  // 다른 단어가 바로 직전에 겹쳤는가?
    
    for(int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])   // 같다면...
        {
            start = i;
            // 언제까지 동일한지 확인한다. start까지는 계속 동일한 것이다.
            for (int j = i + 1; s[i] == s[j]; j++)
            {
                start++;
            }

            i = start;

            // i 부터 start 까지 동일함을 확인했다. 이 다음부터 넣으면 된다.
            // 단 이게 마지막인 경우는 넣지 않고 패스.
            if(!hasSamed) answer.push_back("");

            // start까지 끝났는데 마지막이 하나라면 그건 그거대로 따로 넣는다.
            if (start == s.length() - 2)
            {
                answer[answer.size() - 1] += s[i + 1];
            }

            hasSamed = true;
        }   // 여기까지가 같은 경우. 다르다면 넣는다.
        else
        {
            answer[answer.size() - 1] += s[i];
            // 마지막을 예외처리.
            if (i == s.length() - 2) // 마지막의 이전까지 돌았는데도 다르다고 나왔으므로
            {
                answer[answer.size() - 1] += s[i + 1];
            }
            hasSamed = false;
        }
    }
    

    return answer;
}

int main(void)
{
    vector<string> ans = solution("aabb");

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}