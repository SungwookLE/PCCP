#include <bits/stdc++.h>

using namespace std;

vector<int> adj[25];
int searched[25];
queue<int> candidates;

void bfs(int here)
{

    candidates.push(here);
    searched[here] = 1; // 방문 했는지 아닌지 정보와, 이동비용 정보를 담고 있음

    while (!candidates.empty())
    {

        int now = candidates.front();
        candidates.pop(); // 이제 해당 노드에 자신이 위치(방문)하게 됨

        for (auto v : adj[now])
        {

            if (searched[v] == 0)
            {
                candidates.push(v);
                searched[v] = searched[now] + 1; // 탐색 완료
            }
        }
    }
}

int main()
{

    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);
    for(auto v : searched)
        cout << v << " ";
    cout << endl;

    return 0;
}