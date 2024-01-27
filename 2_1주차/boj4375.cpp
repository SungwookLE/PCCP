#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{

    ll N;
    while (cin >> N)
    {
        ll mod = 1;
        ll i = 0;
        while (1)
        {   
            i++;
            if (mod%N == 0){
                cout << i << "\n";
                break;
            }
            mod = (mod * 10 + 1)%N; // 모듈러 연산의 특성을 이용해서 중간계산을 계속 해주어도 된다.
        }
    }
    return 0;
}