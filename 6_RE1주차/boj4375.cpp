#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
int main()
{

    while (cin >> N){
        ll mod = 1;
        ll i = 0;
        while(1){
            i++;
            if (mod%N == 0){
                cout << i << "\n";
                break;
            }
            mod = (mod*10+1)%N; // (10/8: 아 어차피 나누어 떨어지기만 하면 되는거니까, 미리 나머지 계산을 중간에 해주면 되는군)
        }
        
    }

    return 0;
}