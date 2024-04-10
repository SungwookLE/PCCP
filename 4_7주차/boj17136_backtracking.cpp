#include <bits/stdc++.h>

using namespace std;

#define INFI 987654321
vector<vector<int>> Paper(10, vector<int>(10, 0));

int ret = INFI;
map<int, int> mp;

bool check(pair<int, int> s, int sz)
{
    if (s.first + sz > 10 || s.second + sz > 10)
        return false;

    for (int i = s.first; i < s.first + sz; ++i)
    {
        for (int j = s.second; j < s.second + sz; ++j)
        {
            if (Paper[i][j] == 0)
                return false;
        }
    }

    return true;
}

void draw(pair<int, int> s, int sz, int value)
{

    for (int i = s.first; i < s.first + sz; ++i)
    {
        for (int j = s.second; j < s.second + sz; ++j)
        {
            Paper[i][j] = value;
        }
    }
    return;
}

void dfs(pair<int, int> here, int cnt)
{
    if (cnt >= ret)
        return; // 백트래킹, 조기 종료

    if (here.second == 10)
    {
        // 기저사례(base case)
        dfs({here.first + 1, 0}, cnt);
        return;
    }

    if (here.first == 10)
    {
        // 기저사례(base case)
        ret = min(cnt, ret);
        return;
    }

    if (Paper[here.first][here.second] == 0)
    {
        // 기저사례(base case)
        dfs({here.first, here.second + 1}, cnt);
        return;
    }

    for (int sz = 5; sz >= 1; --sz)
    {
        // 사이즈가 큰거부터 넣어보는게 좀 더 빠르겠지 (휴리스틱)
        if (mp[sz] == 0)
            continue;
        if (check(here, sz))
        {
            mp[sz]--;
            draw(here, sz, 0);
            dfs({here.first, here.second + sz}, cnt + 1);
            draw(here, sz, 1);
            mp[sz]++;
        }
    }
    return;
}

int main()
{

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin >> Paper[i][j];
        }
    }

    mp[1] = 5;
    mp[2] = 5;
    mp[3] = 5;
    mp[4] = 5;
    mp[5] = 5;
    dfs({0, 0}, 0);

    if (ret == INFI)
        cout << -1;
    else
        cout << ret;

    return 0;
}