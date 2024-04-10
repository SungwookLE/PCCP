#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<vector<int>> A;
vector<vector<int>> Land;
vector<vector<vector<int>>> Tree;
vector<vector<vector<int>>> deadTree;
vector<vector<int>> delta = {{-1, 0}, {-1, -1}, {-1, 1}, {0, 1}, {0, -1}, {1, 0}, {1, -1}, {1, 1}};
int cnt;

void spring()
{

    deadTree = vector<vector<vector<int>>>(N, vector<vector<int>>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {

            int sz = Tree[i][j].size();
            if (sz)
            {
                sort(Tree[i][j].begin(), Tree[i][j].end());

                for (int k = 0; k < sz; ++k)
                {
                    if (Land[i][j] >= Tree[i][j][k])
                    {
                        Land[i][j] -= Tree[i][j][k];
                        Tree[i][j][k] += 1;
                    }
                    else
                    {
                        deadTree[i][j].insert(deadTree[i][j].begin(), Tree[i][j].begin() + k, Tree[i][j].end());
                        Tree[i][j].erase(Tree[i][j].begin() + k, Tree[i][j].end());
                        break;
                    }
                }
            }
        }
    }
}

void summer()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int sz = deadTree[i][j].size();

            if (sz)
            {
                for (int k = 0; k < sz; ++k)
                {
                    Land[i][j] += deadTree[i][j][k] / 2;
                }
            }
        }
    }
}

void fall()
{

    vector<vector<vector<int>>> nextTree = Tree;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {

            int sz = Tree[i][j].size();
            if (sz)
            {

                for (int k = 0; k < sz; ++k)
                {
                    if (Tree[i][j][k] % 5 == 0)
                    {

                        for (auto &d : delta)
                        {
                            int next_i = i + d[0];
                            int next_j = j + d[1];

                            if (next_i < 0 || next_i >= N)
                                continue;
                            if (next_j < 0 || next_j >= N)
                                continue;

                            nextTree[next_i][next_j].push_back({1});
                        }
                    }
                }
            }
        }
    }

    Tree = nextTree;
}

void winter()
{
    cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Land[i][j] += A[i][j];
            cnt += Tree[i][j].size();
        }
    }
}

void debug()
{
    cout << "DEBUG" << endl;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << "{";
            for (int k = 0; k < Tree[i][j].size(); ++k)
            {
                cout << Tree[i][j][k] << ",";
            }
            cout << "}\t";
        }
        cout << endl;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K; // 땅의크기(N), 나무의개수(M), 년수(K)

    Land = vector<vector<int>>(N, vector<int>(N, 5));
    A = vector<vector<int>>(N, vector<int>(N, 0));
    Tree = vector<vector<vector<int>>>(N, vector<vector<int>>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
    }

    int a, b, age;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> age;
        Tree[a - 1][b - 1].push_back(age);
    }

    for (int i = 0; i < K; ++i)
    {
        spring();
        summer();
        fall();
        winter();
    }

    cout << cnt << "\n";

    return 0;
}