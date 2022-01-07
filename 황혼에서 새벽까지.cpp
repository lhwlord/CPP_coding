#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct
{
    int dest;   // ������ ����ȣ
    int arriveTime;   // �����ð�
    int blood; // �Ҹ��ϴ� ��
}info;

typedef struct
{
    int leastTime;   // �ּҷ� �����ϴ� �ð�. �ּ� �Ǻ��� �켱���� ����
    int leastBlood;   // �ּҷ� ����ϴ� ��. �켱���� ����
}least;

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<string> str;   // �̸��� ���� ���̴�.
        vector<vector<int>> line;   // ��� �ε����� ���� ������. �ε����� ��ȣ�ű�°� str��.
        vector<vector<pair<int, int>>> table;   // ��� ����� ��� �ε����� ���� ����ؼ� ���� ������. ������ line�� �����ش�.
        while (n--)
        {
            char a[33], b[33];
            int start, end;
            scanf("%32s %32s %d %d", a, b, &start, &end);
            string s_start(a), s_end(b);
            if ((start > 6) && (start < 18) || ((start + end) % 24 > 6) && ((start + end) % 24 < 18)) continue;   // ���� �ð��� ���� ��� ����
            if (find(str.begin(), str.end(), a) == str.end())   // �ش��ϴ� ���ڿ��� ������
            {
                str.push_back(a);
                line.push_back(vector<int>());
                table.push_back(vector<pair<int, int>>());
            }
            if (find(str.begin(), str.end(), b) == str.end())
            {
                str.push_back(b);
                line.push_back(vector<int>());
                table.push_back(vector<pair<int, int>>());
            }
            line[find(str.begin(), str.end(), s_start) - str.begin()].push_back(find(str.begin(), str.end(), s_end) - str.begin());
            table[find(str.begin(), str.end(), s_start) - str.begin()].push_back({ start, (start + end) % 24 });
        }

        // ���͵鿡 ������ �־���. ���� ����.
        vector<least> nodeInfo(line.size(), { -1, 2147483647 });   // �ʱⰪ ����. �ð��� -1�̸� �ʱⰪ�̶�� ��
        queue<info> q;
        string from, to;
        char temp1[33], temp2[33];
        scanf("%32s %32s", temp1, temp2);
        from = temp1;
        to = temp2;

        int from_index, to_index;
        from_index = find(str.begin(), str.end(), from) - str.begin();
        to_index = find(str.begin(), str.end(), to) - str.begin();   // �� �� ������ �̿��� ���� �ε����� �� �ε����� �����´�.

        if (line.size() != 0)q.push({ from_index, -6, 0 });

        while (!q.empty())
        {
            info temp = q.front();
            int blood_save = temp.blood;
            q.pop();
            //if (line[temp.dest].size() == 0) continue; // �ش� ��尡 ������ ��� ����

               // ������忡 ���������� �ּ��� Ȯ���ϰ����
            if (temp.dest == to_index)
            {
                if (nodeInfo[temp.dest].leastBlood > temp.blood) nodeInfo[temp.dest].leastBlood = temp.blood;
                goto escape;
            }
            for (int i = 0; i < line[temp.dest].size(); i++)
            {
                temp.blood = blood_save;
                if (nodeInfo[line[temp.dest][i]].leastTime != -1)// ��尡 �ʱⰪ�� �ƴ� ��쿡�� �����Ǵ�
                {
                    // �ش� ����� �ּ������� Ȯ���ߴµ� �ּ��Ǹ� �Ѱ�ٸ� ���� ����
                    if (nodeInfo[temp.dest].leastBlood < temp.blood) goto escape;
                    // �ش� ����� �ּ��������� �Ǵ� ������ �ð��� �� �̸��� �̹� �ִٸ� ���� ����
                    bool checkTime;
                    int tempTime = temp.arriveTime;
                    int nodeTime = nodeInfo[temp.dest].leastTime;
                    if (tempTime <= 6) tempTime += 24;
                    if (nodeTime <= 6) nodeTime += 24;
                    checkTime = tempTime < nodeTime;
                    if (nodeInfo[temp.dest].leastBlood == temp.blood && checkTime) goto escape;
                }
                // �� ���ǿ��� ��Ƴ��Ҵٸ�(ó�� ���� ���ų�, �ƴϸ� ���� �� ����� ����̹Ƿ�) �� ���� ���⿡ �����ϰ� ������ ��ε��� ť�� �ֱ�
                nodeInfo[temp.dest].leastBlood = temp.blood;
                nodeInfo[temp.dest].leastTime = temp.arriveTime;
                int time_temp = temp.arriveTime;
                int time_table = table[temp.dest][i].first;
                time_temp += time_temp <= 6 ? 24 : 0;
                time_table += time_table <= 6 ? 24 : 0;
                if (time_temp > time_table) temp.blood++;
                q.push({ line[temp.dest][i], table[temp.dest][i].second, temp.blood });
            }


        escape:;
        }

        // ť�� �� �����. ���� ��忡�� ���� ���� �Ҹ�� �Ǹ� ���.
        if (line.size() == 0 || nodeInfo[to_index].leastBlood == 2147483647) printf("����.\n");
        else printf("%d\n", nodeInfo[to_index].leastBlood);

    }
    return 0;
}