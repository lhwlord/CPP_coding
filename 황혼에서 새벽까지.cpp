#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct
{
    int dest;   // 목적지 노드번호
    int arriveTime;   // 도착시각
    int blood; // 소모하는 피
}info;

typedef struct
{
    int leastTime;   // 최소로 도착하는 시간. 최소 피보다 우선순위 낮음
    int leastBlood;   // 최소로 사용하는 피. 우선순위 높음
}least;

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<string> str;   // 이름을 담을 것이다.
        vector<vector<int>> line;   // 몇번 인덱스가 어디로 가는지. 인덱스에 번호매기는건 str로.
        vector<vector<pair<int, int>>> table;   // 어느 노드의 몇번 인덱스가 언제 출발해서 어디로 가는지. 방향은 line이 정해준다.
        while (n--)
        {
            char a[33], b[33];
            int start, end;
            scanf("%32s %32s %d %d", a, b, &start, &end);
            string s_start(a), s_end(b);
            if ((start > 6) && (start < 18) || ((start + end) % 24 > 6) && ((start + end) % 24 < 18)) continue;   // 지정 시간을 넘은 경우 제낌
            if (find(str.begin(), str.end(), a) == str.end())   // 해당하는 문자열이 없으면
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

        // 벡터들에 적당히 넣었다. 이제 시작.
        vector<least> nodeInfo(line.size(), { -1, 2147483647 });   // 초기값 설정. 시각이 -1이면 초기값이라는 뜻
        queue<info> q;
        string from, to;
        char temp1[33], temp2[33];
        scanf("%32s %32s", temp1, temp2);
        from = temp1;
        to = temp2;

        int from_index, to_index;
        from_index = find(str.begin(), str.end(), from) - str.begin();
        to_index = find(str.begin(), str.end(), to) - str.begin();   // 이 두 구문을 이용해 시작 인덱스와 끝 인덱스를 가져온다.

        if (line.size() != 0)q.push({ from_index, -6, 0 });

        while (!q.empty())
        {
            info temp = q.front();
            int blood_save = temp.blood;
            q.pop();
            //if (line[temp.dest].size() == 0) continue; // 해당 노드가 말단인 경우 빠꾸

               // 목적노드에 도달했으면 최소피 확보하고빠꾸
            if (temp.dest == to_index)
            {
                if (nodeInfo[temp.dest].leastBlood > temp.blood) nodeInfo[temp.dest].leastBlood = temp.blood;
                goto escape;
            }
            for (int i = 0; i < line[temp.dest].size(); i++)
            {
                temp.blood = blood_save;
                if (nodeInfo[line[temp.dest][i]].leastTime != -1)// 노드가 초기값이 아닌 경우에만 빠꾸판단
                {
                    // 해당 노드의 최소정보를 확인했는데 최소피를 넘겼다면 역시 빠꾸
                    if (nodeInfo[temp.dest].leastBlood < temp.blood) goto escape;
                    // 해당 노드의 최소정보에서 피는 같은데 시각이 더 이른게 이미 있다면 또한 빠꾸
                    bool checkTime;
                    int tempTime = temp.arriveTime;
                    int nodeTime = nodeInfo[temp.dest].leastTime;
                    if (tempTime <= 6) tempTime += 24;
                    if (nodeTime <= 6) nodeTime += 24;
                    checkTime = tempTime < nodeTime;
                    if (nodeInfo[temp.dest].leastBlood == temp.blood && checkTime) goto escape;
                }
                // 위 조건에서 살아남았다면(처음 보는 노드거나, 아니면 내가 더 우월한 경우이므로) 내 값을 여기에 적용하고 나머지 경로들을 큐에 넣기
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

        // 큐가 다 비었다. 목적 노드에서 가장 적게 소모된 피를 출력.
        if (line.size() == 0 || nodeInfo[to_index].leastBlood == 2147483647) printf("못감.\n");
        else printf("%d\n", nodeInfo[to_index].leastBlood);

    }
    return 0;
}