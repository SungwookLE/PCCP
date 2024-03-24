#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[300001];

bool check(int mid){

    int ret =0;
    for(int i =0 ; i < M; ++i){
        ret += (A[i]/mid);
        if (A[i]%mid) ret++;
    }

    return N >= ret;

}

int main(){
    cin >> N >> M;

    int high = 0;
    for(int i =0 ; i < M; ++i){
        cin >> A[i];
        high = max(high, A[i]);
    }

    int left = 1;
    int right = high;

    int mn = high;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(check(mid)){
            if (mn > mid) mn = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    cout << mn;

    return 0;
}