#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    if (a >= b)
        return gcd(b, a % b);
    else
        return gcd(a, b % a);
}

int main()
{

    ll N;
    while (cin >> N)
    {

        ll mod = 1;
        for (ll i = 0; i < 1000000000; ++i)
        {
            if (N <= mod)
            {
                // cout << mod << " "<< gcd(N, mod) << endl;
                if (gcd(N, mod) == N)
                {
                    cout << i + 1 << "\n";
                    return 0;
                }
            }

            mod = mod * 10 + 1;
        }
    }

    return 0;
}