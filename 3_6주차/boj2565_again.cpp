#include <bits/stdc++.h>

using namespace std;
int N;
vector<pair<int, int>> P;
vector<int> DP;
int mx;

int main()
{

    cin >> N;
    P = vector<pair<int, int>>(N);
    DP = vector<int>(N, 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> P[i].first >> P[i].second;
    }

    sort(P.begin(), P.end());

    for (int i = 0; i < N; ++i)
    {

        for (int j = i - 1; j >= 0; --j)
        {
            if (P[i].second > P[j].second)
            {
                if (DP[i] < DP[j] + 1)
                {
                    DP[i] = DP[j] + 1;
                }
            }
        }

        if (mx < DP[i])
            mx = DP[i];
    }

    cout << N - mx;

    return 0;
}