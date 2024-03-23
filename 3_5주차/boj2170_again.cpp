#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> P;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    P = vector<vector<int>>(N, vector<int>(2, 0));

    for (int i = 0; i < N; ++i)
    {
        cin >> P[i][0] >> P[i][1];
    }

    sort(P.begin(), P.end());

    int ret = 0;
    int s = P[0][0], e = P[0][1];
    for (int i = 1; i < N; ++i)
    {
        if (e < P[i][0])
        {
            ret += (e - s);
            s = P[i][0];
            e = P[i][1];
        }
        else if (e < P[i][1])
        {
            e = P[i][1];
        }
    }

    ret += (e - s);
    cout << ret;
}