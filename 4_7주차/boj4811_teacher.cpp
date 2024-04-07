#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, dp[31][31];

ll go(int whole, int half){
    if(whole == 0 && half ==0) return 1;

    ll& ret = dp[whole][half];
    if (ret) return ret;

    if (whole>0) ret += go(whole-1, half+1);
    if (half>0) ret += go(whole, half-1);
    return ret;
}

int main(){
    while(true){
        cin >> n; if(n==0) break;
        cout << go(n,0) << "\n";
    }
}