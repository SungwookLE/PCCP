#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> city, visited;
vector<vector<int>> houses, chickens;
const int mx = 51 * 13 + 1000;
int ans = mx;

int get_distance(vector<int> &house, vector<int> &chicken)
{
    return abs(house[0] - chicken[0]) + abs(house[1] - chicken[1]);
}

int get_cityDistance(vector<vector<int>> &_houses, vector<vector<int>> &_chickens)
{
    int total_dist = 0;
    for (auto house : _houses)
    {
        int dist = mx;
        for (auto chicken : _chickens)
        {
            dist = min(get_distance(house, chicken), dist);
        }
        total_dist += dist;
    }
    return total_dist;
}

void go(int start, vector<vector<int>> v)
{
    if (ans == M)
        return;
    if (v.size() == M)
    {
        int dist = get_cityDistance(houses, v);
        ans = min(dist, ans);
        return;
    }

    for (int i = start + 1; i < chickens.size(); ++i)
    { // 와 이거.. 순서 상관없으니까 조건 따져야함
        if (visited[chickens[i][0]][chickens[i][1]] == 0)
        {
            visited[chickens[i][0]][chickens[i][1]] = 1;
            v.push_back(chickens[i]);
            go(i, v);
            v.pop_back();
            visited[chickens[i][0]][chickens[i][1]] = 0;
        }
    }

    return;
}

int main()
{
    cin >> N >> M;
    city = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> city[i][j];
            if (city[i][j] == 1)
                houses.push_back({i, j});
            else if (city[i][j] == 2)
                chickens.push_back({i, j});
        }

    // 현재 치킨집보다 최종 치킨집의 개수가 적다면, combination으로 뽑아야함, 치킨집을
    // 뽑은 치킨집을 기준으로 치킨거리를 구하고, 치킨 거리를 출력하면 됨
    // 치킨거리는 모든 집의 치킨 거리의 합 (1<->2)

    go(-1, {});
    cout << ans << endl;

    return 0;
}