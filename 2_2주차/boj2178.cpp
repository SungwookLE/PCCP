#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> maze;
vector<vector<int>> searched;
queue<vector<int>> candidates;
vector<vector<int>> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{

    int N, M;
    cin >> N >> M;
    maze = vector<vector<int>>(N, vector<int>(M, 0));
    searched = vector<vector<int>>(N, vector<int>(M, 0));

    /* 1. 이렇게 받거나, 근데 꼭 bufferflush가 필요함
    string s;
    getline(cin, s); // bufferflush, 이거 안해주면 쓰레기값이 하나 들어온다..
    for (int i = 0; i < N; ++i)
    {
        getline(cin, s);
        for (int j = 0; j < M; ++j)
        {
            maze[i][j] = s[j] - '0'; // 문자'1'과 숫자1은 다르다. 문자'1'은 아스키코드로 49이다. 1이 아니다.
        }
    }
    */

    // 2. 이렇게 받거나
    string s;
    for (int i = 0; i < N; ++i)
    {
        cin >> s;
        for (int j = 0; j < M; ++j)
        {
            maze[i][j] = s[j] - '0'; // 문자'1'과 숫자1은 다르다. 문자'1'은 아스키코드로 49이다. 1이 아니다.
        }
    }


    candidates.push({0, 0}); // start
    searched[0][0] = 1;

    while (!candidates.empty())
    {

        vector<int> now = candidates.front();
        candidates.pop(); // 방문

        if (now[0] == N - 1 && now[1] == M - 1)
        {
            cout << searched[now[0]][now[1]] << endl;
            return 0;
        }

        for (auto d : deltas)
        {
            int next_i = now[0] + d[0];
            int next_j = now[1] + d[1];

            if (next_i >= 0 && next_j >= 0 && next_i < N && next_j < M)
            {
                if (searched[next_i][next_j] == 0 && maze[next_i][next_j] == 1)
                {
                    searched[next_i][next_j] = searched[now[0]][now[1]] + 1;
                    candidates.push({next_i, next_j});
                }
            }
        }
    }

    cout << "-1\n";

    return 0;
}