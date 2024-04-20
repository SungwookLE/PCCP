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

int DP[100001][5][5];

int go(int left, int right, int idx, int sum){

    if (idx == A.size()){
        return sum; // 아 이렇게 되면 중간 DP에 담기는 값들이 중간 연산결과가 아닌 최종 답만 담기게 되는구나!!
    }   

    int& ret = DP[idx][left][right];
    if (ret!=INF) return ret;

    if (A[idx] == left || A[idx] == right) ret = min(ret, go(left, right, idx+1, sum+1));
    else{
        if (left == center) ret = min(ret, go(A[idx], right, idx+1, sum +2));
        else if (left == up && (A[idx] == left_ || A[idx] == right_)) ret = min(ret, go(A[idx], right, idx+1, sum+3));
        else if (left == down && (A[idx] == left_ || A[idx] == right_)) ret = min(ret, go(A[idx], right, idx+1, sum+3));
        else if (left == left_ && (A[idx] == up || A[idx] == down)) ret = min(ret, go(A[idx], right, idx+1, sum+3));
        else if (left == right_ && (A[idx] == up || A[idx] == down)) ret = min(ret, go(A[idx], right, idx+1, sum+3));
        else if (left == up && A[idx] == down) ret = min(ret, go(A[idx], right, idx+1, sum+4));
        else if (left == down && A[idx] == up) ret = min(ret, go(A[idx], right, idx+1, sum+4));
        else if (left == left_ && A[idx] == right_) ret = min(ret, go(A[idx], right, idx+1, sum+4));
        else if (left == right_ && A[idx] == left_) ret = min(ret, go(A[idx], right, idx+1, sum+4));

        if (right == center) ret = min(ret, go(left, A[idx], idx+1, sum+2));
        else if (right == up && (A[idx] == left_ || A[idx] == right_)) ret = min(ret, go(left, A[idx], idx+1, sum+3));
        else if (right == down && (A[idx] == left_ || A[idx] == right_)) ret = min(ret, go(left, A[idx], idx+1, sum+3));
        else if (right == left_ && (A[idx] == up || A[idx] == down)) ret = min(ret, go(left, A[idx], idx+1, sum+3));
        else if (right == right_ && (A[idx] == up || A[idx] == down)) ret = min(ret, go(left, A[idx], idx+1, sum+3));
        else if (right == up && A[idx] == down) ret = min(ret, go(left, A[idx], idx+1, sum+4));
        else if (right == down && A[idx] == up) ret = min(ret, go(left, A[idx], idx+1, sum+4));
        else if (right == left_ && A[idx] == right_) ret = min(ret, go(left, A[idx], idx+1, sum+4));
        else if (right == right_ && A[idx] == left_) ret = min(ret, go(left, A[idx], idx+1, sum+4));
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
    fill(&DP[0][0][0], &DP[0][0][0]+sizeof(DP)/sizeof(int), INF);
    cout << go(0,0,0, 0);


    return 0;
}