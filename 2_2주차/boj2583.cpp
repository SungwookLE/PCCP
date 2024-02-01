#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> paper, visited;
vector<vector<int>> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int M, N, K;

int dfs(int i, int j, int count)
{

    visited[i][j] = 1;
    count += 1;

    for (auto d : deltas)
    {
        int next_i = i + d[0];
        int next_j = j + d[1];

        if (next_i >= 0 && next_j >= 0 && next_i < M && next_j < N)
        {
            if (visited[next_i][next_j] == 0 && paper[next_i][next_j] == 0)
                count = dfs(next_i, next_j, count);
        }
    }

    return count; // 최종 바깥으로 나가는 출력임
}

int main()
{

    cin >> M >> N >> K;
    paper = vector<vector<int>>(M, vector<int>(N, 0));
    visited = vector<vector<int>>(M, vector<int>(N, 0));

    for (int i = 0; i < K; ++i)
    {

        pair<int, int> vertex1, vertex2;
        cin >> vertex1.second >> vertex1.first; // Left-Down (i, j) (2, 0)
        cin >> vertex2.second >> vertex2.first; // Right-Up (i, j) (4, 4)

        int start_i = vertex1.first; // 2
        int end_i = vertex2.first;   // 4

        int start_j = vertex1.second; // 0
        int end_j = vertex2.second;   // 4

        for (int ii = start_i; ii < end_i; ++ii)
        {
            for (int jj = start_j; jj < end_j; ++jj)
            {
                paper[ii][jj] = i + 1;
            }
        }
    }

    vector<int> answer;
    int count = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {

            if (visited[i][j] == 0 && paper[i][j] == 0)
            {
                count++;
                int ret = dfs(i, j, 0);
                answer.push_back(ret);
            }
        }
    }

    cout << count << "\n";
    sort(answer.begin(), answer.end());

    for (auto a : answer)
        cout << a << " ";

    return 0;
}