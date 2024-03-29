#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll X, Y;
ll ret = -1;

int main(){
    // 게임을 최소 몇 판 더야하는지 출력하라. 만약 Z가 절대 변하지 않는다면 -1을 출력한다.
    cin >> X >> Y;

    ll ratio = (Y*100)/X;
    ll left = 0;
    ll right = 1E15;
    
    while(left<=right){
        ll mid = (left+right)/2;

        // cout << ratio << " " << mid << " "<<  (ll)((Y+mid)*100)/(X+mid) << endl;

        if ( (ll)((Y+mid)*100)/(X+mid) > ratio ){
            right= mid-1;
            ret = mid;
        }
        else left = mid+1;

    }

    cout << ret;



    return 0;
}