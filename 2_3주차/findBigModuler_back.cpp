#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> v;
int ret = 0;

void go(int idx, int sum)
{
    if (ret == 10) return;

    if (idx == N)
    {
        ret = max(ret, sum%11);
        return ;
    }

    go(idx + 1, sum + v[idx]); go(idx + 1, sum);

    return ;
}

int main()
{
    cin >> N;
    v = vector<int>(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    go(0, 0);
    cout << ret<<endl;

    return 0;
}