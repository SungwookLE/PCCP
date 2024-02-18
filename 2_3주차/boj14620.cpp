#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> garden, visited;
vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int mn = 5000;

// 꽃 씨앗은 3개 밖에 없음
// 꽃이 만개하면 5평의 땅을 필요로함
// 꽃임이 닿게 되면 안된다. 화단 밖으로 삐쳐나와도 안된다.
// 꽃을 심기 위해 필요한 최소 비용

void go(vector<vector<int>> &seed, int cnt, int sum)
{
    // seed 배열은 디버깅을 위해 인자로 설정함
    
    if (cnt == 3)
    {
        // cout << "=============\n";
        // for(auto ss : seed){
        //     cout << ss[0] << ", " << ss[1] << endl;
        // }
        mn = min(sum, mn);
        return;
    }

    for (int i = 1; i < N - 1; ++i)
    {
        for (int j = 1; j < N - 1; ++j)
        {

            bool isOk = true;
            for (auto d : delta)
            {
                int next_i = i + d[0];
                int next_j = j + d[1];
                if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= N)
                {
                    isOk = false;
                    break;
                }
                if (visited[next_i][next_j])
                {
                    isOk = false;
                    break;
                }
            }

            if (isOk)
            {

                visited[i][j] = 1;
                visited[i - 1][j] = 1;
                visited[i + 1][j] = 1;
                visited[i][j - 1] = 1;
                visited[i][j + 1] = 1;

                int add = garden[i][j] + garden[i - 1][j] + garden[i + 1][j] + garden[i][j - 1] + garden[i][j + 1];
                seed.push_back({i, j});
                go(seed, cnt + 1, sum + add);
                seed.pop_back();
                visited[i][j] = 0;
                visited[i - 1][j] = 0;
                visited[i + 1][j] = 0;
                visited[i][j - 1] = 0;
                visited[i][j + 1] = 0;
            }
        }
    }
}

int main()
{
    cin >> N; // (6<=N<=10)
    garden = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> garden[i][j];
    }

    vector<vector<int>> seed;
    go(seed, 0, 0); //

    cout << mn << endl;

    return 0;
}