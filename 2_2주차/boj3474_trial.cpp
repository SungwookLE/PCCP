#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int T;
ll N;
ll cnt;

ll dfs(ll N)
{
    if (N == 2)
        return 2;

    ll temp = dfs(N - 1);

    while (temp % 10 == 0)
    {
        cnt++;
        temp /= 10;
    }
   
    return (temp%1000000000 * N)%1000000000;
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cnt = 0;
        cin >> N ;
        
        ll ret = dfs(N);
        while (ret % 10 == 0)
        {
            cnt++;
            ret /= 10;
        }
        cout << cnt << endl;
    }

    return 0;
}