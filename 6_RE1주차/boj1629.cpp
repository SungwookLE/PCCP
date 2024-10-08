#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A, B, C;

ll go(ll a, ll b)
{
    if (b == 1)
        return a % C;

    if (b % 2 == 1)
        return a * go(a, b-1) % C;
    else
        return go(a, b / 2) % C * go(a, b/2) %C;
        // = return go( a%C*a%C, b/2) %C;
}

ll ANS;
int main(){
    cin >> A >> B >> C;

    ANS = go(A, B);
    cout << ANS;

    return 0;
}