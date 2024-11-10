#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> Attack = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 3, 9}, {1, 9, 3}};
vector<int> SCV;
int visited[61][61][61] = {
    0,
};
queue<vector<int>> candidates;
int main()
{
    cin >> N;
    SCV.resize(3, 0);
    for (int i = 0; i < N; ++i)
        cin >> SCV[i];
    candidates.push(SCV);
    visited[SCV[0]][SCV[1]][SCV[2]] = 1;

    while (candidates.size())
    {
        auto now = candidates.front();
        candidates.pop();

        if (now[0] == 0 && now[1] == 0 && now[2] == 0)
            break;

        for (auto at : Attack)
        {
            int p = max(0, now[0] - at[0]);
            int q = max(0, now[1] - at[1]);
            int r = max(0, now[2] - at[2]);

            if (visited[p][q][r] != 0)
                continue;
            visited[p][q][r] = visited[now[0]][now[1]][now[2]] + 1;
            candidates.push({p, q, r});
        }
    }
    cout << visited[0][0][0] - 1;
    return 0;
}