#include <bits/stdc++.h>

using namespace std;

int N, M, T;
vector<vector<int>> C;
vector<vector<int>> I;

void rotate_cw(vector<int> &a)
{
    rotate(a.begin(), a.end() - 1, a.end());
}

void rotate_ccw(vector<int> &a)
{
    rotate(a.begin(), a.begin() + 1, a.end());
}

int find_same()
{

    vector<vector<int>> check = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (C[i][j] != 0)
            {
                if (j == M - 1)
                {
                    if (C[i][j] == C[i][0])
                    {
                        check[i][j] = 1;
                        check[i][0] = 1;
                    }
                }
                else
                {
                    if (C[i][j] == C[i][j + 1])
                    {
                        check[i][j] = 1;
                        check[i][j + 1] = 1;
                    }
                }
            }
        }
    }

    for (int j = 0; j < M; ++j)
    {
        for (int i = 0; i < N - 1; ++i)
        {
            if (C[i][j] != 0)
            {
                if (C[i][j] == C[i + 1][j])
                {
                    check[i][j] = 1;
                    check[i + 1][j] = 1;
                }
            }
        }
    }

    bool isSame = false;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (C[i][j] != 0)
            {
                if (check[i][j] == 1)
                {
                    isSame = true;
                    C[i][j] = 0;
                }
                else
                {
                    cnt++;
                }
                sum += C[i][j];
            }
        }
    }

    double mean = (double)sum / (double)cnt;
    if (!isSame)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {

                if (C[i][j] != 0)
                {
                    if ((double)C[i][j] > mean)
                    {

                        C[i][j] -= 1;
                        sum -= 1;
                    }
                    else if ((double)C[i][j] < mean)
                    {

                        C[i][j] += 1;
                        sum += 1;
                    }
                }
            }
        }
    }

    return sum;
}

void debug()
{

    cout << endl;

    for (auto cc : C)
    {
        for (auto c : cc)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{

    cin >> N >> M >> T;
    C = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> C[i][j];
        }
    }

    int x, d, k;
    for (int i = 0; i < T; ++i)
    {
        cin >> x >> d >> k;
        I.push_back({x, d, k});
    }
    int ret;
    for (auto input : I)
    {

        for (int i = 1; i <= N; ++i)
        {
            if (i % input[0] == 0)
            {
                if (input[1] == 0)
                {
                    int k = input[2];
                    while (k > 0)
                    {
                        rotate_cw(C[i - 1]);
                        k--;
                    }
                }
                else
                {
                    int k = input[2];
                    while (k > 0)
                    {
                        rotate_ccw(C[i - 1]);
                        k--;
                    }
                }
            }
        }

        ret = find_same();
    }

    cout << ret << "\n";

    return 0;
}