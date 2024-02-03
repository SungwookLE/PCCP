#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<vector<int>> city;

void dfs(int i, int j)
{

    if (j == W)
        return;

    if (j + 1 < W && city[i][j + 1] == -1)
    {
        city[i][j + 1] = city[i][j] + 1;
        dfs(i, j + 1);
    }
}

int main()
{
    cin >> H >> W;
    city = vector<vector<int>>(H, vector<int>(W, -1));

    vector<pair<int, int>> starts;
    string s;
    for (int i = 0; i < H; ++i)
    {
        cin >> s;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] == 'c')
            {
                city[i][j] = 0;
                starts.push_back({i, j});
            }
            if (s[j] == '.')
                city[i][j] = -1;
        }
    }

    for (auto start : starts)
    {
        dfs(start.first, start.second);
    }

    for (auto c : city)
    {
        for (auto cc : c)
            cout << cc << " ";
        cout << "\n";
    }

    return 0;
}