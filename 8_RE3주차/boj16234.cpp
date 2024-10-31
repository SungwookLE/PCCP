#include <bits/stdc++.h>

using namespace std;

int N, L, R;
vector<vector<int>> Land, newLand, visited;

int days = 0;
vector<int> delta[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> record;

vector<int> dfs(pair<int, int> here, int flag)
{   
    record.push_back(here);
    int sum = Land[here.first][here.second];
    int cnt = 1;
    visited[here.first][here.second] = flag;

    for (auto &d : delta)
    {
        int next_i = here.first + d[0];
        int next_j = here.second + d[1];

        if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= N)
            continue;
        if (visited[next_i][next_j] != 0)
            continue;
        
        int delta  = abs(Land[here.first][here.second] - Land[next_i][next_j]);
        if (delta >= L && delta <= R)
        {
            auto ret = dfs({next_i, next_j}, flag);
            sum += ret[0];
            cnt += ret[1];
        }
    }
    return {sum, cnt};
}

int main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> L >> R;
    Land.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Land[i][j];
        }
    }

    newLand = Land;
    while (1)
    {

        visited = vector<vector<int>>(N, vector<int>(N, 0));
        vector<vector<int>> ret;
        // 국경이 열리고, 인구가 조정된 뒤
        int count = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[i][j] == 0)
                {
                    count++;
                    ret.push_back(dfs({i, j}, count)); // 연합국 체크

                    for(auto r: record){
                        newLand[r.first][r.second] = ret.back()[0]/ret.back()[1];
                    }

                    record.clear();
                }
            }
        }

        // 더 이상 조정될 수 없을 때 까지
        if (count == N * N)
        {
            break;
        }

        Land = newLand;
        days++;
    }

    cout << days << endl;

    return 0;
}