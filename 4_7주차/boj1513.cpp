#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, C;
pair<int, int> start, goal;
vector<vector<int>> delta = {{1, 0}, {0, 1}};
const int mod = 1000007;

int DP[51][51][51][51];
int G[51][51];

int go(int i, int j, int cnt, int prev)
{

    if (i > N || j > M)
        return 0;
    if (i == N && j == M)
    {
        if (cnt == 0 && G[i][j] == 0)
            return 1;
        if (cnt == 1 && G[i][j] > prev)
            return 1;
        return 0;
    }

    int &ret = DP[i][j][cnt][prev];
    if (ret != -1)
        return ret;

    ret = 0;
    if (G[i][j] == 0)
    {
        ret = (go(i + 1, j, cnt, prev) + go(i, j + 1, cnt, prev)) % mod;
    }
    else if (G[i][j] > prev)
    {
        ret = (go(i + 1, j, cnt - 1, G[i][j]) + go(i, j + 1, cnt - 1, G[i][j])) % mod;
    }

    return ret;
}

int main()
{
    cin >> N >> M >> C;

    start = {1, 1};
    goal = {N, M};

    memset(DP, -1, sizeof(DP));

    int y, x;
    for (int i = 1; i <= C; ++i)
    {
        cin >> y >> x;
        G[y][x] = i;
    }

    for (int i = 0; i <= C; ++i)
    {
        cout << go(1, 1, i, 0) << " ";
    }

    return 0;
}