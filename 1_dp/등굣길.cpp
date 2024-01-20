#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));

    for (auto p : puddles)
    {
        if (!p.empty())
            dp[p[0]][p[1]] = -1; // check puddles
    }

    for (int j = 0; j <= n; ++j)
        dp[0][j] = 0;
    dp[0][1] = 1;
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 0;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dp[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }
    answer = dp[m][n];

    return answer;
}

int ASTAR_TOOLONGTIME(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto p : puddles)
    {
        if (!p.empty())
            dp[p[0]][p[1]] = -1; // check puddles
    }

    vector<int> start = {1, 1};
    vector<vector<int>> candidates;
    candidates.push_back(start);
    vector<vector<int>> delta = {{1, 0}, {0, 1}};

    while (!candidates.empty())
    {
        vector<int> now = candidates.back();
        candidates.pop_back();
        for (auto d : delta)
        {
            int new_m = now[0] + d[0];
            int new_n = now[1] + d[1];

            if (new_m >= 1 && new_m <= m && new_n >= 1 && new_n <= n && dp[new_m][new_n] != -1)
            {
                candidates.push_back({new_m, new_n});
                dp[new_m][new_n] = (dp[new_m][new_n] + 1) % 1000000007;
            }
        }
    }

    answer = dp[m][n];

    return answer;
}