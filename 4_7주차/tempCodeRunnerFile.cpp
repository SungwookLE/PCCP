#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

typedef enum{
    center = 0,
    up = 1,
    down = 3,
    left_ = 2,
    right_ = 4
} dir_e;

vector<dir_e> A;

int DP[100001][100001];


int go(int left, int right, int idx, int power){

    if (idx == A.size()){
        return power;
    }   
    
    int& ret = DP[idx][power];
    if(ret != INF) return ret;

    if (A[idx] == left || A[idx] == right) ret = min(ret, go(left, right, idx+1, power+1));
    else{
        if (left == center) ret = min(ret, go(A[idx], right, idx+1, power+2));
        else if (left == up && (A[idx] == left_ || A[idx] == right_)) ret = min(ret, go(A[idx], right, idx+1, power+3));
        else if (left == down && (A[idx] == left_ || A[idx] == right_)) ret = min(ret, go(A[idx], right, idx+1, power+3));
        else if (left == left_ && (A[idx] == up || A[idx] == down)) ret = min(ret, go(A[idx], right, idx+1, power+3));
        else if (left == right_ && (A[idx] == up || A[idx] == down)) ret = min(ret, go(A[idx], right, idx+1, power+3));
        else if (left == up && A[idx] == down) ret = min(ret, go(A[idx], right, idx+1, power+4));
        else if (left == down && A[idx] == up) ret = min(ret, go(A[idx], right, idx+1, power+4));
        else if (left == left_ && A[idx] == right_) ret = min(ret, go(A[idx], right, idx+1, power+4));
        else if (left == right_ && A[idx] == left_) ret = min(ret, go(A[idx], right, idx+1, power+4));

        if (right == center) ret = min(ret, go(left, A[idx], idx+1, power+2));
        else if (right == up && (A[idx] == left_ || A[idx] == right_)) ret = min(ret, go(left, A[idx], idx+1, power+3));
        else if (right == down && (A[idx] == left_ || A[idx] == right_)) ret = min(ret, go(left, A[idx], idx+1, power+3));
        else if (right == left_ && (A[idx] == up || A[idx] == down)) ret = min(ret, go(left, A[idx], idx+1, power+3));
        else if (right == right_ && (A[idx] == up || A[idx] == down)) ret = min(ret, go(left, A[idx], idx+1, power+3));
        else if (right == up && A[idx] == down) ret = min(ret, go(left, A[idx], idx+1, power+4));
        else if (right == down && A[idx] == up) ret = min(ret, go(left, A[idx], idx+1, power+4));
        else if (right == left_ && A[idx] == right_) ret = min(ret, go(left, A[idx], idx+1, power+4));
        else if (right == right_ && A[idx] == left_) ret = min(ret, go(left, A[idx], idx+1, power+4));
    }

    return ret;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    while(true){
        cin >> n;
        if (n==0) break;
        A.push_back((dir_e)n);
    }
    fill(&DP[0][0], &DP[0][0]+sizeof(DP)/sizeof(int), INF);
    cout << go(0,0,0,0);


    return 0;
}