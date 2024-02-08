#include <bits/stdc++.h>

using namespace std;
int N, L, R;
vector<vector<int>> world;
vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> opens;
vector<int> result;

int dfs(vector<int> here, int &cnt, int number)
{
    cnt++;
    int ret = world[here[0]][here[1]];
    opens[here[0]][here[1]] = number;

    for (auto d : delta)
    {
        int next_i = here[0] + d[0];
        int next_j = here[1] + d[1];

        if (next_i >= 0 && next_j >= 0 && next_i < N && next_j < N)
        {
            int diff = abs(world[here[0]][here[1]] - world[next_i][next_j]);
            if (diff >= L && diff <= R && opens[next_i][next_j] == -1 )
                ret += dfs({next_i, next_j}, cnt, number);
        }
    }

    return ret;
}

int main()
{
    cin >> N >> L >> R;
    world = vector<vector<int>>(N, vector<int>(N, 0));

    result = vector<int>(N*N+1, 0);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> world[i][j];
    }
    int ans = 0;

    while (true)
    {
        opens = vector<vector<int>>(N, vector<int>(N, -1));
        int ret = 0;

        int number = 1;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                int cnt = 0;
                if (opens[i][j] == -1){
                    ret = dfs({i, j}, cnt, number);
                    result[number] = ret/cnt;
                    number++;
                }   
            }
        }

        for(int i = 0; i < N ; ++i){
            for(int j =0 ; j < N ; ++j){
                world[i][j] = result[opens[i][j]];
            }
        }

        if (number - 1 == N * N)
            break;
        ans++;
    }

    cout << ans;

    return 0;
}