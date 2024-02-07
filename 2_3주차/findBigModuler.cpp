#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> v;

int go(int idx, int sum)
{
    if (idx == N)
    {
        int ret = sum % 11;
        return ret;
    }

    return max(go(idx + 1, sum + v[idx]), go(idx + 1, sum));
}

int main()
{
    cin >> N;
    v = vector<int>(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    cout << go(0, 0);

    return 0;
}