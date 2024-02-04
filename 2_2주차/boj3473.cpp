#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll T, N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> N ;


        ll ret2 = 0, ret5 = 0; // 2의배수를 담을 것, 5의 배수를 담을 것
        for(ll j = 2 ; j <= N; j*=2){
            ret2 += N/j;
        }
        for(ll j = 5; j <= N ; j*=5){
            ret5 += N/j;
        }

        cout << min(ret2, ret5) << "\n";

    }

    return 0;
}