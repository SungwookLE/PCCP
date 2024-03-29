#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll N, M;
vector<ll> A;
ll temp;

bool check(ll mid){

    temp = M;
    for(int i =0 ; i < M ; ++i){
        temp += mid/A[i];
    }

    return temp >= N;
}


int main(){
    cin >> N >> M;
    A = vector<ll>(M,0);
    for(int i = 0 ; i < M ; ++i) cin >> A[i];

    if ( N <= M) cout << N << endl;
    else{

        ll left = 1;
        ll right = 1E15;
        ll ret = 0;
        while(left <= right){
            ll mid = (left+right)/2;

            if(check(mid)){
                right = mid-1;
                ret = mid;
            }
            else{
                left = mid+1;
            }
        } 

        temp = M;
        for(int i = 0; i < M; i++) temp += ((ret - 1) / A[i]); 

        for(int i =0 ; i < M ; ++i){
            if (ret%A[i] == 0) temp++;
            if (temp == N){
                cout << i + 1 << "\n";
                return 0;
            }
        }
    }
 
    return 0;
}