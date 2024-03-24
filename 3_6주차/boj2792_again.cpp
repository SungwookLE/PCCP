#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A;
int mn = 1000000001;

bool check(int mid){

    int ret = 0;

    for(int i = 0 ; i < M ;++i){
        ret += A[i]/mid;
        if (A[i]%mid) ret++;
    }

    return N >= ret;

}

int main(){
    cin >> N >> M;
    A = vector<int>(M,0);

    int left = 1;
    int right = 1;
    for(int i =0 ; i < M ; ++i){
        cin >> A[i];
        if(right < A[i]) right = A[i];
    } 

    int mid;
    while(left<=right){

        mid = (left+right)/2;
        if (check(mid)){
            right = mid-1;
            if (mn > mid) mn = mid;
        }
        else left = mid+1;

    }

    cout << mn ;

    return 0;
}