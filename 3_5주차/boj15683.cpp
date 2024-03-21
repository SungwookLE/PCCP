#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> ROOM;
vector<pair<int, int>> Cameras;
int ret = 987654321;

vector<pair<int, int>> RIGHT_ON(pair<int, int> origin)
{

    vector<pair<int, int>> changes;
    for (int j = origin.second; j < M; ++j)
    {
        if (ROOM[origin.first][j] == 6)
            break;
        if (ROOM[origin.first][j] != 0)
            continue;

        changes.push_back({origin.first, j});
        ROOM[origin.first][j] = 8;
    }
    return changes;
}

vector<pair<int, int>> LEFT_ON(pair<int, int> origin)
{
    vector<pair<int, int>> changes;

    for (int j = origin.second; j >= 0; --j)
    {
        if (ROOM[origin.first][j] == 6)
            break;
        if (ROOM[origin.first][j] != 0)
            continue;

        changes.push_back({origin.first, j});
        ROOM[origin.first][j] = 8;
    }
    return changes;
}

vector<pair<int, int>> UP_ON(pair<int, int> origin)
{
    vector<pair<int, int>> changes;

    for (int i = origin.first; i >= 0; --i)
    {
        if (ROOM[i][origin.second] == 6)
            break;
        if (ROOM[i][origin.second] != 0)
            continue;

        changes.push_back({i, origin.second});
        ROOM[i][origin.second] = 8;
    }
    return changes;
}

vector<pair<int, int>> DOWN_ON(pair<int, int> origin)
{
    vector<pair<int, int>> changes;

    for (int i = origin.first; i < N; ++i)
    {
        if (ROOM[i][origin.second] == 6)
            break;
        if (ROOM[i][origin.second] != 0)
            continue;

        changes.push_back({i, origin.second});
        ROOM[i][origin.second] = 8;
    }
    return changes;
}

vector<pair<int, int>> rotate_camera(pair<int, int> now, int type, int direction)
{
    vector<pair<int, int>> changes, temp;

    if (type == 1)
    {
        if (direction == 0)
            changes = RIGHT_ON(now);
        if (direction == 1)
            changes = LEFT_ON(now);
        if (direction == 2)
            changes = UP_ON(now);
        if (direction == 3)
            changes = DOWN_ON(now);
    }
    else if (type == 2)
    {
        if (direction == 0 || direction == 1)
        {
            changes = RIGHT_ON(now);
            temp = LEFT_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
        if (direction == 2 || direction == 3)
        {
            changes = UP_ON(now);
            temp = DOWN_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
    }
    else if (type == 3)
    {
        if (direction == 0)
        {
            changes = RIGHT_ON(now);
            temp = UP_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
        if (direction == 1)
        {
            changes = RIGHT_ON(now);
            temp = DOWN_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
        if (direction == 2)
        {
            changes = DOWN_ON(now);
            temp = LEFT_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
        if (direction == 3)
        {
            changes = LEFT_ON(now);
            temp = UP_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
    }
    else if (type == 4)
    {
        if (direction == 0)
        {
            changes = RIGHT_ON(now);
            temp = LEFT_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
            temp = UP_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
        if (direction == 1)
        {
            changes = DOWN_ON(now);
            temp = UP_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
            temp = RIGHT_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
        if (direction == 2)
        {
            changes = RIGHT_ON(now);
            temp = LEFT_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
            temp = DOWN_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
        if (direction == 3)
        {
            changes = UP_ON(now);
            temp = DOWN_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
            temp = LEFT_ON(now);
            changes.insert(changes.end(), temp.begin(), temp.end());
        }
    }
    else if (type == 5)
    {
        changes = RIGHT_ON(now);
        temp = LEFT_ON(now);
        changes.insert(changes.end(), temp.begin(), temp.end());
        temp = UP_ON(now);
        changes.insert(changes.end(), temp.begin(), temp.end());
        temp = DOWN_ON(now);
        changes.insert(changes.end(), temp.begin(), temp.end());
    }
    return changes;
}

void dfs(int here)
{

    if (here == Cameras.size())
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (ROOM[i][j] == 0)
                    cnt++;
            }
        }
        ret = min(cnt, ret);
        return;
    }

    for (int direction = 0; direction < 4; ++direction)
    {
        vector<pair<int, int>> changes = rotate_camera(Cameras[here], ROOM[Cameras[here].first][Cameras[here].second], direction);
        dfs(here + 1);
        for (auto b : changes)
            ROOM[b.first][b.second] = 0;
    }
}

void print()
{
    for (auto rr : ROOM)
    {
        for (auto r : rr)
            cout << r << "\t";
        cout << endl;
    }
}

int main()
{
    // 사무실의 크기와 상태, 그리고 CCTV의 정보가 주어졌을 때, CCTV의 방향을 적절히 정해서, 사각 지대의 최소 크기를 구하는 프로그램을 작성하시오.

    cin >> N >> M;
    ROOM = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {

            cin >> ROOM[i][j];
            if (ROOM[i][j] != 0 && ROOM[i][j] != 6 && ROOM[i][j] != -1)
            {
                Cameras.push_back({i, j});
            }
        }
    }

    dfs(0);
    cout << ret;

    return 0;
}