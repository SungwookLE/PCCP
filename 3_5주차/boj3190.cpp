#include <bits/stdc++.h>

using namespace std;
int N, K, L;                        // 보드 사이즈, 사과 개수, 조작 개수
vector<vector<int>> B;              // 보드
vector<vector<int>> M;              // 조작 정보
deque<pair<int, int>> H = {{0, 0}}; // 뱀위 위치 정보

int now = 1; // 현재 시간
int ans;     // 출력

void rotate90R(vector<vector<int>> &B, deque<pair<int, int>> &here)
{
    vector<vector<int>> temp = B;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {

            temp[i][j] = B[N - j - 1][i];
        }
    }
    B = temp;

    deque<pair<int, int>> tempS;

    while (here.size())
    {
        pair<int, int> c = here.front();
        pair<int, int> trans_c;

        trans_c.first = c.second;
        trans_c.second = N - c.first - 1;

        tempS.push_back(trans_c);
        here.pop_front();
    }

    here = tempS;
}

void rotate90L(vector<vector<int>> &B, deque<pair<int, int>> &here)
{
    vector<vector<int>> temp = B;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {

            temp[i][j] = B[j][N - i - 1];
        }
    }
    B = temp;

    deque<pair<int, int>> tempS;

    while (here.size())
    {
        pair<int, int> c = here.front();
        pair<int, int> trans_c;

        trans_c.first = N - c.second - 1;
        trans_c.second = c.first;

        tempS.push_back(trans_c);
        here.pop_front();
    }

    here = tempS;
}

void debug(vector<vector<int>> &B, deque<pair<int, int>> S)
{

    vector<vector<int>> tempB = B;

    for (auto it = S.begin(); it != S.end(); ++it)
    {
        tempB[it->first][it->second] = 9;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << tempB[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool move_Right(deque<pair<int, int>> &here)
{

    int next_i = here.front().first;
    int next_j = here.front().second + 1;

    if (next_j < 0 || next_j >= N)
        return false;
    for (auto it = here.begin(); it != here.end(); ++it)
    {
        if (next_i && next_i == it->first && next_j == it->second)
        {
            return false;
        }
    }

    if (B[next_i][next_j] == 0)
    {
        here.pop_back();
    }
    else
    {
        B[next_i][next_j] = 0;
    }

    here.push_front({next_i, next_j});

    return true;
}

int main()
{
    cin >> N >> K;
    B = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < K; ++i)
    {
        int row, col;
        cin >> row >> col;
        B[row - 1][col - 1] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; ++i)
    {
        int X;
        char D;
        cin >> X >> D;
        if (D == 'D')
            M.push_back({X, 0});
        else
            M.push_back({X, 1});
    }

    for (auto m : M)
    {
        for (int i = now; i <= m[0]; ++i)
        {
            bool ret = move_Right(H);

            if (!ret)
            {
                ans = i;
                cout << ans;
                return 0;
            }
        }

        if (m[1] == 0)
        {
            // 오른쪽
            rotate90L(B, H);
        }
        else
        {
            rotate90R(B, H);
        }

        now = m[0] + 1;
    }

    while (true)
    {

        bool ret = move_Right(H);

        if (!ret)
        {
            ans = now;
            cout << ans;
            return 0;
        }
        now++;
    }

    return 0;
}
