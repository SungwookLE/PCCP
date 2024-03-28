#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, H_atk;
vector<tuple<ll, ll, ll>> I;

bool simulation(ll H_Max){
    ll t, a, h;
    ll H_Cur = H_Max;
    ll H_atk_ = H_atk;

    for(int i =0 ; i < N ; ++i){

        t = get<0>(I[i]);
        a = get<1>(I[i]);
        h = get<2>(I[i]);

        if (t == 1){
            // 몬스터

            ll cnt_monster = h/H_atk_;
            if (h%H_atk_) cnt_monster++;

            ll cnt_hero = H_Cur/a;
            if (H_Cur%a) cnt_hero++;

            if ( cnt_monster > cnt_hero ) return false;
            else H_Cur -= a*(cnt_monster-1);

        }
        else if (t == 2){
            // 포션
            H_atk_ += a;
            H_Cur += h;
            if (H_Cur > H_Max) H_Cur = H_Max;
        }

    }
    return true;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> H_atk;
    
    ll t, a, h;
    for(int i = 0; i < N ; ++i){
        cin >> t >> a >> h;
        I.push_back({t,a,h});
    }

    ll left = 0;
    ll right = 9223372036854775807;
    // ll = 1e18 + 4;
    ll mid = 0;

    ll ret =0;
    while(left<=right){
        mid = (left+right)/2;

        if (simulation(mid)){
            right = mid-1;
            ret = mid;
        }
        else{
            left = mid+1;
        }
    }
    cout << ret;

    return 0;
}