#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A, B;
vector<vector<int>> DP;

int main()
{
    cin >> N;
    A = vector<int>(N, 0);
    B = vector<int>(N, 0);

    DP = vector<vector<int>>(N + 1, vector<int>(101, 0));

    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> B[i];

    for (int j = 1; j <= 100; ++j)
    {
        for (int i = 1; i <= N; ++i)
        {
            if (A[i - 1] < j)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - A[i - 1]] + B[i - 1]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    cout << DP[N][100];

    return 0;
}