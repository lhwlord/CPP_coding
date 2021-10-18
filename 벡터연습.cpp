#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;

    int left, right;

    if (v[0][0] == v[1][0]) left = v[2][0];
    else if (v[0][0] == v[2][0]) left = v[1][0];
    else left = v[0][0];

    if (v[0][1] == v[1][1]) right = v[2][1];
    else if (v[0][1] == v[2][1]) right = v[1][1];
    else right = v[0][1];

    ans.push_back(left);
    ans.push_back(right);

    return ans;
}

int main(void)
{
    vector<vector<int>> v = { {1,4},{3,4},{3,10} };
    vector<int> s = solution(v);

    cout << s[0] << " " << s[1] << endl;
    return 0;
}