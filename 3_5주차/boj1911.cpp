#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<int> R;
vector<vector<int>> POOL;

int ans = 0;
int main(){

    cin >> N >> L;

    for(int i = 0; i < N ; ++i){
        int a, b;
        cin >> a >> b;
        POOL.push_back({a,b});
    }
    sort(POOL.begin(), POOL.end());

    // cout << "=================\n";
    int s= 0, e= 0;
    for(auto P: POOL){
        // cout << s << ", " << e << endl;

        if ((e-s)%L){

            if (P[0] > e + L - (e-s)%L){
                ans += (e-s)/L;
                ans +=1;

                s = P[0];
                e = P[1];

            }
            else e = P[1];

        }
        else{
            if (P[0] > e){
                ans += (e-s)/L;
                s= P[0];
                e= P[1];
            }
            else{
                e = P[1];
            }
        }
    }

    // cout << s << ", " << e << endl;

    ans += (e-s)/L;
    if ((e-s)%L) ans +=1;
    cout << ans;

    return 0;
}