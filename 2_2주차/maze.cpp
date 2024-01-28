#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> maze(3, vector<int>(3, 0));
vector<vector<int>> directions = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};
vector<vector<int>> visited(3, vector<int>(3, 0));

void dfs(int i, int j, int id)
{
    cout << id << ": (" << i << "," << j << ")\n";
    visited[i][j] = 1;

    for (auto d : directions)
    {

        int next_i = i + d[0];
        int next_j = j + d[1];

        if (next_i >= 0 && next_j >= 0 && next_i < 3 && next_j < 3)
        {
            if (visited[next_i][next_j] == 0 && maze[next_i][next_j] == 1)
            {
                dfs(next_i, next_j, id);
            }
        }
    }
}

int main()
{

    // 3 x 3 input
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            cin >> maze[i][j];
    }

    // fluid - fill , 연결된 컴포넌트에 id 부여하기ㄴ
    int id = 1;
    for(int i = 0 ; i < 3; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            if (visited[i][j] == 0 && maze[i][j] == 1){
                dfs(i, j, id);
                id++;
            }
        }
    }
}