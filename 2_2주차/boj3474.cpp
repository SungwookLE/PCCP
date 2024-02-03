#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int T;
ll N;
int temp;

ll dfs(ll i)
{

    cout << temp << endl;

    if (i == N)
        return N;

    temp = (dfs(i + 1) % 1000000001) * i;

    return temp;
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        cout << dfs(1);
    }

    return 0;
}