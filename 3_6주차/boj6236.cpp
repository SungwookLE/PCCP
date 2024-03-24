#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> Money;
int mn = 1000000001;

bool check(int mid){

    int cnt = 0;
    int ret = 0;
    for(int i =0 ; i < N ; ++i){

        if (Money[i]>mid) return 0;

        if (ret-Money[i]>=0){
            ret -= Money[i];
        }
        else{
            ret = 0;
            while(ret < Money[i]){
                ret += mid;
                cnt++;
            }
            ret -= Money[i];
        }
    }
   
    return cnt <= M;
}

int main(){
    cin >> N >> M;
    Money = vector<int>(N,0);

    int left = 1, right=0;
    for(int i =0 ; i < N ; ++i){
        cin >> Money[i];
        right += Money[i];
    }

    while(left<=right){
        int mid = (left+right)/2;
        if (check(mid)){

            right = mid-1;
            if (mn > mid) mn = mid;
        }
        else{
            left = mid+1;

        }
    }

    cout << mn;



    return 0;
}