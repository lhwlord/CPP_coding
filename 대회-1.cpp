#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(string s) {
    vector<string> answer;

    answer.push_back("");

    int start = 0; // � ������ ��������(start���� i����)
    bool hasSamed = false;  // �ٸ� �ܾ �ٷ� ������ ���ƴ°�?
    
    for(int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])   // ���ٸ�...
        {
            start = i;
            // �������� �������� Ȯ���Ѵ�. start������ ��� ������ ���̴�.
            for (int j = i + 1; s[i] == s[j]; j++)
            {
                start++;
            }

            i = start;

            // i ���� start ���� �������� Ȯ���ߴ�. �� �������� ������ �ȴ�.
            // �� �̰� �������� ���� ���� �ʰ� �н�.
            if(!hasSamed) answer.push_back("");

            // start���� �����µ� �������� �ϳ���� �װ� �װŴ�� ���� �ִ´�.
            if (start == s.length() - 2)
            {
                answer[answer.size() - 1] += s[i + 1];
            }

            hasSamed = true;
        }   // ��������� ���� ���. �ٸ��ٸ� �ִ´�.
        else
        {
            answer[answer.size() - 1] += s[i];
            // �������� ����ó��.
            if (i == s.length() - 2) // �������� �������� ���Ҵµ��� �ٸ��ٰ� �������Ƿ�
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